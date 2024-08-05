#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int h = nums.size() - 1;  
        int l = 0;                
        int index = 0;            
        
        while (index <= h) {
            if (nums[index] == 2) {
                swap(nums[index], nums[h]);
                h--;
            } else if (nums[index] == 0) {
                swap(nums[index], nums[l]);
                index++;
                l++;
            } else {
                index++;
            }
        }
    }
};
