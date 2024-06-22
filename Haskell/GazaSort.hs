import System.Random
import Control.Monad.State

gazaSort :: [Int] -> IO [Int]
gazaSort arr = if isSorted arr then return arr else do
    idx <- randomRIO (0, length arr - 1)
    gazaSort (take idx arr ++ drop (idx + 1) arr)

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted (x:y:xs) = x <= y && isSorted (y:xs)
