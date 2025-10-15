#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class Linkedlist {
    // properties = variables
    private :
        Node *head, *cur;
        int n;

    // constructor = special method 
    public :
        Linkedlist(){
            head = nullptr;
            cur = nullptr;
            n = 0;
        }
        
        // methods
        int size(){
            return n;
        }

        void traverse(){
            if (n==0){
                cout << "(empty!)\n"; //if empty, print empty
            }
            cur = head; //start from head
            while (cur != nullptr){
                cout <<cur->value<<"->"; //print value
                cur = cur->next; //move to next node
            }
            cout<<endl; 
        }
        
        Node* getHead(){
            return head; //return head pointer
        }

        void insertFront(int val){
            Node* nNode = new Node{val, nullptr}; //create new node
            nNode->next = head; //link new node to previous head
            head = nNode; //update head to new node
            n++; //increment size
        }

        void insertEnd(int val){
            if (n==0){
                insertFront(val); //if empty, insert at front
                return;
            }
            cur = head; //traverse to the end of the list
            while (cur->next != nullptr){
                cur = cur->next; //move to next node
            }
            Node* nNode = new Node {val, nullptr}; //create new node
            cur->next = nNode; //link last node
            n++; //increment size
            
        }

        void insertMiddle(int val, int pos){
            if (pos > n){
                cout << "Out of node range!\n"; //if pos is greater than size, it's invalid
                return;
            }
            if (pos == 0){
                insertFront(val); //if pos is 0, insert at front
                return;
            }
            if (pos == n){
                insertEnd(val); //if pos is size, insert at end
                return;
            }
            cur = head; //traverse to the node before the position
            for (int i=0; i<pos-1; i++){
                cur = cur->next; //move to next node
            }
            Node* nNode = new Node {val, nullptr}; //create new node
            nNode->next = cur->next; //link new node to the next node
            cur->next = nNode; //link previous node to new node
            n++; //increment size
        }

        void deleteFront(){
            if (n==0){
                cout << "Empty list!\n"; //there's nothing to delete when empty
                return;
            }
            Node* delNode = head; //node to be deleted
            head = head->next; //update head to next node
            delete delNode; //free memory to not cause memory leak
            n--; //decrement size
        }

        void deleteEnd(){
            if (n==0){
                cout << "Empty list!\n"; //there's nothing to delete when empty
                return;
            }
            if (n==1){
                deleteFront(); //if only 1 node, delete at front
                return;
            }
            cur = head; //traverse to the second last node
            while (cur->next->next != nullptr){
                cur = cur->next; //move to next node
            }
            Node* delNode = cur->next; //node to be deleted
            cur->next = nullptr; //update the second last node to be the last node
            delete delNode; //free memory to not cause memory leak
            n--; //decrement size
        }

        void deleteMiddle(int pos){
            if (pos > n){
                cout << "Out of node range!\n"; //if pos is greater than size, it's invalid
                return;
            }
            if (pos==0){
                deleteFront(); //if pos is 0, delete at front
                return;
            }
            if (pos==n-1){
                deleteEnd(); //if pos is size-1, delete at the end
                return;
            }
            cur = head; //traverse to the node before the position
            for (int i=0; i<pos-1; i++){
                cur = cur->next; //move to next node
            }
            Node* delNode = cur->next; //node to be deleted
            cur->next = cur->next->next; //link previous node to the next node
            delete delNode; //free memory to not cause memory
            n--; //decrement size
        }

        void swapNodes(int pos1, int pos2){
            if (pos1 == pos2){
                return; //no need to swap if both pos are the same
            }
            if (pos1 > n || pos2 > n){
                cout << "Out of node range!\n"; //if pos is greater than size, it's invalid
                return;
            }
            Node *node1 = head, *node2 = head; //start from head
            for (int i=0; i<pos1; i++){
                node1 = node1->next; //move to next node
            }
            for (int i=0; i<pos2; i++){
                node2 = node2->next; //move to next node
            }
            int temp = node1->value; //swap the two node values
            node1->value = node2->value; //swap the node values
            node2->value = temp; //assign temp to node2 value
        }

        void searchValue(int val){
            cur = head; //start from head
            int pos = 0;
            while (cur != nullptr){
                if (cur->value == val){
                    cout << "Value "<<val<<" found at position "<<pos<<endl; //print pos if found
                    return;
                }
                cur = cur->next; //move to next node
                pos++; //increment pos
            }
            cout << "Value "<<val<<" not found!\n"; //print not found if reached the end
        }
};