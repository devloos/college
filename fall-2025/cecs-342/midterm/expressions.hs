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

t01 = 0 -- Num a -> a

t02 = (+) -- Num a => a -> a -> a

t03 = (==) -- Eq a => a -> a -> Bool

t04 = (<=) -- Ord a => a -> a -> Bool

t05 = 'a' -- Char

t06 = "text" -- String

t07 = [1, 2, 3] -- Num a => [a]

t08 = [] -- [a]

t09 = (:) -- a -> [a] -> [a]

t10 = [[], [0]] -- Num a => [[a]]

t11 = ('a', 2) -- Num b => (Char, b)

t12 = ('a', "bc") -- (Char, [Char])

t13 = fst -- (a, b) -> a

t14 = flip -- (f -> a -> b) -> f -> b -> a

t15 = flip (:) -- (f -> a -> [a]) -> f -> [a] -> a

t16 = head -- [a] -> a

t17 = tail -- [a] -> [a]

t18 = (++) -- [a] -> [a] -> [a]

t19 = map -- (a -> b) -> [a] -> [b]

t20 = foldr -- (a -> b -> b) -> b -> [a] -> b

t21 = foldl -- (a -> b -> b) -> b -> [a] -> b

t22 = foldr (+) 0 -- Num a => (a -> a -> a) -> a -> [a] -> a

t23 = foldr (++) [] -- 

t24 = sum

t25 = product

t26 = filter

t27 = max

t28 = maximum

t29 = sort

t30 = ($)

t31 = \f x -> x

t32 = \f x -> f x

t33 = \f x -> f (f x)

t34 = (.)

t35 = curry

t36 = uncurry

t37 = foldl (flip (:)) []

t38 = flip (foldr (:))

t39 = [2 * x | x <- [1 .. 10]]

t40 = map (2 *) [1 .. 10]