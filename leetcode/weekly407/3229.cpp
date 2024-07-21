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
    long long minimumOperations(std::vector<int>& nums, std::vector<int>& target) {
        int64_t ans = 0;
        int n = nums.size();
        
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = target[i] - nums[i];
        }
        
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                ans += std::abs(a[i]);
            } else {
                if(a[i] == 0) {
                    continue;
                }
                if(a[i] > 0) {
                    if(a[i - 1] >= 0) {
                        ans += std::max(0, a[i] - a[i - 1]);
                    } else {
                        ans += a[i];
                    }
                } else {
                    if(a[i - 1] >= 0) {
                        ans += -a[i];
                    } else {
                        ans += std::max(0, a[i - 1] - a[i]);
                    }
                }
            }
        }
        
        return ans;
    }
};
