#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        stack<int> stk;
        
        for(int i = 0; i < n; i++) {
            if(!stk.empty() && s[i] == '*') {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        
        string ans = "";
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
