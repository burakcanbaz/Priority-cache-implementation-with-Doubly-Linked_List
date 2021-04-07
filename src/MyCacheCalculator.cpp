#include <cmath>
#include "../MyCacheCalculator.h"
#include "../Data.h"
#include "../ListNode.h"

typedef struct Data calculatedValues;

MyCacheCalculator::MyCacheCalculator(){

	head = new ListNode({0,0.0},nullptr,nullptr);
	current = head;
	lastSearched = 0;
	size = 0;
	capacity = 0;

}

MyCacheCalculator::~MyCacheCalculator(){

	while(head != nullptr){

		current = head->next;
		delete head;
		head = current;

	}
}

void MyCacheCalculator::add(int n,double fn){

	current = head;
	if(size != capacity){

		if(size == 0){
			current->next = new ListNode({n,fn},nullptr,current);
			size++;
		}

		else{
			ListNode* firstNode = new ListNode({n,fn},nullptr,current);
			firstNode->next = current->next;
			current->next->prev = firstNode;
			current->next = firstNode;
			size++;
		}
	}
	else{
		while(current->next != nullptr)
			current = current->next;
		current->prev->next = nullptr;
		delete current;
		current = nullptr;
		if(size != 1){
			ListNode* extraNode = new ListNode({n,fn},head->next,head);
			head->next->prev = extraNode;
			head->next = extraNode;
		}
		else{
			ListNode* extraNode = new ListNode({n,fn},nullptr,head);
			head->next = extraNode;
		}
	}
}



ListNode* MyCacheCalculator::swap(int lastSearched){

	if(current->prev != head){

		ListNode* currentPrev = current->prev;
		current->prev = currentPrev->prev;
		currentPrev->prev->next  = current;
		currentPrev->prev = current;
		currentPrev->next = current->next;

		if(current->next != nullptr)
			current->next->prev = currentPrev;

		current->next = currentPrev;
	}
	return current;

}



ListNode* MyCacheCalculator::search(int data){

	current = head->next;

	while(current != nullptr){

		if(current->datas.n == data){

			if(lastSearched == data){
				current = swap(lastSearched);
			}

			lastSearched = current->datas.n;
			return current;
		}
		current = current->next;
	}

	return nullptr;

}



std::ostream& operator<<(std::ostream& out,MyCacheCalculator& obj){

	std::string delimeter = "";
	obj.current = obj.head;
	while(obj.current->next != nullptr){
		obj.current = obj.current->next;
		std::cout << delimeter << obj.current->datas.n << " ";
		std::cout <<"f(" << obj.current->datas.fn << ")";
		delimeter = ", ";
	}

	return out;
}



void MyCacheCalculator::setCacheSize(int capacity){

	if(capacity == 0)
		throw std::invalid_argument("Cache size must be greater than 0");

	this->capacity = capacity;
}



double MyCacheCalculator::calculate(int n){

	current = head;

	ListNode* found = search(n);

	if(found != nullptr)
		return found->datas.fn;

	double result = 0;

	for(int i = 0 ; i <= n ; i++){
		result = result + (sin(i) * i);
	}
	add(n,result);

	return result;

}



int MyCacheCalculator::getCacheElement(int index){

	current = head->next;

	if(index > (capacity-1))
		return -1;

	while(index > 0){
		current = current->next;
		index--;
	}

	return current->datas.n;

}
