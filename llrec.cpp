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
		return;
	}
	if (head->val <= pivot){
		smaller = head;
		llpivot(head->next, smaller->next, larger, pivot);	
	}
	else if(head->val > pivot){
		larger = head;
		llpivot(head->next, smaller, larger->next, pivot);
	}
}

