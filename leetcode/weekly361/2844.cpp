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
    int minimumOperations(std::string num) {
        int n = num.size();
        int ans = n;
        
        for(std::string s : {"00", "25", "50", "75"}) {
            int i = n - 1;
            int cnt = 0;
            while(i >= 0 && num[i] != s[1]) {
                i -= 1;
                cnt += 1;
            }
            
            if(i <= 0) {
                continue;
            }
            
            i -= 1;
            while(i >= 0 && num[i] != s[0]) {
                i -= 1;
                cnt += 1;
            }
            
            if(i < 0) {
                continue;
            }
            
            ans = std::min(ans, cnt);
        }
        
        for(int i = 0; i < n; i++) {
            if(num[i] == '0') {
                ans = std::min(ans, n - 1);
                break;
            }
        }
        
        return ans;
    }
};
