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
    LinkedList(Node node);
    ~LinkedList();
    void insert(int value);
    LinkedList *remove(int value);
    void showList() const;
    void addAsFirstNode(int value);
    void addAfterNode(int valueOfCurrentNode, int value);
    void addAsLastNode(int value);
    LinkedList *reverseList();
    LinkedList *setListPointerAccess(Node *head);
    Node *sortListAscending();
    Node *sortListDescending(Node *head);
    Node *getListPointerAccess();
    Node *findNodePointerAccess(int value);
    // remove all duplicate Node having same data value
};

#endif