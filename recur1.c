#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Google coding interview 2/24/25
// Find all combinations of a string of characters. The string is null terminated

// if defined, then do not store string duplicates
//#undef DEDUPE_STRINGS
#define DEDUPE_STRINGS 1

#define TEST_STRING "AABC"
#define TEST_STRING_LEN	sizeof(TEST_STRING)

typedef struct node_s {
	char string[TEST_STRING_LEN]; // +1 for NULL character
	struct node_s* next;
} node_t;

node_t* head;

void charSwap(char *char1, char *char2) {
	char tempChar = *char1;

	*char1 = *char2;
	*char2 = tempChar;
}

// insert into linked list in order
void insertString(char* string) {
	node_t* newEl = malloc(sizeof(node_t));
	node_t* nodePtr = head;
	node_t* prev = head;

	strcpy_s(newEl->string, TEST_STRING_LEN, string); // assume inserted/not deduped

	// special cases first - empty list or new head
	if ((head == NULL) || (strcmp(head->string, newEl->string) > 0)) { // new string replaces head if less than head
		newEl->next = head;
		head = newEl;
	}
	else {
		// find first string greater than current string and insert
		while (nodePtr != NULL) {

			int strcmpRet = strcmp(nodePtr->string, newEl->string);
#ifdef DEDUPE_STRINGS
			if (strcmpRet == 0) { // found the same string, so don't save this one
				free(newEl);
				return;
			}
#endif
			if (strcmp(nodePtr->string, newEl->string) > 0) {
				break;
			}
			prev = nodePtr;
			nodePtr = nodePtr->next;
		}

		newEl->next = nodePtr;
		prev->next = newEl;
	}
}


//  Find all permutations of a character string - abc, aab, unlimited string length. String is null terminated
// backtracking algorithm will build a binary tree with each combination and visit every node.
int recur1(int index, char* string, int strLen) {

	if (index == strLen) { // finished with this string/node
		insertString(string);
#if 0 // the actual question was to return the letter's numeric representation
		for (int j = 0; j < strLen; j++) {
			printf("%d", string[j]-'A');
		}
		printf("\n");
#endif
		return 0;
	}

	for (int i = index; i < strLen; i++) {
		charSwap(&string[index], &string[i]);
		recur1(index + 1, string, strLen);
		charSwap(&string[index], &string[i]);
	}

	return 0;
}

int printList() {
	node_t* nodePtr = head;
	node_t* prev = nodePtr;

	while (nodePtr != NULL) {
		printf("%s ", nodePtr->string);

		head = head->next;
		nodePtr = nodePtr->next;
		free(prev);
		prev = nodePtr;
	}
	printf("\n");
}

void main() {

	int strLen = (int)strlen(TEST_STRING);
	int numStrings = (int)tgamma(strLen + 1); // tgamma(num)+1 is a factorial operation
	char string[] = TEST_STRING;

	recur1(0, string, strLen);

	printList();
}
