#include <cstdio>
#include <format>
#include <vector>
#include <execution>
#include "gazasort.hpp"

int main()
{
	auto rand = std::default_random_engine{};
	constexpr auto v = [&]()
	{
		auto v = std::vector<int>{ 8, 9, 5, 6, 7, 4, 1 };
		v.erase(gaza::sort(v.begin(), v.end(), rand), v.end());
		return v;
	}();
	for (const auto& i : v)
	{
		std::printf("%s", std::format("{}, ", i).c_str());
	}

	return 0;
}
