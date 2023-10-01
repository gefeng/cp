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
    int minOperations(std::vector<int>& nums) {
        std::map<int, int> m;
        for(int x : nums) {
            m[x] += 1;
        }
        
        int ans = 0;
        for(auto [_, f] : m) {
            if(f % 3 == 0) {
                ans += f / 3;
            } else if(f % 3 == 2) {
                ans += f / 3 + 1;
            } else {
                if(f == 1) {
                    return -1;
                }
                
                ans += (f - 4) / 3 + 2;
            }
        }
        
        return ans;
    }
};
