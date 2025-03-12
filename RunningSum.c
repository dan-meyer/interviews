#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// from https://leetcode.com/problems/running-sum-of-1d-array

//Given an array nums.We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

//Return the running sum of nums.

//1 <= nums.length <= 1000
//- 10 ^ 6 <= nums[i] <= 10 ^ 6

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
	int runningCount = 0;
	int* returnArr = malloc(numsSize * sizeof(int));

	for (int i = 0; i < numsSize; i++) {
		runningCount += nums[i];
		returnArr[i] = runningCount;
	}

	*returnSize = numsSize;

	return returnArr;
}


void main() {
	int retSize;
	int* runSumRet;

	uint32_t nums1[] = { 1,2,3,4 };

	runSumRet = runningSum(nums1, sizeof(nums1) / sizeof(int), &retSize);
	for (int i = 0; i < retSize; i++) {
		printf("%d ", runSumRet[i]);
	}
	printf("\n");
	free(runSumRet);
	
	uint32_t nums2[] = { 1,1,1,1,1 };
	runSumRet = runningSum(nums2, sizeof(nums2) / sizeof(int), &retSize);
	for (int i = 0; i < retSize; i++) {
		printf("%d ", runSumRet[i]);
	}
	printf("\n");
	free(runSumRet);


	uint32_t nums3[] = { 3,1,2,10,1 };
	runSumRet = runningSum(nums3, sizeof(nums3) / sizeof(int), &retSize);
	for (int i = 0; i < retSize; i++) {
		printf("%d ", runSumRet[i]);
	}
	printf("\n");
	free(runSumRet);

}