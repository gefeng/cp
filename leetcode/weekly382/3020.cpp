#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = 32000;

class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        std::map<int, int> m;
        int ans = 1;
        for(int x : nums) {
            m[x] += 1;
        }
        
        
        if(m.find(1) != m.end()) {
            ans = m[1] % 2 == 0 ? m[1] - 1 : m[1];
        }
        
        for(int i = 2; i < MAX; i++) {
            int64_t x = i;
            int cnt = 0;
            while(true) {
                if(m.find(x) == m.end() || x > (int64_t)1e9) {
                    ans = std::max(ans, cnt * 2 - 1);
                    break;
                }
                
                if(m[x] == 1) {
                    ans = std::max(ans, cnt * 2 + 1);
                    break;
                }
                cnt += 1;
                x *= x;
            }
        }
        
        return ans;
    }
};
