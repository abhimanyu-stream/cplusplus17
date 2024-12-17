#ifndef SINGLE_LINKEDLIST_H
#define SINGLE_LINKEDLIST_H
class Node
{
public:
    int data;
    Node *next;
    Node();
    Node(int value);
};

class LinkedList
{

private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();
    void insert(int value);
    void remove(int value);
    void showList() const;
    void addAsFirstNode(int value);
    void addAfterNode(int valueOfCurrentNode, int value);
    void addAsLastNode(int value);
    Node *sortListAscending(Node *head);
    Node *sortListDescending(Node *head);
    Node *getListPointerAccess();
    Node *findNodePointerAccess(int value);
    // remove all duplicate Node having same data value
};

#endif