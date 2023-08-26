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
    int minimumOperations(std::vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        
        std::vector<int> psum1(n + 1, 0);
        std::vector<int> psum2(n + 1, 0);
        std::vector<int> psum3(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            psum1[i] = psum1[i - 1] + (nums[i - 1] == 1 ? 1 : 0);
            psum2[i] = psum2[i - 1] + (nums[i - 1] == 2 ? 1 : 0);
            psum3[i] = psum3[i - 1] + (nums[i - 1] == 3 ? 1 : 0);
        }
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n - i; j++) {
                ans = std::min(ans, i - psum1[i] + j - (psum2[i + j] - psum2[i]) + n - i - j - (psum3[n] - psum3[i + j]));
            }
        }
        
        return ans;
    }
};
