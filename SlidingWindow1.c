#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Google coding interview 1 2/24/25: return highest ack - fill in start(), returnHighestAck(), Ack()
// example: ack tracking starts at 10 and receives, Ack(10), Ack(16), Ack(12), Ack(11), Ack(14), returnHighestAck() = 12, Ack(13), returnHighestAck = 14

typedef struct node_s {
	int ackNum;
	struct node_s* next;
} node_t;

node_t* head = NULL;

int highestAck = 0;

// updates highestAck as well
// assumptions - no duplicates, no wrapping (e.g., call start() to reset the highest ACK),
// no limits on ack values (rules out optimizations like a bitmap tracker)
void insertNewAck(int ackNum) {

	node_t* nodePtr = head;
	node_t* prev = nodePtr;

	// first see if we can just update the highestAck
	if (ackNum == highestAck + 1) {
		highestAck++;

		// In this scenario, search the list to see if we can update further
		while ((nodePtr != NULL) && (nodePtr->ackNum == highestAck + 1)){
			head = head->next;
			highestAck++;
			prev = nodePtr;
			nodePtr = nodePtr->next;
			free(prev);
		}

		return;
	}

	node_t* newEl = malloc(sizeof(node_t));

	newEl->ackNum = ackNum;

	// first check for empty list
	if ((head == NULL) || (ackNum < head->ackNum)) {
		newEl->next = head;
		head = newEl;
	}
	else {
		while ((nodePtr != NULL) && (ackNum < nodePtr->ackNum)) {
			prev = nodePtr;
			nodePtr = nodePtr->next;
		}
		newEl->next = nodePtr;
		prev->next = newEl;
	}
}

// approach: track acks in a list and retire elements as they are acked.
void start(int ackNum) {
	highestAck = ackNum;
}

int returnHighestAck() {
	printf("highest ACK = %d\n", highestAck);
	return highestAck;
}

// called from other software, only to track ACKs, not to send.
void Ack(int ackNum) {
	insertNewAck(ackNum);
}

void main() {
	printf("sl_main\n");

	// test 1 - 10-16 with gaps
	start(9);
	Ack(10); Ack(16); Ack(12); Ack(11); Ack(14);
	assert(returnHighestAck() == 12);
	Ack(13);
	assert(returnHighestAck() == 14);
	Ack(15);
	assert(returnHighestAck() == 16);

	// test 2 - 50-70 backwards
	start(49);
	assert(returnHighestAck() == 49);
	Ack(70); Ack(69); Ack(68); Ack(67); Ack(66);
	assert(returnHighestAck() == 49);
	
	for (int i = 65; i > 50; i--) {
		Ack(i);
		assert(returnHighestAck() == 49);
	}
	Ack(50);
	assert(returnHighestAck() == 70);
	assert(head == NULL); // ack list should be empty at this point
}

