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
    int numberOfPoints(std::vector<std::vector<int>>& nums) {
        std::vector<int> diff(200, 0);
        for(auto& v : nums) {
            diff[v[0]] += 1;
            diff[v[1] + 1] -= 1;
        }
        
        int ans = 0;
        int sum = 0;
        for(int i = 1; i <= 100; i++) {
            sum += diff[i];
            if(sum) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
