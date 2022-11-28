#include "llrec.h"
#include <iostream>

using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if (head == nullptr){
		smaller = head;
		larger = head;
		//head = nullptr;
		return;
	}
	if (head->val <= pivot){ //tail recursion
		smaller = head;
		head = head->next;
		llpivot(head, smaller->next, larger, pivot);	
	}
	else if(head->val > pivot){
		larger = head;
		head = head->next;
		llpivot(head, smaller, larger->next, pivot);
	}
}

