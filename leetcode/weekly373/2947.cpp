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
    int beautifulSubstrings(std::string s, int k) {
        std::string v = "aeiou";
        int n = s.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cnt1 = 0;
            int cnt2 = 0;
            for(int j = i; j < n; j++) {
                if(v.find(s[j]) != std::string::npos) {
                    cnt1 += 1;
                } else {
                    cnt2 += 1;
                }
                
                if(cnt1 == cnt2 && (cnt1 * cnt2) % k == 0) {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};
