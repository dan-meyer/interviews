#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// from https://leetcode.com/problems/reverse-integer

//Given a signed 32 - bit integer x, return x with its digits reversed.If reversing x
// causes the value to go outside the signed 32 - bit integer range[-231, 231 - 1], then return 0.

//Assume the environment does not allow you to store 64 - bit integers(signed or unsigned).

int reverseInt(int x) {
	int reverse = 0;

	while (x != 0) {
		if ((reverse > INT32_MAX / 10) || (reverse < INT32_MIN / 10))
			return 0;

		reverse = (reverse * 10 + x % 10);
		x /= 10;
	}

	return reverse;
}

void main() {
	uint32_t revIntRet;


	uint32_t myInt1 = 123;

	revIntRet = reverseInt(myInt1);
	printf("T1 = Int %d reversed to %d\n", myInt1, revIntRet);


	uint32_t myInt2 = -123;

	revIntRet = reverseInt(myInt2);
	printf("T2 = Int %d reversed to %d\n", myInt2, revIntRet);


	uint32_t myInt3 = 120;

	revIntRet = reverseInt(myInt3);
	printf("T3 = Int %d reversed to %d\n", myInt3, revIntRet);


	// INT32_MAX is 2147483647
	uint32_t myInt4 = 7463847412;

	revIntRet = reverseInt(myInt4);
	printf("T3 = Int %d reversed to %d\n", myInt4, revIntRet);
}