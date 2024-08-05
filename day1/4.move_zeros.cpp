#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != j) {
                    swap(nums[i], nums[j]); // Swap non-zero element with the zero at position j
                }
                j++;
            }
        }
    }
};
