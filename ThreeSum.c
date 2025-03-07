#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// from https://leetcode.com/problems/3sum/

// Given an integer array nums, return all the triplets[nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// compare function for qsort()
int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int** retVal;

	*returnSize = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int) * 3);
	retVal = malloc(sizeof(int*) * 3);

	// sort the numbers to be able to skip duplicates
	qsort(nums, numsSize, sizeof(int), compare);

	// loop through each combination left to right and skip duplicates
	for (int i = 0; i < numsSize-2; i++) {
		if ((i>0) && (nums[i] == nums[i - 1])) { continue; }
		for (int j = i+1; j < numsSize-1; j++) {
			if ((j>i+1) && (nums[j] == nums[j - 1])) { continue; }
			for (int k = j+1; k < numsSize; k++) {
				if ((k > j + 1) && (nums[k] == nums[k - 1])) { continue; }
				if ((nums[i] + nums[j] + nums[k]) == 0) {
					//printf("%d, %d, %d\n", nums[i], nums[j], nums[k]);
					retVal[*returnSize] = malloc(sizeof(int) * 3);
					(*returnColumnSizes)[(*returnSize)] = 3;
					retVal[*returnSize][0] = nums[i]; retVal[*returnSize][1] = nums[j]; retVal[(*returnSize)++][2] = nums[k];
				}
			}
		}
	}
	return retVal;
}

void main() {
	int **threeSumRet;
	int* returnColumnSizes;

	int numsSize, returnSize=0;

	int nums1[] = { -1,0,1,2,-1,-4 }; // TC 1

	printf("TC1 [ -1,0,1,2,-1,-4 ]\n");
	threeSumRet = threeSum(nums1, sizeof(nums1)/sizeof(int), &returnSize, &returnColumnSizes);

	printf("TC1 returnSize=%d\n", returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d, %d, %d\n", threeSumRet[i][0], threeSumRet[i][1], threeSumRet[i][2]);
	}
	assert(returnSize == 2);

	int nums2[] = { 0, 1, 1 }; // TC 2

	printf("TC1 [ 0, 1, 1 ]\n");
	threeSumRet = threeSum(nums2, sizeof(nums2) / sizeof(int), &returnSize, &returnColumnSizes);

	printf("TC2 returnSize=%d\n", returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d, %d, %d\n", threeSumRet[i][0], threeSumRet[i][1], threeSumRet[i][2]);
	}
	assert(returnSize == 0);

	int nums3[] = { 0, 1, 1 }; // TC 3

	printf("TC1 [ 0, 1, 1 ]\n");
	threeSumRet = threeSum(nums3, sizeof(nums3) / sizeof(int), &returnSize, &returnColumnSizes);

	printf("TC3 returnSize=%d\n", returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d, %d, %d\n", threeSumRet[i][0], threeSumRet[i][1], threeSumRet[i][2]);
	}
	assert(returnSize == 0);

	int nums4[] = { -1, 0, 1, 2, -1, -4, -1, 0, 0, 4, 4 }; // TC 4

	printf("TC1 [  -1, 0, 1, 2, -1, -4, -1, 0, 0, 4, 4 ]\n");
	threeSumRet = threeSum(nums4, sizeof(nums4) / sizeof(int), &returnSize, &returnColumnSizes);

	printf("TC4 returnSize=%d\n", returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d, %d, %d\n", threeSumRet[i][0], threeSumRet[i][1], threeSumRet[i][2]);
	}
	assert(returnSize == 4);
}