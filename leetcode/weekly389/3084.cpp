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
    long long countSubstrings(std::string s, char c) {
        int64_t ans = 0;
        int n = s.size();
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                cnt += 1;
                ans += cnt;
            }
        }
        
        return ans;
    }
};
