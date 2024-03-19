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
    int sumOfEncryptedInt(std::vector<int>& nums) {
        int ans = 0;
        for(int x : nums) {
            int max_d = 0;
            int y = x;
            while(y) {
                max_d = std::max(max_d, y % 10);
                y /= 10;
            }
            
            y = x;
            int v = 0;
            while(y) {
                v *= 10;
                v += max_d;
                y /= 10;
            }
            
            ans += v;
        }
        
        return ans;
    }
};
