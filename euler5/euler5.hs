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
-- Started: 2/9/2013
-- Completed: 
-- Author: epicoxymoron
-- Language: Haskell

-- Checks whether a number is evenly divisible by each number in a list
divByAll :: [Int] -> Int -> Bool
divByAll [] _ = True
divByAll xs n = all (\x -> (mod n x) == 0) xs

-- Finds the smallest number divisible by [1..n]
-- we can cheat here by only checking multiples of the largest number
euler5' n = take 1 $ filter (divByAll [1..n]) [n,2*n..] 

-- the magic
euler5 = euler5' 20
