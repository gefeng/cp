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
    int gcd(int a, int b) {
        if(a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
    
    int minimumArrayLength(std::vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        int g = nums[0];
        for(int i = 2; i < n; i++) {
            g = gcd(g, nums[i]);
        }
        
        int ans = 0;
        if(g == nums[0]) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] == nums[0]) {
                    cnt += 1;
                }
            }
            
            ans = (cnt + 1) / 2;
        } else {
            ans = 1;
        }
        
        return ans;
    }
};
