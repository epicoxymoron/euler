/*
 * Title: Longest Collatz sequence
 *
 * Problem #: 14
 * 
 * Description: The following iterative sequence is defined for the set 
 * of positive integers:
 *     n -> n/2 (n is even)
 *     n -> 3n + 1 (n is odd)
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13  40  20  10  5  16  8  4  2  1
 * It can be seen that this sequence (starting at 13 and finishing at 1) 
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), 
 * it is thought that all starting numbers finish at 1.
 * Which starting number, under one million, produces the longest chain?
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 *
 * Author: epicoxymoron
 * Language: Go
 */

package main

import "fmt"

func nextCollatzNumber(n uint64) uint64 {
	if n == 1 {
		return 1
	} else if n % 2 == 0 {
		return n / 2
	} else {
		return 3 * n + 1
	}
	// http://code.google.com/p/go/issues/detail?id=65
	panic("unreachable") 
}

func collatzChainLength(n uint64) uint64 {
	var i uint64 = 1
	for ;; i++ {
		n = nextCollatzNumber(n)
		if n == 1 {
			return i
		}
	}
	return 0
}

func findMaxLen(upTo uint64) (maxVal uint64, maxChainLen uint64) {
	var i uint64 = 1
	for i = 2; i < upTo; i++ {
		var collatz uint64 = collatzChainLength(i)
		if collatz > maxChainLen {
			maxVal = i
			maxChainLen = collatz
		}
	}
	return
}

func main() {
	var num, _ uint64 = findMaxLen(1000000)
	fmt.Println(num)
}
