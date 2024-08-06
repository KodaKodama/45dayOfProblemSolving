// first solution 
#include <vector>
#include <cmath>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for (auto x : mp) {
            if (x.second == 2) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};

// second solution 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      vector<int>ans;
      int n =size(nums);
      for(int i=0; i<n; i++){
        int x = abs(nums[i]);
        if(nums[x-1]<0){
            ans.push_back(x);
        }
        nums[x-1]*=-1;
      }
      return ans;
    }
};