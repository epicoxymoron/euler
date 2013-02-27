Title: Digit Fifth Powers
Problem #: 30

Description: Surprisingly there are only three numbers that can be written 
as the sum of fourth powers of their digits:
    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.
The sum of these numbers is 1634 + 8208 + 9474 = 19316.
Find the sum of all the numbers that can be written as the sum of fifth 
powers of their digits.

Author: epicoxymoron
Language: Haskell (literate)

---------

This function actually calculates the value of the number.

> sumPowerDigits pow num
> 	| num < 10		= num^pow
> 	| otherwise		= (mod num 10)^pow + sumPowerDigits pow (floor (fromIntegral num / 10))

Checks whether the calculated value of the number is equal to the number 
itself.

> matchingSum pow num = (sumPowerDigits pow num) == num

Finds the upper bound of a number that could satisfy the requirement.  We 
won't bother to search for numbers above this value.

So how do we do that?  Well, past a certain number, it's impossible for the 
sum of the digits to equal the number itself.  3(9^2) = 243, but 4(9^2) is 
324; with a power of 2, the largest number we can make out of 4 digits is
itself only a 3-digit number.  Therefore, we don't need to look at 4-digit 
numbers so 243 is our upper bound for a power of 2.

In detail:

findUpperBound 2 =? 2 * 9^2 < 10
findUpperBound 2 =? 162 < 10
Result: not yet

findUpperBound 2 =? 3 * 9^2 < 100
findUpperBound 2 =? 243 < 100
Result: not yet

findUpperBound 2 =? 4 * 9^2 < 10^4
findUpperBound 2 =? 324 < 1000
Result: found it!

> findUpperBound pow = findUpperBound' pow 2 where
>	findUpperBound' pow digits 
> 		| 10^digits > (digits * 9^pow)	= (digits * 9^pow)
>		| otherwise						= findUpperBound' pow (digits+1)

Does the same for lower bounds.  We know that 1-digit numbers are out because 
they're not sums, but we'll just leave it at that for now.

> findLowerBound _ = 10

Enumerates the matching sums

> findMatchingSums pow = filter (matchingSum pow) [(findLowerBound pow) .. (findUpperBound pow)]

Puts it all together for a given power by summing the matching sums.

> euler30' pow = sum $ findMatchingSums pow 

And, since the problem is to calculate the values for the 5th power, this
actually runs the problem

> euler30 = euler30' 5

Tests the example case:

> testExampleList = (findMatchingSums 4) == [1634, 8208, 9474]
> testExampleSum = (sum $ findMatchingSums 4) == 19316
