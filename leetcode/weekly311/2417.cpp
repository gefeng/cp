#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();
        int ans = 1;
        int len = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] - s[i - 1] == 1) {
                len++;
            } else {
                len = 1;
            }
            ans = max(ans, len);
        }
        
        return ans;
    }
};
