-- Main.hs
--
-- CECS 342 Assignment 1
-- Quick sort in Haskell

-- TOOLS USED:
-- vscode, gcc, ghosty terminal, chat gpt for explaining algorithm

module Main where

-- Quick sort a list.
-- qsort :: Ord a => [a] -> [a]
-- qsort xs
--   | null xs        = []          -- size < 1
--   | length xs == 1 = xs          -- size == 1
--   | otherwise =
--       let i = 0
--           j = length xs - 1
--       in helper xs i j
--   where
--     -- Local helper: put the *type signature* and *definition* here.
--     pivot :: Int
--     pivot = xs[length xs / 2]

--     helper :: Ord a => [a] -> Int -> Int -> null
--     helper arr i j
--       | i > j        = null          -- size < 1
--       | otherwise =
--         if arr[i] < pivot
--           helper arr i + 1 j
        
--         if arr[j] > pivot
--           helper arr i j - 1
        
--         if j > 0
--           qsort xs j + 1
        
--         if i < length xs
--           qsort (xs + i) (length xs - i)

-- I did get some help from gpt to try and make my idea above come to life
-- But overall logic was me, I also comented each haskell line to ensure I understand it
qsort :: Ord a => [a] -> [a]
qsort xs
  | n <= 1    = xs
  | otherwise =
      let mid   = n `div` 2 -- n / 2
          pivot = xs !! mid -- super weird but essentially is xs[mid]
          rest  = take mid xs ++ drop (mid+1) xs -- remove mid and concat left and right
          left  = filter (<= pivot) rest -- filter any element thats <= pivot
          right = filter (> pivot) rest -- filter any element that is > pivot
      in qsort left ++ [pivot] ++ qsort right -- concat back together with the now sorted array and include pivot
  where
    n = length xs


-- Call a sort function and print input and output.
testSort sort input = do
  putStr "Input:  "
  print input
  putStr "Sorted: "
  print (sort input)

-- Call some tests.
main = do
  putStrLn "CECS 342 Assignment 1"
  putStrLn "Name: Carlos Aguilera"
  putStrLn "Algorithm: quick sort, Language: Haskell\n"
  
  testSort qsort ([]::[Int])
  testSort qsort [1]
  testSort qsort [3, 2, 1]
  testSort qsort [102, -43, 5, 645, 4, 34, -6, 776, 445, 45]
  testSort qsort ["the",  "quick",  "brown", "fox",
                  "jumps", "over", "the", "lazy", "dog"]
