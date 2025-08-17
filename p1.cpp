#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
int main(){
    Node * head = new Node(1);
    Node * second = new Node(2);
    Node * third = new Node(3);
    // linking the nodes 
    head -> next = second;
    second -> next = third;
    // printing the linked list
    Node * temp = head;
    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
