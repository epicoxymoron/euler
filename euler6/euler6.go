/*
 * Title: Sum square difference
 *
 * Problem #: 6
 *
 * Description: The sum of the squares of the first ten natural numbers is,
 *     1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 *     (1 + 2 + ... + 10)^2 = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten 
 * natural numbers and the square of the sum is 3025  385 = 2640.
 * 
 * Find the difference between the sum of the squares of the first one 
 * hundred natural numbers and the square of the sum.
 *
 * Author: epicoxymoron
 * Language: Go
 */

package main

import "fmt"

// Optimized short-form calculation of the sum from 1 to n
func sumFromOneTo(n int) int {
	return (n * (n+1)) / 2
}

// Calculates the sum of i^2 from i = 1 to n
func sumSquare(n int) int {
	s := 0
	for i := 1; i <= n; i++ {
		s += (i * i)
	}
	return s
}

// Calculates the square of (sum of i from i = 1 to n)
func squareSum(n int) int {
	x := sumFromOneTo(n)
	return x * x
}

func main() {
	num := 100
	diff := squareSum(num) - sumSquare(num)

	fmt.Println(diff)
}
