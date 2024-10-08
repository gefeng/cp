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
    int maxGoodNumber(std::vector<int>& nums) {
        int ans = 0;
        
        std::sort(nums.begin(), nums.end());
        
        do {
            int res = 0;
            for(int x : nums) {
                int hb = -1;
                for(int i = 10; i >= 0; i--) {
                    if(x & (1 << i)) {
                        hb = i;
                        break;
                    }
                }
                res = (res << (hb + 1)) | x;
            }
            ans = std::max(ans, res);
        } while(std::next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};
