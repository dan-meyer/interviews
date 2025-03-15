#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// from https://leetcode.com/problems/find-pivot-index

//Given an array of integers nums, calculate the pivot index of this array.

//The pivot index is the index where the sum of all the numbers strictly to
// the left of the index is equal to the sum of all the numbers strictly to the index's right.

//If the index is on the left edge of the array, then the left sum is 0 because
// there are no elements to the left.This also applies to the right edge of the array.

//Return the leftmost pivot index.If no such index exists, return -1.

//1 <= nums.length <= 10^4
//- 1000 <= nums[i] <= 1000

#define pivotIndex pivotIndex2

int pivotIndex1(int* nums, int numsSize) {

	int* sumLeft = malloc(numsSize * sizeof(int));
	int* sumRight = malloc(numsSize * sizeof(int));
	int sumL = 0;
	int sumR = 0;
	memset(sumLeft, 0, numsSize * sizeof(int));
	memset(sumRight, 0, numsSize * sizeof(int));
	int retIndex = -1;

	// sum from left and right. Store ordered in sumLeft and sumRight arrays for later comparison.
	for (int i = 0; i < numsSize; i++) {
		sumL += nums[i];
		sumR += nums[numsSize-1-i];
		sumLeft[i] = sumL;
		sumRight[numsSize -1 - i] = sumR;
	}

	// walk sumLeft and sumRight arrays to find pivot
	for (int i = 0; i < numsSize; i++) {
		if (sumLeft[i] == sumRight[i]) {
			retIndex = i;
			break;
		}
	}

	free(sumLeft);
	free(sumRight);

	return retIndex;
}

// calculate entire sum of array and then pivot is when the current value is some of array - double leftmost sum
int pivotIndex2(int* nums, int numsSize) {
	int t = 0;
	for (int i = 0; i < numsSize; i++) t += nums[i];
	int temp = 0;
	for (int i = 0; i < numsSize; temp += nums[i++])
		if (nums[i] == t - 2 * temp)
			return i;
	return -1;
}

void main() {

	int nums1[] = { 1,7,3,6,5,6 };

	printf("pivotIndex=%d\n", pivotIndex(nums1, sizeof(nums1)/sizeof(int)));

	int nums2[] = { 1,2,3 };

	printf("pivotIndex=%d\n", pivotIndex(nums2, sizeof(nums2) / sizeof(int)));

	int nums3[] = { 2,1,-1 };

	printf("pivotIndex=%d\n", pivotIndex(nums3, sizeof(nums3) / sizeof(int)));

}