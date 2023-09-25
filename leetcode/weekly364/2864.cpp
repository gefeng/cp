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
    std::string maximumOddBinaryNumber(std::string s) {
        int n = s.size();
        std::string ans(n, '0');
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += s[i] - '0';
        }
        
        cnt -= 1;
        ans[n - 1] = '1';
        for(int i = 0; i < cnt; i++) {
            ans[i] = '1';
        }
        
        return ans;
    }
};
