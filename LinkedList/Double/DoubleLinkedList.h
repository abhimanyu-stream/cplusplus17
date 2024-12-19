#ifndef DOUBLE_LINKEDLIST_H
#define DOUBLE_LINKEDLIST_H

class Node
{
public:
    int data;
    Node *next;
    Node *previous;
    Node();
    Node(int value);
};

class DoubleLinkedList
{

private:
    Node *head;

public:
    DoubleLinkedList();
    //DoubleLinkedList(int value);
    ~DoubleLinkedList();

    DoubleLinkedList *insert(int value);
    DoubleLinkedList *update(int value);
    DoubleLinkedList *remove(int value);
    void showDoubleLinkedList();
    DoubleLinkedList *getPointerAccess();
    DoubleLinkedList *setPointerAccess(Node *head);
    DoubleLinkedList *reverse();

    Node *sortListAscending();
    Node *sortListDescending();
    Node *findNodePointerAccess(int value);
};

#endif