#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    std::string findValidPair(std::string s) {
        std::array<int, 10> freq = {};
        int n = s.size();
        
        std::string ans = "";
        for(int i = 0; i < n; i++) {
            freq[s[i] - '0'] += 1;
        }
        
        for(int i = 0; i < n - 1; i++) {
            if(s[i] != s[i + 1] && freq[s[i] - '0'] == s[i] - '0' && freq[s[i + 1] - '0'] == s[i + 1] - '0') {
                ans.push_back(s[i]);
                ans.push_back(s[i + 1]);
                break;
            }
        }
        
        return ans;
    }
};
