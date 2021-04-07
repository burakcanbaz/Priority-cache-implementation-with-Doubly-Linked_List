#ifndef LISTNODE_H_
#define LISTNODE_H_

#include "Data.h"

typedef struct Data calculatedValues;

struct ListNode{

	calculatedValues datas;  //data struct for Node data
	ListNode* next;
	ListNode* prev;

	ListNode(calculatedValues, ListNode*, ListNode*);
};


#endif /* LISTNODE_H_ */
