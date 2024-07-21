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
    int maxOperations(std::string s) {
        int n = s.size();
        int ans = 0;
        
        bool zero = false;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(zero) {
                    ans += cnt;
                    zero = false;
                }
                cnt += 1;
            } else {
                zero = true;
            }
        }
        if(zero) {
            ans += cnt;
        }
        
        return ans;
    }
};
