#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0; // Handle empty vector case

        int maxprof = 0;
        int min_price = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            maxprof = max(maxprof, prices[i] - min_price);
            min_price = min(prices[i], min_price);
        }
        return maxprof;
    }
};
