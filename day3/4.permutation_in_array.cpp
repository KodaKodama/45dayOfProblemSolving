#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
  public:
    bool isPossible(int k, vector<int> &arr1, vector<int> &arr2) {
        // Sort arr1 in ascending order
        sort(arr1.begin(), arr1.end());
        // Sort arr2 in descending order
        sort(arr2.begin(), arr2.end(), greater<int>());
        // Check the condition
        for (int i = 0; i < arr1.size(); i++) {
            if ((arr1[i] + arr2[i]) < k) {
                return false;
            }
        }
        return true;
    }
};
