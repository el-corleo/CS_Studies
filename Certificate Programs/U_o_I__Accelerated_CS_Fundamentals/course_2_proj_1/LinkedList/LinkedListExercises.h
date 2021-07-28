
/**
 * @file LinkedListExercises.h
 * University of Illinois CS 400, MOOC 2, Week 1: Linked List
 * Spring 2019
 *                        STUDENT STARTER FILE
 *
 * @author Eric Huber - University of Illinois staff
 *
**/

/********************************************************************
  Week 1: Linked List and Merge Sort Exercises

  There are two exercises in this file. Please read the code comments
  below and see the provided instructions PDF before you begin. The
  other provided code files in the starter zip also contain important
  comments and hints about how to approach this.

  This is the only file you can edit for the sake of grading! You can
  edit the other provided starter files for testing purposes, but the
  autograder will assume that this is the only file that has been edited
  by you, and the others will be replaced with the original intended
  versions at grading time.
 ********************************************************************/

// Prevent the header from being included more than once per cpp file
#pragma once

// It's good to put system headers first, so that if your own libraries
// cause conflicts, the compiler will most likely identify the problem
// as being in your own source code files, where it arises later.
#include <iostream>
#include <string>

#include "LinkedList.h"

template <typename T>
void LinkedList<T>::insertOrdered(const T& newData) {
	// create new node
	Node* new_node_ptr = new Node(newData);
	// start at the beginning
	Node* traversal_ptr = head_;

	// empty list
	if (!traversal_ptr)
	{
		head_ = new_node_ptr;
		tail_ = new_node_ptr;
		size_++;
		return;
	}

	// find where element belongs
	while(traversal_ptr->data < newData)
	{
		if (!traversal_ptr->next) break;
		else	traversal_ptr = traversal_ptr->next;
	}	

	// insert at back
	if (traversal_ptr->data < newData)
	{
		new_node_ptr->prev = tail_;
		tail_->next = new_node_ptr;
		tail_ = new_node_ptr;
	}
	// insert at the front
	else if (!traversal_ptr->prev)
	{
		new_node_ptr->next = head_; 
		head_->prev = new_node_ptr;
		head_ = new_node_ptr;
	} else
	{
		traversal_ptr->prev->next = new_node_ptr;
		new_node_ptr->prev = traversal_ptr->prev;
		traversal_ptr->prev = new_node_ptr;
		new_node_ptr->next = traversal_ptr;
	}
	// increment size
	size_++;
}

/********************************************************************
  Exercise 2: Linear-time Merge

  This LinkedList member function is intended to perform the classic
  "merge" operation from the mergesort algorithm. It combines two sorted
  lists into a single sorted list. This algorithm is intended to run
  in linear time (that is, O(n) where n is the total number of elements
  in the input lists), so it is not appropriate to simply concatenate
  the two lists and then apply a sorting algorithm. Instead, the merge
  algorithm relies on the fact that the two input lists are already sorted
  separately in order to create the merged, sorted list in linear time.

  One of the implied input lists is the "*this" LinkedList instance that
  is calling the function, and the other input list is explicitly specified
  as the function argument "other". The function does NOT change either
  of the original lists directly, as the inputs are marked const.
  Instead, this function makes a new list containing the merged result,
  and it returns a copy of the new list. For example, one usage might
  look like this (OUTSIDE of this function, where we are making the call):

  LinkedList<int> leftList;
  // [... Add some sorted contents to leftList here. ...]
  LinkedList<int> rightList;
  // [... Add some sorted contents to rightList here. ...]
  LinkedList<int> mergedList = leftList.merge(rightList);

  You may assume that the two input lists have already been sorted.
  However, the lists may be empty, and they may contain repeated or
  overlapping elements. The lists may also have different lengths.
  For example, it's possible that these are the two input lists:

  Left list: [1, 2, 2, 3, 5, 5, 5, 6]
  Right list: [1, 3, 5, 7]

  And the result of merging those two sorted lists will contain all
  of the same elements, including the correct number of any duplicates,
  in sorted order:
  [1, 1, 2, 2, 3, 3, 5, 5, 5, 5, 6, 7]

  Because your implementation of this function operates on const inputs
  and returns a newly created list, you do not need to maintain the
  previous memory locations of any nodes as required in Exercise 1.
  You may need to make non-const "working copies" of the const input lists
  if you wish. You may approach this problem either iteratively or
  recursively, and you may use the member functions of the LinkedList class
  to make it simpler (such as push and pop), or you may edit the contents
  of lists explicitly by changing the pointers of a list or of its nodes
  (such as head_, tail_, next, and prev).

  Be sure that the size_ member of the resulting list is correct.

  A correct implementation of this function has O(n) time complexity
  for a list of length n. That is, in the worst case, you would
  traverse each element of the list some constant number of times.
  
  Important notes for getting the correct running time:

  1. Since both lists being merged are already sorted themselves, there
     is a way to merge them together into a single sorted list in a single
     traversal pass down the lists. This can run in O(n) time.
  2. You SHOULD NOT call any sorting function in your merge function.
  3. You SHOULD NOT call the insertOrdered function in merge. That would
     result in a very slow running time. (The insertOrdered function was
     part of the insertion sort exercise. It has nothing to do with merge
     or merge sort.)

  You can use "make test" followed by "./test" to check the correctness
  of your implementation, and then you can use "./test [bench]" to run
  some interesting benchmarks on the speed of your code.

 ********************************************************************/

template <typename T>
LinkedList<T> LinkedList<T>::merge(const LinkedList<T>& other) const {

  // You can't edit the original instance of LinkedList that is calling
  // merge because the function is marked const, and the "other" input
  // list is also marked const. However, here we'll make some convenient
  // "working copies" of the two lists: "*this" refers to the current
  // list object instance that is calling the merge member function, and
  // "other" refers to the list that was passed as an argument:
  LinkedList<T> left = *this;
  LinkedList<T> right = other;

  // So if this function was called as "A.merge(B)", then now, "left"
  // is a temporary copy of the "A" and "right" is a temporary copy
  // of the "B".
  
  // We will also create an empty list called "merged" where we can build
  // the final result we want. This is what we will return at the end of
  // the function.
  LinkedList<T> merged;

  while (!right.empty() || !left.empty())
  {
	if (left.empty())
	{
		while (!right.empty())
		{
			merged.pushBack(right.front());
			right.popFront();
		}
	} else if (right.empty())
	{
		while (!left.empty())
		{
			merged.pushBack(left.front());
			left.popFront();
		}
	} else
	{
		if (left.front() < right.front())
		{
			merged.pushBack(left.front());
			left.popFront();
		} else
		{
			merged.pushBack(right.front());
			right.popFront();
		}
	}
  }

  return merged;
}

