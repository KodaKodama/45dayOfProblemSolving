#include <string>
#include <cctype> 
using namespace std;

class Solution {
public:
    int sameChar(string A, string B) {
        int count = 0;
        int n = A.length(); 
        for (int i = 0; i < n; i++) {
            if (tolower(A[i]) == tolower(B[i])) {
                count++;
            }
        }
        return count;
    }
};
