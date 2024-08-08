#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while (head != NULL) {
            if (s.find(head) == s.end()) {
                s.insert(head);
            } else {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};

// Helper function to create a linked list with a cycle
ListNode* createCyclicList(vector<int>& nums, int pos) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    ListNode* cycleNode = nullptr;

    for (int i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
        if (i == pos) {
            cycleNode = current;
        }
    }

    if (cycleNode) {
        current->next = cycleNode;
    }

    return head;
}

// Helper function to create a non-cyclic linked list
ListNode* createLinkedList(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Test case 1: List with a cycle
    vector<int> nums1 = {3, 2, 0, -4};
    ListNode* head1 = createCyclicList(nums1, 1); // Cycle starts at index 1
    cout << "Test 1 - Has Cycle: " << (solution.hasCycle(head1) ? "True" : "False") << endl; // Expected: True

    // Test case 2: List without a cycle
    vector<int> nums2 = {1, 2};
    ListNode* head2 = createLinkedList(nums2);
    cout << "Test 2 - Has Cycle: " << (solution.hasCycle(head2) ? "True" : "False") << endl; // Expected: False

    return 0;
}
