/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if(in == nullptr){ //base case, when this runs then it will return to main, allowing the previously pause SPLIT to finish
    return;
  }

  Node* head = in; //new Node* head for each split
  in = in->next; //in is being used to make new heads over and over until it eventually points to null

  split(in, odds, evens); //pauses the current split to begin the next one

  if(head->value % 2 == 0){
    head->next = evens;
    evens = head;
  }
  else{
    head->next = odds;
    odds = head;
  }
  
}

/* If you needed a helper function, write it here */

