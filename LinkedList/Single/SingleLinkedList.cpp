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
Node *LinkedList::sortListAscending(Node *head)
{
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
    return head;
}
Node *LinkedList::getListPointerAccess()
{
    return head;
}
Node *LinkedList::findNodePointerAccess(int value)
{
    return head;
}