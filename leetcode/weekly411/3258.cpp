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
    int countKConstraintSubstrings(std::string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int cnt_0 = 0;
            int cnt_1 = 0;
            for(int j = i; j < n; j++) {
                if(s[j] == '0') {
                    cnt_0 += 1;
                } else {
                    cnt_1 += 1;
                }
                ans += (cnt_0 <= k || cnt_1 <= k) ? 1 : 0; 
            }
        }
        
        return ans;
    }
};
