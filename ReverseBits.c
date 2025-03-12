#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// from https://leetcode.com/problems/reverse-bits

uint32_t reverseBits(uint32_t n) {
	uint32_t reversed = 0;

	for (int i = 0; i < (sizeof(n) * 8); i++) {
		reversed |= (n >> i & 1) << (31 - i);
	}

	return reversed;
}

uint32_t printBinary(uint32_t n) {
	for (int i = 0; i < 32; i++) {
		printf("%d", (n>>i)&1);
	}
	printf("\n");
}

void main() {
	uint32_t revBitsRet;


	uint32_t bits1 = 0b00000010100101000001111010011100;

	revBitsRet = reverseBits(bits1);
	printf("T1 = bits1 0x%08x reversed to 0x%08x\n", bits1, revBitsRet);
	printBinary(bits1);
	printBinary(revBitsRet);


	uint32_t bits2 = 0b11111111111111111111111111111101;

	revBitsRet = reverseBits(bits2);
	printf("T2 = bits2 0x%08x reversed to 0x%08x\n", bits2, revBitsRet);
	printBinary(bits2);
	printBinary(revBitsRet);
}