#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:

    int gcd(int a, int b) {
        if(a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
    
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        
        bool has_one = false;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                has_one = true;
                break;
            }
        }
        
        int ans = -1;
        if(has_one) {
            ans = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] != 1) {
                    ans += 1;
                }
            }
        } else {
            int min_step = INF;
            for(int i = 0; i < n - 1; i++) {
                int g = nums[i];
                for(int j = i + 1; j < n; j++) {
                    g = gcd(g, nums[j]);
                    if(g == 1) {
                        min_step = std::min(min_step, j - i);
                    }
                }
            }
            
            if(min_step != INF) {
                ans = min_step + n - 1;
            }
        }
        
        return ans;
    }
};
