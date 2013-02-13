-- Title: Smallest multiple
--
-- Problem #: 5
--
-- Description: 2520 is the smallest number that can be divided by each of 
-- the numbers from 1 to 10 without any remainder.
--
-- What is the smallest positive number that is evenly divisible by all of 
-- the numbers from 1 to 20?
--
-- Author: epicoxymoron
-- Language: Haskell

-- Checks whether a number is evenly divisible by each number in a list
divByAll :: [Int] -> Int -> Bool
divByAll [] _ = True
divByAll xs n = all (\x -> (mod n x) == 0) xs

isFactor :: Int -> Int -> Bool
isFactor x y = and [(x > y), (mod x y == 0)]
--filterFactors xs n = filter (\y -> (y == n) or ((mod n y) > 0)) xs

-- Finds the smallest number divisible by [1..n]
-- 
-- We can cheat here by only checking multiples of the largest number
-- and not explicitly checking for it as its own factor.
--
-- For example, if we're looking for a number which is evenly divided by
-- [1..5], we can check only for multiples of 5 (5,10,15,20...), and only 
-- check that it's really a multiple of [1..4].  It's not going to change the
-- O(x) of the function, but it'll still do less work.
--
-- We can also look at removing factors from the list such that we're only 
-- looking for co-prime numbers.  For example, if we're looking for a number
-- divided by [1..6], we can simplify that to looking for factors from 
-- [4,5,6], since [1..3] all divide 6.  Again, doesn't change the O(x) of the 
-- function, but still does less actual work.  This optimization isn't 
-- implemented yet, but that's what the stub for isFactor is meant for.
-- 
euler5' n = head $ filter (divByAll [2 .. n-1]) [n, 2*n ..] 

-- the magic
euler5 = euler5' 20
