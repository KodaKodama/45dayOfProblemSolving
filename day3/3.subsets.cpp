#include <vector>
using namespace std;

class Solution {
public:
    void generateSubsets(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }
        
        // Include the current element
        subset.push_back(nums[index]);
        generateSubsets(index + 1, nums, subset, ans);
        
        // Exclude the current element
        subset.pop_back();
        generateSubsets(index + 1, nums, subset, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; // This will store all the subsets
        vector<int> subset; // This will store the current subset
        generateSubsets(0, nums, subset, ans);
        return ans;
    }
};
