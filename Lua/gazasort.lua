function gazaSort(arr)
    while not isSorted(arr) do
        table.remove(arr, math.random(#arr))
    end
    return arr
end

function isSorted(arr)
    for i = 1, #arr - 1 do
        if arr[i] > arr[i + 1] then return false end
    end
    return true
end
