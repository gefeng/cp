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
    long long countCompleteDayPairs(std::vector<int>& hours) {
        int64_t ans = 0;
        int n = hours.size();
        
        std::map<int, int> m;
        for(int i = 0; i < n; i++) {
            int r = hours[i] % 24;
            int t = (24 - r) % 24;
            
            if(m.find(t) != m.end()) {
                ans += m[t];
            }
            
            m[r] += 1;
        }
        
        return ans;
    }
};
