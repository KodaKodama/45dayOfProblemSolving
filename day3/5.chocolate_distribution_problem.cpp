#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using namespace std;
    long long findMinDiff(vector<long long> a, long long n, long long m){
        // Sort the array
        sort(a.begin(), a.end());
        long long minDiff = LLONG_MAX;

        // Find the minimum difference in any subset of size m
        for (int i = 0; i <= a.size() - m; i++){
            long long diff = a[i + m - 1] - a[i];
            if (diff < minDiff){
                minDiff = diff;
            }
        }
        return minDiff;
    }


int main() {
    vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};
    long long n = a.size();
    long long m = 5;
    cout << "Minimum difference is: " << findMinDiff(a, n, m) << endl;
    return 0;
}
