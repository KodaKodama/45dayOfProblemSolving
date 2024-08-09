#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Index for the end of the valid elements in nums1
        int j = n - 1; // Index for the end of nums2
        int k = m + n - 1; // Index for the end of the merged array in nums1

        // Merge nums1 and nums2 starting from the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If there are remaining elements in nums2, copy them
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

// Function to print the vector
void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the merge function
int main() {
    Solution sol;

    // Example arrays
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 with extra space for nums2
    vector<int> nums2 = {2, 5, 6}; // nums2 to merge into nums1
    int m = 3; // Number of valid elements in nums1
    int n = 3; // Number of elements in nums2

    // Merge nums2 into nums1
    sol.merge(nums1, m, nums2, n);

    // Print the merged array
    cout << "Merged array: ";
    printVector(nums1);

    return 0;
}
