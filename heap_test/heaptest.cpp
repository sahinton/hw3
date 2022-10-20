#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

int main(){
	Heap<int> pq(4);

	int arr[] = {8, 7, 10, 23, 2, 4, 6, 90, 3, 11, 13, 15, 77, 98, 54, 46, 56, 52, 35, 78, 32};

	for(int i = 0; i < 21; i++){
		cout<<arr[i]<<" ";
		pq.push(arr[i]);
	}

	cout<<endl;
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	
}