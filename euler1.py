# Title: Multiples of 3 and 5
#
# Problem #: 1
#
# Description: If we list all the natural numbers below 10 that are 
# multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 
# 23.
# Find the sum of all the multiples of 3 or 5 below 1000.
#
# Started: 1/14/2013
# Completed: 1/14/2013
# Author: epicoxymoron
# Language: Python

def multiples_of_below(multiples, below):
    def f(num):
        for m in multiples:
            if (num % m) == 0:
                return True
        return False
    return [x for x in range(below) if f(x)]

def straight_up():
    return sum([x for x in range(1000) if x % 3 == 0 or x % 5 == 0])


if __name__ == '__main__':
    print(sum(multiples_of_below([3, 5], 10)))
    print(sum(multiples_of_below([3, 5], 1000)))
    print(straight_up())
