#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<int>& curr, int ind, int n, int k, vector<vector<int>>& res) {
        // Base case: if the current combination size is k, add it to the result
        if (curr.size() == k) {
            res.push_back(curr); // Add the current combination to the result
            return;
        }

        // If the current combination size is not k, continue with recursion
        for (int i = ind; i <= n; i++) {
            curr.push_back(i); // Include the current number in the combination
            helper(curr, i + 1, n, k, res); // Recur with the next index
            curr.pop_back(); // Backtrack to remove the last number and explore other options
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res; // Resultant vector of combinations
        vector<int> curr; // Current combination
        helper(curr, 1, n, k, res); // Start recursion from index 1
        return res;
    }
};

// Example usage
int main() {
    Solution sol;
    int n = 4;
    int k = 2;
    vector<vector<int>> result = sol.combine(n, k);

    // Print the result
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
