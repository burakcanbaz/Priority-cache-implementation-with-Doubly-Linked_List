#include "../ListNode.h"

ListNode::ListNode(calculatedValues data, ListNode* nextElement, ListNode* prevElement)
			:datas{data.n,data.fn},
			 next{nextElement},
			 prev{prevElement}
			 {}



