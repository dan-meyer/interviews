#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// from https://leetcode.com/problems/two-sum

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.

//You can return the answer in any order.

#include "uthash.h" // credit https://github.com/troydhanson/uthash
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
struct hash_entry {
	int key;            /* we'll use this field as the key */
	int data;
	UT_hash_handle hh; /* makes this structure hashable */
};

int* twoSumHash(int* nums, int numsSize, int target, int* returnSize) {
	int* newList = NULL;
	(int*)malloc(sizeof(int) * 2);
	int remainder;
	struct hash_entry* table = NULL;
	struct hash_entry* element;

	for (int i = 0; i < numsSize; i++) {
		remainder = target - nums[i];
		HASH_FIND_INT(table, &remainder, element);

		// the remainder was found
		if (element) {
			newList = (int*)malloc(sizeof(int) * 2);
			newList[1] = i; newList[0] = element->key;
			break;
		}
		else {  // not found, so add this to the hash
			element = (struct hash_entry*)malloc(sizeof(*element));
			element->data = nums[i];
			element->key = i;
			HASH_ADD_INT(table, data, element);
		}
	}

	*returnSize = 2;
	return newList;
}

enum bool{ false, true };
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSumIter(int* nums, int numsSize, int target, int* returnSize) {
	int* newList = (int*)malloc(sizeof(int) * 2);
	enum bool breakFlag = false;

	for (int i = 0; i < numsSize; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (target == (nums[j] + nums[i])) {
				newList[0] = i; newList[1] = j;
				*returnSize = 2;
				return newList;
			}
		}
	}
	return NULL;
}

//#define twoSumFunc	twoSumIter
#define twoSumFunc	twoSumHash

void main() {
	int* twoSumRet;
	int* returnColumnSizes;

	int numsSize, returnSize = 0;


	int nums1[] = { 2,7,11,15 }; // TC 1
	int target1 = 9;

	printf("TC1 [2,7,11,15], target %d\n", target1);
	twoSumRet = twoSumFunc(nums1, sizeof(nums1) / sizeof(int), target1, &returnSize);
	assert(twoSumRet != NULL);
	printf("nums[return %d] == %d + nums[return %d] == %d sum is %d\n", twoSumRet[0], nums1[twoSumRet[0]], twoSumRet[1], nums1[twoSumRet[1]], target1);
	assert((twoSumRet[0] == 0) && (twoSumRet[1] == 1));
	free(twoSumRet);
	

	int nums2[] = { 3,2,4 }; // TC 2
	int target2 = 6;

	printf("TC2 [3,2,4], target %d\n", target2);
	twoSumRet = twoSumFunc(nums2, sizeof(nums2) / sizeof(int), target2, &returnSize);
	assert(twoSumRet != NULL);
	printf("nums[return %d] == %d + nums[return %d] == %d sum is %d\n", twoSumRet[0], nums2[twoSumRet[0]], twoSumRet[1], nums2[twoSumRet[1]], target2);
	assert((twoSumRet[0] == 1) && (twoSumRet[1] == 2));
	free(twoSumRet);


	int nums3[] = { 3,3 }; // TC 3
	int target3 = 6;

	printf("TC3 [3,3], target %d\n", target3);
	twoSumRet = twoSumFunc(nums3, sizeof(nums3) / sizeof(int), target2, &returnSize);
	assert(twoSumRet != NULL);
	printf("nums[return %d] == %d + nums[return %d] == %d sum is %d\n", twoSumRet[0], nums3[twoSumRet[0]], twoSumRet[1], nums3[twoSumRet[1]], target3);
	assert((twoSumRet[0] == 0) && (twoSumRet[1] == 1));
	free(twoSumRet);


	int nums4[] = { 2,7,11,15,8,3 }; // TC 4
	int target4 = 11;

	printf("TC4 [2,7,11,15,8,3], target %d\n", target4);
	twoSumRet = twoSumFunc(nums4, sizeof(nums4) / sizeof(int), target4, &returnSize);
	assert(twoSumRet != NULL);
	printf("nums[return %d] == %d + nums[return %d] == %d sum is %d\n", twoSumRet[0], nums4[twoSumRet[0]], twoSumRet[1], nums4[twoSumRet[1]], target4);
	assert((twoSumRet[0] == 4) && (twoSumRet[1] == 5));
	free(twoSumRet);


	int nums5[] = { 2,7,11,15,8,2 }; // TC 5
	int target5 = 11;

	printf("TC5 [2,7,11,15,8,2], target %d\n", target5);
	twoSumRet = twoSumFunc(nums5, sizeof(nums5) / sizeof(int), target5, &returnSize);
	assert(twoSumRet == NULL);
	printf("Not found, return == NULL\n");
}