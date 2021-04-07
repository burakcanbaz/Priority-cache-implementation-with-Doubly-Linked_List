#ifndef MYCACHECALCULATOR_H_
#define MYCACHECALCULATOR_H_

#include <iostream>
#include "BaseFunctionCalculator.h"
#include "Data.h"
#include "ListNode.h"

class MyCacheCalculator : public BaseFunctionCalculator{

	calculatedValues myValues; //Keep the values of n and fn in struct
	ListNode* head;
	ListNode* current;

	int lastSearched;  //keep lastSearched data to increase priority
	int capacity;  //capacity given from user
	int size;  //comparison with capacity variable to create enough space for object.

	void add(int,double); //if there is space add values to linkedlist else delete last element and add given values at the beginning of the list
	ListNode* swap(int);  //increase priority if given data is entered twice in a row.
	ListNode* search(int); //if given data already in list search before calculation operation.

public:

	MyCacheCalculator();
	~MyCacheCalculator() override;

	friend std::ostream& operator<<(std::ostream&,MyCacheCalculator&); // "<<" operator overload for print object without any print function
	void setCacheSize(int) override;
	double calculate(int) override;
	int getCacheElement(int) override;


};



#endif /* MYCACHECALCULATOR_H_ */
