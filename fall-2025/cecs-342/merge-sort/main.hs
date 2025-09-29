-- Main.hs
--
-- CECS 342 Assignment 4
-- Merge sort in Haskell

module Main where

import Data.List (sort)

merge [] ys = ys
merge xs [] = xs
-- this merge is much more easier to understand this c, surprisingly
merge (x : xs) (y : ys)
  | x <= y = x : merge xs (y : ys) -- if x is less then take x and concat with merge of the rest of xs with ys
  | otherwise = y : merge (x : xs) ys -- otherwise do opposite

-- Merge sort a list.
msort :: (Ord a) => [a] -> [a]
msort [] = []
msort [a] = [a]
msort xs = do
  -- went this route because its simple
  -- I asked gpt if there was a better way of doing this and it pointed to using split form module
  let n = length xs `div` 2
  let (left, right) = splitAt n xs

  let sortedLeft = msort left
  let sortedRight = msort right

  merge sortedLeft sortedRight

-- Call a sort function and print input and output.
testSort sort input = do
  putStr "Input:  "
  print input
  putStr "Sorted: "
  print (sort input)

-- Call some tests.
main = do
  putStrLn "CECS 342 Assignment 4"
  putStrLn "Name: Carlos Aguilera"
  putStrLn "Algorithm: merge sort, Language: Haskell"

  testSort msort ([] :: [Int])
  testSort msort [1]
  testSort msort [3, 2, 1]
  testSort msort [102, -43, 5, 645, 4, 34, -6, 776, 445, 45]
  testSort
    msort
    [ "the",
      "quick",
      "brown",
      "fox",
      "jumps",
      "over",
      "the",
      "lazy",
      "dog"
    ]