#ifndef GAZASORT_HPP
#define GAZASORT_HPP

#include <algorithm>
#include <random>
#include <iterator>
#include <type_traits>
#include <execution>

namespace gaza {

namespace detail {

template<typename T, typename V, typename = void>
struct is_comparison : std::false_type
{
};

template<typename T, typename V>
struct is_comparison<T, V,
	std::enable_if_t<
		std::is_convertible_v<
			decltype(
				std::declval<T>()(
					std::declval<V>(),
					std::declval<V>()
				)
			),
			bool
		>
	>
> : std::true_type
{
};

template<typename T, typename V>
inline constexpr bool is_comparison_v = is_comparison<T, V>::value;

template<typename T>
struct is_unsigned_integral : std::bool_constant<
	std::is_unsigned_v<T>
	&& std::is_integral_v<T>
>
{
};

template<typename T>
inline constexpr bool is_unsigned_integral_v = is_unsigned_integral<T>::value;

} // namespace detail

/// <summary>
/// GazaSort: The only method for sorting an array while embracing necessary data sacrifices.
/// </summary>
/// <typeparam name="It">Iterator type</typeparam>
/// <typeparam name="Rand">Random engine type</typeparam>
/// <typeparam name="Compare">Comparison type</typeparam>
/// <param name="first">Iterator pointing to the beginning of the range to sort.</param>
/// <param name="last">Iterator pointing to past-the-end of the range to sort.</param>
/// <param name="comp">Comparison functor.</param>
/// <param name="rand">Random engine to use to generate randomness.</param>
/// <returns></returns>
template<
	typename It,
	typename Compare = std::less<typename std::iterator_traits<It>::value_type>,
	typename Rand = std::default_random_engine
>
constexpr auto sort(
	It first, It last,
	Compare comp = std::less<typename std::iterator_traits<It>::value_type>{},
	Rand&& rand = std::default_random_engine{ std::random_device{}() }
) -> std::enable_if_t<
	detail::is_comparison_v<
		Compare,
		typename std::iterator_traits<It>::value_type
	>
	&& detail::is_unsigned_integral_v<decltype(std::declval<Rand>()())>,
	It
>;

template<
	typename ExecutionPolicy,
	typename It,
	typename Compare = std::less<typename std::iterator_traits<It>::value_type>,
	typename Rand = std::default_random_engine
>
auto sort(
	ExecutionPolicy&& policy,
	It first, It last,
	Compare comp = std::less<typename std::iterator_traits<It>::value_type>{},
	Rand&& rand = std::default_random_engine{ std::random_device{}() }
) -> std::enable_if_t<
	std::is_execution_policy_v<std::decay_t<ExecutionPolicy>>
	&& detail::is_comparison_v<
		Compare,
		typename std::iterator_traits<It>::value_type
	>
	&& detail::is_unsigned_integral_v<decltype(std::declval<Rand>()())>,
	It
>;

/// <summary>
/// GazaSort: The only method for sorting an array while embracing necessary data sacrifices.
/// </summary>
/// <typeparam name="It">Iterator type</typeparam>
/// <typeparam name="Rand">Random engine type</typeparam>
/// <param name="first">Iterator pointing to the beginning of the range to sort.</param>
/// <param name="last">Iterator pointing to past-the-end of the range to sort.</param>
/// <param name="rand">Random engine to use to generate randomness.</param>
/// <returns></returns>
template<typename It, typename Rand>
constexpr auto sort(It first, It last, Rand&& rand) -> std::enable_if_t<
	detail::is_unsigned_integral_v<decltype(std::declval<Rand>()())>,
	It
>;

template<typename ExecutionPolicy, typename It, typename Rand>
auto sort(
	ExecutionPolicy&& policy,
	It first, It last,
	Rand&& rand
) -> std::enable_if_t<
	std::is_execution_policy_v<std::decay_t<ExecutionPolicy>>
	&& detail::is_unsigned_integral_v<decltype(std::declval<Rand>()())>,
	It
>;



namespace detail {

template<typename It>
constexpr auto remove(It pos, It last) -> It
{
    return std::move(pos + 1, last, pos);
}

template<typename ExecutionPolicy, typename It>
auto remove(ExecutionPolicy&& policy, It pos, It last) -> It
{
	return std::move(policy, pos + 1, last, pos);
}

} // namespace detail

template<typename It, typename Compare, typename Rand>
constexpr auto sort(It first, It last, Compare comp, Rand&& rand) -> std::enable_if_t<
	detail::is_comparison_v<
		Compare,
		typename std::iterator_traits<It>::value_type
	>
	&& detail::is_unsigned_integral_v<decltype(std::declval<Rand>()())>,
	It
>
{
    using ItDiffT = typename std::iterator_traits<It>::difference_type;
    auto ans = last;

    while (!std::is_sorted(first, ans, comp))
    {
        auto size = std::distance(first, ans);
        auto dist = std::uniform_int_distribution<ItDiffT>{ 0, size - 1 };
        ans = detail::remove(first + dist(rand), ans);
    }

    return ans;
}

template<
	typename ExecutionPolicy,
	typename It,
	typename Compare,
	typename Rand
>
auto sort(
	ExecutionPolicy&& policy,
	It first, It last,
	Compare comp,
	Rand&& rand
) -> std::enable_if_t<
	std::is_execution_policy_v<std::decay_t<ExecutionPolicy>>
	&& detail::is_comparison_v<
		Compare,
		typename std::iterator_traits<It>::value_type
	>
	&& detail::is_unsigned_integral_v<decltype(std::declval<Rand>()())>,
	It
>
{
	using ItDiffT = typename std::iterator_traits<It>::difference_type;
	auto ans = last;

	while (!std::is_sorted(policy, first, ans, comp))
	{
		auto size = std::distance(first, ans);
		auto dist = std::uniform_int_distribution<ItDiffT>{ 0, size - 1 };
		ans = detail::remove(policy, first + dist(rand), ans);
	}

	return ans;
}

template<typename It, typename Rand>
constexpr auto sort(It first, It last, Rand&& rand) -> std::enable_if_t<
	detail::is_unsigned_integral_v<decltype(std::declval<Rand>()())>,
	It
>
{
    using ValueT = typename std::iterator_traits<It>::value_type;
    return sort(first, last, std::less<ValueT>{}, std::forward<Rand>(rand));
}

template<typename ExecutionPolicy, typename It, typename Rand>
auto sort(
	ExecutionPolicy&& policy,
	It first, It last,
	Rand&& rand
) -> std::enable_if_t<
	std::is_execution_policy_v<std::decay_t<ExecutionPolicy>>
	&& detail::is_unsigned_integral_v<decltype(std::declval<Rand>()())>,
	It
>
{
	using ValueT = typename std::iterator_traits<It>::value_type;
	return sort(policy, first, last, std::less<ValueT>{}, std::forward<Rand>(rand));
}

} // namespace gaza

#endif // GAZASORT_HPP
