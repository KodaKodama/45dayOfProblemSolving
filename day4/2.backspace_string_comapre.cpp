#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ans = "";
        string ans1 = "";
        
        // Process the first string 's'
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '#' && ans.empty()) continue;
            if(s[i] == '#' && !ans.empty()) {
                ans.pop_back();
            } else {
                ans += s[i];
            }
        }
        
        // Process the second string 't'
        for(int i = 0; i < t.length(); i++) {
            if(t[i] == '#' && ans1.empty()) continue;
            if(t[i] == '#' && !ans1.empty()) {
                ans1.pop_back();
            } else {
                ans1 += t[i];
            }
        }
        
        // Compare the processed strings
        return ans == ans1;
    }
};

// Main function to test the backspaceCompare function
int main() {
    Solution solution;

    // Test cases
    string s1 = "ab#c";
    string t1 = "ad#c";
    cout << "Test 1 - Result: " << (solution.backspaceCompare(s1, t1) ? "True" : "False") << endl; // Expected: True

    string s2 = "ab##";
    string t2 = "c#d#";
    cout << "Test 2 - Result: " << (solution.backspaceCompare(s2, t2) ? "True" : "False") << endl; // Expected: True

    string s3 = "a##c";
    string t3 = "#a#c";
    cout << "Test 3 - Result: " << (solution.backspaceCompare(s3, t3) ? "True" : "False") << endl; // Expected: True

    string s4 = "a#c";
    string t4 = "b";
    cout << "Test 4 - Result: " << (solution.backspaceCompare(s4, t4) ? "True" : "False") << endl; // Expected: False

    return 0;
}
