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
    int maxActiveSectionsAfterTrade(std::string s) {
        int ans = 0;
        int n = s.size();
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += s[i] - '0';
        }
        
        ans = sum;
        int now_0 = 0;
        int now_1 = 0;
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && s[i] == s[j]) {
                i += 1;
            }
            if(s[j] == '0') {
                if(now_1 && now_0) {
                    ans = std::max(ans, now_0 + now_1 + i - j + sum - now_1);
                }
                now_0 = i - j;
            } else {
                now_1 = i - j;
            }
        }
        
        return ans;
    }
};
