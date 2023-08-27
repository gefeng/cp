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
    long long minimumPossibleSum(int n, int target) {
        int64_t ans = 0;
        
        std::set<int> s;
        int cur = 1;
        while(s.size() != n) {
            if(s.find(target - cur) == s.end()) {
                s.insert(cur);
                ans += cur;
            }
            cur += 1;
        }
        
        return ans;
    }
};
