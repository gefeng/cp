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
    int punishmentNumber(int n) {
        int ans = 0;
        
        for(int i = 1; i <= n; i++) {
            if(is_ok(i * i, i)) {
                ans += i * i;
            }
        }
        
        return ans;
    }
    
    bool is_ok(int sq, int t) {
        std::vector<int> digits;
        while(sq) {
            digits.push_back(sq % 10);
            sq /= 10;
        }

        std::reverse(digits.begin(), digits.end());

        return dfs(digits, t, 0, 0);
    }
    
    bool dfs(std::vector<int>& digits, int t, int cur, int sum) {
        int sz = digits.size();
        if(cur == sz) {
            return sum == t;
        }
        
        int x = 0;
        for(int i = cur; i < sz; i++) {
            x = x * 10 + digits[i];
            if(dfs(digits, t, i + 1, sum + x)) {
                return true;
            }
        }
        
        return false;
    }
};
