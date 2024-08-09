#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode *current = head;
        
        while (current != NULL && current->next != NULL) {
            if (current->val == current->next->val) {
                // Duplicate found
                ListNode *temp = current->next;
                current->next = current->next->next; // Skip the duplicate
                delete temp; // Free memory
            } else {
                // No duplicate, move to next node
                current = current->next;
            }
        }
        
        return head;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to test the deleteDuplicates function
int main() {
    // Create a linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution sol;
    head = sol.deleteDuplicates(head);

    // Print the result
    cout << "List after removing duplicates: ";
    printList(head);

    // Clean up remaining nodes
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
