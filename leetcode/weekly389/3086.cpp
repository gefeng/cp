#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)2e18;

class Solution {
public:
    long long minimumMoves(std::vector<int>& nums, int k, int maxChanges) {
        int n = nums.size();
        
        std::vector<int> ones;
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                ones.push_back(i);
            }
        }
        
        int m = ones.size();
        std::vector<int64_t> psum(m + 1, 0);
        for(int i = 0; i < m; i++) {
            psum[i + 1] = psum[i] + ones[i];
        }
        
        int64_t ans = maxChanges >= k ? k * 2 : INF;
        int max_use = std::min(k, maxChanges);
        for(int x = max_use; x >= 0 && x >= max_use - 3; x--) {
            int len = k - x;
            if(len == 0) {
                continue;
            }
            int64_t cost = (int64_t)x * 2;
            for(int l = 0, r = 0; r < m; r++) {
                if(r - l + 1 > len) {
                    l += 1;
                }
                
                if(r - l + 1 == len) {
                    int mid = (l + r) / 2;
                    int64_t sum_l = psum[mid + 1] - psum[l];
                    int64_t sum_r = psum[r + 1] - psum[mid + 1];
                    int64_t d = (int64_t)ones[mid] * (mid - l + 1) - sum_l + sum_r - (int64_t)ones[mid] * (r - mid);
                    ans = std::min(ans, d + cost);
                }
            }
        }
        
        return ans;
    }
};
