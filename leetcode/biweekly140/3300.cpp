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
    int minElement(std::vector<int>& nums) {
        int ans = int(1e5);
        
        for(int x : nums) {
            int sum = 0;
            while(x) {
                sum += x % 10;
                x /= 10;
            }
            ans = std::min(ans, sum);
        }
        
        return ans;
    }
};
