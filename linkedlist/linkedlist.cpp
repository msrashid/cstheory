#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node{
  struct node *next;
  int val;
};

class LinkedList{
  public:

  LinkedList(){
    head = NULL;
  }

  int size(){
    return count;
  }

  void increasesize(){
    count++;
  }

  bool empty(){
    if(this->size()==0){
      return true;
    }
    else{
      return false;
    }
  }

  int front(){
    return head->val;
  }

  int back(){
    return tail->val;
  }

  int pop_front(){
    int value = head->val;
    head = head->next;
    return value;
  }

  int pop_back(){
    int value = head->val;
    node *temp = new node;

    while(temp->next == NULL){
      temp = temp->next;
    }

    value = temp->val;
    temp = NULL;
    return value;
  }

  void push_front(int val){
    node *temp = new node;

    if(head==NULL){
      head = brandnewnode;
      tail = head;
      return;
    }
 
    head->next = head;
    head->val = val;
  }

  void push_back(int val){
    node *brandnewnode = new node;
    node *temp = new node;
    brandnewnode->val = val;
    brandnewnode->next = NULL;
    temp = head;
    this->increasesize();

    if(head==NULL){
      head = brandnewnode;
      tail = head;
      return;
    }

    while(temp->next != NULL){
      temp = temp->next;
    }

    temp->next=brandnewnode;
    tail = temp->next;
  } 

  void printlist(){
    node *temp = new node;
    temp = head;
    while(temp->next != NULL){
      cout << temp->val << endl;
      temp = temp->next;
    }
    cout << temp->val << endl;
  }

  int value_at(int position){
    int listposition = 0;
    node *temp = new node;
    temp = head;

    if(position > count - 1){
      cout << "Position does not exist" << endl;
    }
    else{
      while(listposition != position){
        temp = temp->next;
        listposition++;
      }
      return temp->val;
    }
  }
  
  private: 

  node *head, *tail;  
  int count = 0;
};

int main() {
  LinkedList one;
  one.push_back(1);
  one.push_back(1);
  one.push_back(5);
  one.push_back(1);
  one.printlist();
  cout << "VALUE "<< one.value_at(5) << endl;

}