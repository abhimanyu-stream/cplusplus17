#include <iostream>
#include "DoubleLinkedList.h"

Node::Node()
{
    data = 0;
    previous = nullptr;
    next = nullptr;
}
Node::Node(int value)
{
    data = value;
    previous = nullptr;
    next = nullptr;
}
/**
Node class implementations
Node::Node() : data(0), previous(nullptr), next(nullptr) {}
Node::Node(int value) : data(value), previous(nullptr), next(nullptr) {}
*/
/**
DoubleLinkedList constructor
DoubleLinkedList::DoubleLinkedList() : head(nullptr) {} */

DoubleLinkedList::~DoubleLinkedList()
{

    Node *temp = head;
    while (temp)
    {
        Node *toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
}
DoubleLinkedList::DoubleLinkedList() : head(nullptr) {}

DoubleLinkedList *DoubleLinkedList::insert(int value)
{

    Node *node = new Node(value);
    Node *temp;

    if (head == nullptr)
    {
        head = node;
        return this;
    }
    // find last Node in List
    temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    // HEAD->5->60->80->NULL
    // temp is pointing to 80 now
    temp->next = node;

    node->previous = temp;

    return this;
}
void DoubleLinkedList::showDoubleLinkedList()
{
    // DoubleLinkedList *list = DoubleLinkedList::getPointerAccess();
    // Node *head = list->head;
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}
DoubleLinkedList *DoubleLinkedList::getPointerAccess()
{

    return this;
}