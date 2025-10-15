#include <iostream>
#include <string>
#include "linkedList.hpp"

using namespace std;

int main(){
    Linkedlist list;

    cout << "Insert at front: "<<endl;
    list.insertFront(10);
    list.insertFront(15);
    list.traverse();
    
    cout << "Insert at end: "<<endl;
    list.insertEnd(20);
    list.insertEnd(17);
    list.traverse();

    cout << "Insert in middle: "<<endl;
    list.insertMiddle(13,2);
    list.traverse();

    cout << "Delete at front: "<<endl;
    list.deleteFront();
    list.traverse();

    cout << "Delete at end: "<<endl;
    list.deleteEnd();
    list.traverse();

    cout << "Delete in middle: "<<endl;
    list.deleteMiddle(1);
    list.traverse();

    cout << "Swap two nodes: "<<endl;
    list.swapNodes(0,1);
    list.traverse();

    cout << "Search for value: "<<endl;
    list.searchValue(10);
    return 0;
}