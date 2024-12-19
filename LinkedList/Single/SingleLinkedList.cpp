#include <iostream>
#include "SingleLinkedList.h" // Header file for Node and LinkedList
using namespace std;

// Constructor for Node
Node::Node(int value)
{
    data = value;
    next = nullptr;
}

// Constructor for LinkedList
LinkedList::LinkedList()
{
    head = nullptr;
}

// Destructor for LinkedList (frees all nodes)
LinkedList::~LinkedList()
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;       // Store current node
        head = head->next; // Move head to the next node
        delete temp;       // Delete the current node
    }
    std::cout << "All nodes deleted.\n";
}

// Insert a node at the end of the list
void LinkedList::insert(int value)
{
    Node *temp;
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode; // If the list is empty, the new node becomes the head
    }
    else
    {
        temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Add the new node at the end
    }
}

// Display the list
void LinkedList::showList() const
{
    Node *temp = head; // Start from the head node

    if (temp == nullptr)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    std::cout << "Linked List: ";
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next; // Move to the next node
    }
    std::cout << "NULL" << std::endl;
}
/**
Explanation of Fixes:
Display Logic in showList():

Previously, the while loop was incorrect as temp->next != nullptr prevented printing the last node.
Fixed to while (temp != nullptr) to ensure all nodes are printed.
Added a message when the list is empty.
Proper Printing Format:

Added -> between node values for clarity, and NULL to indicate the end of the list.
Destructor Cleanup:

Added a clear message: "All nodes deleted."
Fixed Missing Semicolon:

The semicolon after std::cout << "all Node deleted\n" was missing.

 */

void LinkedList::addAsFirstNode(int value)
{
    Node *newNode = new Node(value); // Create a new node

    if (head == nullptr)
    {
        // Adding the new node as the first node when the list is empty
        std::cout << "List was empty. Adding " << value << " as the first node in the list." << std::endl;
        head = newNode;
    }
    else
    {
        // Adding the new node as the first node when the list is not empty
        std::cout << "List is not empty. Adding " << value << " as the first node in the list." << std::endl;
        newNode->next = head; // newNode->next has now pointing to previously existed List. i.e. head was previous pointing to List, now newNode is pointing previous List and head will point to this newNode
        head = newNode;       // Make the new node the head
    }
}
void LinkedList::addAfterNode(int valueOfCurrentNode, int value)
{
    Node *temp = head; // Start from the head
    Node *newNode = new Node(value);

    // Traverse the list to find the target node
    while (temp != nullptr)
    {
        if (temp->data == valueOfCurrentNode)
        {
            // Insert the new node after the current node
            newNode->next = temp->next; // Point newNode to the next of current node
            temp->next = newNode;       // Point current node to newNode
            std::cout << "Inserted " << value << " after " << valueOfCurrentNode << std::endl;
            return; // Exit after insertion
        }
        temp = temp->next; // Move to the next node
    }

    // If the valueOfCurrentNode is not found
    std::cout << "Node with value " << valueOfCurrentNode << " not found." << std::endl;
}

void LinkedList::addAsLastNode(int value)
{
    Node *newNode = new Node(value); // Create the new node

    if (head == nullptr)
    {
        // Empty List Case:
        // If the list is empty (head == nullptr), the function does not handle this case, which will lead to a null pointer dereference when attempting to access temp->next.

        // If the list is empty, make the new node the head
        head = newNode;
        std::cout << "List was empty. Added " << value << " as the first and last node." << std::endl;
    }
    else
    {
        // Traverse the list to find the last node
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next; // Move to the next node
        }

        // Add the new node at the end
        temp->next = newNode;
        std::cout << "Added " << value << " as the last node." << std::endl;
    }
}
Node *LinkedList::sortListAscending()
{
    Node *head = LinkedList::getListPointerAccess(); // check it
    if (head == nullptr)
    {
        std::cout << "List is Empty" << std::endl;
        return head; // Return immediately for an empty list
    }
    if (head->next == nullptr)
    {
        std::cout << "Only one Node in List, No need to sort" << std::endl;
        return head; // Return immediately for a single-node list
    }

    Node *temp1;
    Node *temp2;
    bool swapped;

    do
    {
        swapped = false; // Reset swapped to false at the start of each pass
        temp1 = head;

        while (temp1->next != nullptr)
        {
            temp2 = temp1->next;

            // Compare the data of adjacent nodes
            if (temp1->data > temp2->data)
            {
                // Swap the data of temp1 and temp2
                int tempData = temp1->data;
                temp1->data = temp2->data;
                temp2->data = tempData;

                swapped = true; // A swap occurred
            }

            temp1 = temp1->next; // Move to the next pair of nodes
        }

    } while (swapped); // Continue until no swaps occur in a full pass

    return head;
}
LinkedList *LinkedList::remove(int value)
{
    Node *head = LinkedList::getListPointerAccess();
    Node *current = head;
    Node *previous = nullptr; // Pointer to track the previous node

    // Check if the list is empty
    if (head == nullptr)
    {
        std::cout << "List is Empty. Nothing to delete." << std::endl;
        return this;
    }

    // Traverse the list to find the node to delete
    while (current != nullptr)
    {
        if (current->data == value)
        {
            // Case 1: Node to delete is the head
            if (current == head)
            {
                head = current->next;       // Move head to the next node
                delete current;             // Free memory for the head node
                setListPointerAccess(head); // Update the head in the linked list
                std::cout << "Node with value " << value << " deleted from the List." << std::endl;
                return this; // Return after deletion
            }

            // Case 2: Node to delete is not the head
            previous->next = current->next; // Bypass the current node [ Node having data is 12 its next is now pointed by previous. this Node is having data 30]
            delete current;                 // Free memory
            std::cout << "Node with value " << value << " deleted from the List." << std::endl;
            return this; // Return after deletion
        }

        // Move pointers forward
        previous = current;      // Move previous to the current node  // [previous is 10, then 12]
        current = current->next; // Move current to the next node
    }

    // If the node is not found
    std::cout << "Node with value " << value << " not found in the List." << std::endl;
    return this;
}

/**

Explanation:
Edge Case Handling:

If the list is empty (head == nullptr) or contains only one node (head->next == nullptr), sorting is unnecessary.
Bubble Sort Logic:

The outer loop continues until a full pass through the list completes without any swaps (swapped == 0).
The inner loop compares adjacent nodes (temp1 and temp2) and swaps their data values if needed.
Swapping Data:

Since we are swapping data rather than rearranging nodes, the algorithm is straightforward and avoids pointer manipulation.

Improvements and Notes:
Efficiency:

The bubble sort algorithm is not the most efficient (O(n²)), but it is simple and sufficient for small linked lists.
For larger lists, you may consider more efficient sorting techniques like merge sort.
Pointer-based Sorting:

This implementation swaps data. If you prefer to sort by rearranging pointers (to avoid large data swaps for large structures), the logic will need additional complexity.
Integration with LinkedList Class:

Ensure the function is part of the LinkedList class and that head is properly passed or accessed internally.

The logic behind the condition swapped == 0 in the outer loop is an essential part of the bubble sort algorithm. Here’s a detailed explanation:

What the Outer Loop Does:
The outer loop ensures that the list gets completely sorted by repeatedly iterating over the linked list until no further swaps are needed.
During each iteration (or pass) through the list:
Adjacent elements are compared and swapped if they are out of order.
If no swaps are performed during a complete pass, it means the list is already sorted.
Role of swapped:
Purpose:
The swapped flag is used to detect whether any elements were swapped during the current pass.
How It Works:
At the beginning of each pass, swapped is set to 0 (false).
During the pass, if any two elements are swapped, swapped is set to 1 (true).
At the end of the pass:
If swapped is 1, the outer loop continues for another pass.
If swapped is 0, the outer loop terminates because no swaps mean the list is sorted.
Why swapped is Necessary:
Without the swapped flag, the algorithm would blindly make a fixed number of passes (e.g., n passes for a list of size n), even if the list becomes sorted earlier. This wastes computational resources. Using swapped ensures that:

The algorithm stops as soon as the list is sorted.
It avoids unnecessary passes, improving efficiency.
How swapped == 0 Indicates the List is Sorted:
If no swaps occur during a complete pass, it means:
All adjacent elements are already in the correct order.
The entire list is sorted.
In this case, swapped remains 0, and the outer loop exits because there's no need for further passes.
Example Walkthrough:
Input: List = 4 -> 3 -> 2 -> 1
Pass 1:

Compare 4 and 3, swap. List: 3 -> 4 -> 2 -> 1 (swapped = 1).
Compare 4 and 2, swap. List: 3 -> 2 -> 4 -> 1 (swapped = 1).
Compare 4 and 1, swap. List: 3 -> 2 -> 1 -> 4 (swapped = 1).
End of pass: swapped == 1, continue outer loop.
Pass 2:

Compare 3 and 2, swap. List: 2 -> 3 -> 1 -> 4 (swapped = 1).
Compare 3 and 1, swap. List: 2 -> 1 -> 3 -> 4 (swapped = 1).
Compare 3 and 4, no swap. (swapped remains 1).
End of pass: swapped == 1, continue outer loop.
Pass 3:

Compare 2 and 1, swap. List: 1 -> 2 -> 3 -> 4 (swapped = 1).
Compare 2 and 3, no swap. (swapped remains 1).
Compare 3 and 4, no swap. (swapped remains 1).
End of pass: swapped == 1, continue outer loop.
Pass 4:

Compare 1 and 2, no swap. (swapped remains 0).
Compare 2 and 3, no swap. (swapped remains 0).
Compare 3 and 4, no swap. (swapped remains 0).
End of pass: swapped == 0, exit the outer loop.
Final Sorted List: 1 -> 2 -> 3 -> 4
Efficiency of the Logic:
Best Case (Already Sorted List):
No swaps occur during the first pass (swapped == 0), and the algorithm terminates early, requiring only 1 pass.
Worst Case (Reversed List):
The algorithm will perform multiple passes until the list is sorted.
For a list of size n, it can take up to n-1 passes.


 */
Node *LinkedList::sortListDescending(Node *head)
{

    // implement it
    return head;
}
Node *LinkedList::getListPointerAccess()
{
    return head;
}
Node *LinkedList::findNodePointerAccess(int value)
{
    // find Node whose data is equal to value and return Node *
    return head;
}
LinkedList *LinkedList::reverseList()
{
    Node *head = getListPointerAccess();

    // point  to last Node
    if (head == nullptr)
    {
        std::cout << "List is Empty.." << std::endl;
        return this;
    }
    if (head->next == nullptr)
    {
        std::cout << "Only One Node is List, No need to reverse List " << std::endl;
        return this;
    }
    Node *current = head;
    Node *next = nullptr;
    Node *previous = nullptr;
    // head=>4->7->8->NULL
    // while (current->next != nullptr) the last is skipped by by this condition
    while (current != nullptr)
    {
        // current is Node 1
        next = current->next;     // next is Node 2
        current->next = previous; // Node 1->Null
        previous = current;       // previous= Node 1
        current = next;           // current = Node 2
    }
    // std::cout << "last Node data" << temp->data;
    head = previous;
    setListPointerAccess(head); // Update the internal head pointer in the LinkedList object

    return this;
}
LinkedList *LinkedList::setListPointerAccess(Node *updatedHead)
{
    this->head = updatedHead;
    return this;
}
/**
Here’s a step-by-step explanation of how the while loop works in the reverseList function to reverse a singly linked list:

Initial State:
The linked list starts with:
head pointing to the first node of the list.
prev initialized to nullptr (this will eventually point to the reversed list).
current pointing to the first node of the original list (same as head).
next is uninitialized (to be used for temporarily storing the next node).
Execution of the while Loop:
Iteration 1:
Before Execution:

current points to the first node (Node1).
prev is nullptr.
next is uninitialized.
Inside the Loop:

next = current->next: Store the address of the second node (Node2) in next.
current->next = prev: Reverse the link by pointing the first node's next to nullptr (the value of prev).
prev = current: Move prev to point to the first node (Node1).
current = next: Move current to the second node (Node2).
After Execution:

current points to Node2.
prev points to Node1, and Node1->next is nullptr.
The partially reversed list is Node1 -> nullptr.
Iteration 2:
Before Execution:

current points to Node2.
prev points to Node1.
next holds the address of Node2.
Inside the Loop:

next = current->next: Store the address of the third node (Node3) in next.
current->next = prev: Reverse the link by pointing the second node's next to Node1.
prev = current: Move prev to point to the second node (Node2).
current = next: Move current to the third node (Node3).
After Execution:

current points to Node3.
prev points to Node2, and Node2->next points to Node1.
The partially reversed list is Node2 -> Node1 -> nullptr.
Iteration 3 (and so on):
The loop continues until all nodes are reversed. For each iteration:

current moves forward to the next node in the original list.
prev moves forward to the current node in the reversed list.
The current->next pointer is reversed to point to prev.
Final Iteration:
When current becomes nullptr, it means the end of the original list is reached.
prev now points to the last node of the original list, which is the new head of the reversed list.
After the Loop:
head = prev: Update the head pointer to the new front of the list.
The entire list is reversed, and the function returns the new head.
Illustrative Example:
For a list 1 -> 2 -> 3 -> nullptr:

After Iteration 1: 1 -> nullptr, prev points to 1.
After Iteration 2: 2 -> 1 -> nullptr, prev points to 2.
After Iteration 3: 3 -> 2 -> 1 -> nullptr, prev points to 3.
prev now represents the reversed list, and head is updated to point to it.

setListPointerAccess(head); // Update the internal head pointer in the LinkedList object

return this;
LinkedList *LinkedList::setListPointerAccess(Node *updatedHead)
{
    this->head = updatedHead;
    return this;
}

*/