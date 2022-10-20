#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void trickleDown(unsigned int loc);
  void trickleUp(unsigned int loc);
  std::vector<T> myHeap;
	unsigned int m;
	PComparator c;




};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m_, PComparator c_){
  //setting m-ary and comparator
	m = m_;
	c = c_;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{ //vector function
  return myHeap.size();
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{ //vector function
  return myHeap.empty();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){ //push back then trickle up last value
  myHeap.push_back(item);
  trickleUp(myHeap.size() - 1);
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(unsigned int loc){
	if (((m * loc) + 1) >= myHeap.size()){ //if leaf node
    return;
  }
  unsigned int swappedChild = (m * loc) + 1; //leftmost child
	unsigned int smallestChild = swappedChild; //smallest 
  for(unsigned int i = swappedChild + 1; i < swappedChild + m; i++){ //loop through every child
    if (i < myHeap.size()){
      if (c(myHeap[i], myHeap[smallestChild])){ //set true smallest child
        smallestChild = i;
      }
    }
  }
	if (c(myHeap[smallestChild], myHeap[loc])){ //if matches comparator, swap
  	std::swap(myHeap[smallestChild], myHeap[loc]);
  	trickleDown(smallestChild);
	}
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(unsigned int loc){
	unsigned int parent;
	while(loc > 0){ //until reach the top
		parent = (loc - 1)/m; //formula for parent
		if(c(myHeap[loc], myHeap[parent])){ //swap if c is true
			std::swap(myHeap[loc], myHeap[parent]);
		}
		loc = parent; //set new loc to parent
	}
	return;
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty.");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return myHeap[0];



}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty.");


  }
  //swap first and last, remove last, trickle down top
	myHeap[0] = myHeap[myHeap.size() -1];
  myHeap.pop_back();
  trickleDown(0);



}



#endif

