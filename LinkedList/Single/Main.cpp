#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

int main()
{

    LinkedList list;
    list.insert(10);
    list.insert(12);
    list.showList();
    list.addAsFirstNode(30);
    list.showList();
    list.addAfterNode(12, 50);
    list.showList();
    list.addAfterNode(10, 100);
    list.showList();
    list.addAsLastNode(600);
    list.showList();
    list.sortListAscending(list.getListPointerAccess());
    list.showList();

    return 0;
}