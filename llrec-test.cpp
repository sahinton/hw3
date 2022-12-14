#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
#include "stack.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------
struct greaterThan10{
	bool operator()(int pointerVal){
		if (10 < pointerVal){
			return true;
		}
		else if (10 > pointerVal){
			return false;
		}
		else{
			return false;
		}
	}
};

struct IsEven
{
    bool operator()(int num) {
        return (num % 2) == 0;
    }
};

struct lessThan10{
	bool operator()(int pointerVal){
		if (10 > pointerVal){
			return true;
		}
		else if (10 < pointerVal){
			return false;
		}
		else{
			return false;
		}
	}
};

struct Even{
	bool operator()(int value){
		if (value % 2 == 0){
			return true;
		}
		else if (value % 2 != 0){
			return false;
		}
		else{
			return false;
		}
	}
};






int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    Node* smaller;
    Node* larger;
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
    llpivot(head, smaller, larger, 1);
    cout << endl;
    if (smaller){
			cout << "smaller" << endl;
        print(smaller);
    }
    cout << endl;
    if(larger){
			cout << "larger" << endl;
        print(larger);
    }
		cout << endl;
    if(head){
			cout << "head" << endl;
        print(head);
    }

		IsEven filter;
		Node* temp = llfilter(larger, filter);
		cout << "All even values filtered out: ";
		print(temp);

		Stack<int> myStack;
		cout << myStack.empty() << endl;
		//myStack.pop();
		myStack.push(5);
		myStack.push(6);
		myStack.push(7);
		myStack.push(8);
		myStack.push(9);
		cout << myStack.size() << endl;
		cout << myStack.top() << endl;
		myStack.pop();
		cout << myStack.top() << endl;
		cout << myStack.size() << endl;
		cout << myStack.empty() << endl;
		/*myStack.pop();
		myStack.pop();
		myStack.pop();
		myStack.pop();
		dealloc(smaller);
		dealloc(larger);*/


    return 0;

}
