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
    int maxFrequencyElements(std::vector<int>& nums) {
        int ans = 0;
        std::vector<int> f(200, 0);
        
        int max_f = 0;
        for(int x : nums) {
            f[x] += 1;
            max_f = std::max(max_f, f[x]);
        }
        
        for(int x : f) {
            if(x == max_f) {
                ans += x;
            }
        }
        
        return ans;
    }
};
