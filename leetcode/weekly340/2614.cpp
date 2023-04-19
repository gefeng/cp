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
    int diagonalPrime(std::vector<std::vector<int>>& nums) {
        int n = nums.size();
        
        auto is_prime = [](int x) {
            if(x == 1) {
                return false;
            }
            for(int i = 2; i * i <= x; i++) {
                if(x % i == 0) {
                    return false;
                }
            }
            return true;
        };
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(is_prime(nums[i][i])) {
                ans = std::max(ans, nums[i][i]);
            }
            if(is_prime(nums[i][n - 1 - i])) {
                ans = std::max(ans, nums[i][n - 1 - i]);
            }
        }
        
        return ans;
    }
};
