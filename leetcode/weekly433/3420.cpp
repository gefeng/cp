#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int LOG = 20;
constexpr int64_t INF = int64_t(2e18);

class Solution {
public:
    long long countNonDecreasingSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        int64_t ans = 0;
        
        std::vector<int64_t> psum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i];
        }
        
        std::vector<int> stk;
        std::vector<int> nxt(n, n);
        for(int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && nums[stk.back()] <= nums[i]) {
                stk.pop_back();
            }
            
            if(!stk.empty()) {
                nxt[i] = stk.back();
            }
            
            stk.push_back(i);
        }
        
        std::vector<std::vector<int>> jump(LOG + 1, std::vector<int>(n, -1));
        std::vector<std::vector<int64_t>> cost(LOG + 1, std::vector<int64_t>(n, INF));
        for(int i = 0; i < n; i++) {
            jump[0][i] = nxt[i];
            cost[0][i] = int64_t(nxt[i] - i - 1) * nums[i] - (psum[nxt[i]] - psum[i + 1]);
        }
        
        for(int i = 1; i <= LOG; i++) {
            for(int j = 0; j < n; j++) {
                if(jump[i - 1][j] != n && jump[i - 1][j] != -1) {
                    jump[i][j] = jump[i - 1][jump[i - 1][j]];
                    cost[i][j] = cost[i - 1][j] + cost[i - 1][jump[i - 1][j]];
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            int64_t sum = 0;
            int now = i;
            for(int j = LOG; j >= 0; j--) {
                if(cost[j][now] == INF || sum + cost[j][now] > k) {
                    continue;
                }
                sum += cost[j][now];
                now = jump[j][now];
                if(now == n) {
                    break;
                }
            }
            if(now == n) {
                ans += now - i;
                continue;
            }
            
            int lo = now;
            int hi = nxt[now] - 1;
            int p = now;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(int64_t(mid - now) * nums[now] - psum[mid + 1] + psum[now + 1] + sum <= k) {
                    p = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            ans += p - i + 1;
        }
        
        return ans;
    }
};
