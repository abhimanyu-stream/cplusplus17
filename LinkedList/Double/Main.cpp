#include <iostream>
#include "DoubleLinkedList.h"

int main()
{

    DoubleLinkedList *list = new DoubleLinkedList();
    // Insert values into the list
    list->insert(20);
    list->insert(30);

    // Display the list
    std::cout << "Double Linked List: ";
    list->showDoubleLinkedList();

    delete list; // Clean up memory

    std::cout << "Double Linked List" << std::endl;

    return 0;
}