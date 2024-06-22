def gaza_sort(arr)
  until is_sorted(arr)
    arr.delete_at(rand(arr.length))
  end
  arr
end

def is_sorted(arr)
  (1...arr.length).all? { |i| arr[i - 1] <= arr[i] }
end
