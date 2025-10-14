-- CECS 342 "40 Haskell Expressions"

-- Evaluate each of the following 40 Haskell expressions.
-- Then use ghci (in repl.it) to verify the results.

x01 = 1 + 2 -- 3

x02 = (+) 1 2 -- 3

x03 = (-) 1 2 -- -1

x04 = flip (-) 1 2 -- 1

x05 = 1 : [] -- [1]

x06 = head [1, 2] -- 1

x07 = tail [1, 2] -- [2]

x08 = 1 < 2 -- true

x09 = if 1 < 2 then "yes" else "no" -- yes

x10 = 'a' : "bc" -- abc

x11 = [1, 2] ++ [3, 4] -- [1, 2, 3, 4]

x12 = "ab" ++ "cd" -- abcd

x13 = foldr (+) 0 [1, 2, 3] -- 6

x14 = foldr (-) 0 [1, 2, 3] -- 2

x15 = foldl (+) 0 [1, 2, 3] -- 6

x16 = foldl (-) 0 [1, 2, 3] -- -6

x17 = foldr (-) 7 [1, 2, 3] -- -5

x18 = map (2 *) [1 .. 10] -- 2, 4, 6, 8, 10, 12, 14, 16, 18, 20

x19 = [2 * x | x <- [1 .. 10]] -- 2, 4, 6, 8, 10, 12, 14, 16, 18, 20

x20 = take 3 [6, 5, 4, 3, 2, 1] -- [6, 5, 4]

x21 = take 2 (map (2 *) [3, 4, 5]) -- [6, 8]

x22 = take 2 $ map (2 *) [3, 4, 5] -- [6, 8]

x23 = take 2 $ (2 *) <$> [3, 4, 5] -- [6, 8]

x24 = foldr (++) [] [[1], [], [5, 7]] -- [1, 5, 7]

x25 = foldr (++) "" ["a", "", "bc"] -- abc

x26 = max 1 2 -- 2

x27 = 1 `max` 2 -- 2

x28 = maximum [1, 5, 3] -- 5

x29 = flip (foldr (:)) "abc" "def" -- foldr (:) def abc abcdef

x30 = foldl (flip (:)) [] [2, 4, 6] -- (flip (:) [] 2) flip (:) 4) flip (:) 6

x31 = sum [length s | s <- ["a", "b", "cd"]] -- 4

x32 = fst (1, "abc") -- 1

x33 = snd ([1, 2, 3], 'a') -- 'a'

x34 = curry fst 1 2 -- 1

x35 = uncurry (+) (1, 2) -- 3

x36 = (\x -> 2 * x) 5 -- 10

x37 = (\y -> y * y) 5 -- 25

x38 = (\z -> 7) 5 -- 7

x39 = (\x -> (\y -> y + 1) x) 5 -- 6

x40 = (\f -> f (f 0)) (\x -> x + 1) -- 2