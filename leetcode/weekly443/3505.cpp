#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

class Solution {
public:
    long long minOperations(std::vector<int>& nums, int x, int k) {
        int n = nums.size();
        std::multiset<int> ms_1;
        std::multiset<int> ms_2;
        std::vector<int64_t> best(n, 0);
        
        int64_t sum_1 = 0;
        int64_t sum_2 = 0;
        for(int l = 0, r = 0; r < n; r++) {
            if(ms_1.empty() || *ms_1.rbegin() >= nums[r]) {
                ms_1.insert(nums[r]);
                sum_1 += nums[r];
            } else {
                ms_2.insert(nums[r]);
                sum_2 += nums[r];
            }
            
            if(r - l + 1 > x) {
                if(ms_1.find(nums[l]) != ms_1.end()) {
                    ms_1.erase(ms_1.find(nums[l]));
                    sum_1 -= nums[l];
                } else {
                    ms_2.erase(ms_2.find(nums[l]));
                    sum_2 -= nums[l];
                }
                l += 1;
            }
            
            if(r - l + 1 == x) {
                if(x % 2 == 0) {
                    while(ms_1.size() > ms_2.size()) {
                        int last = *ms_1.rbegin();
                        ms_1.erase(std::prev(ms_1.end()));
                        ms_2.insert(last);
                        sum_1 -= last;
                        sum_2 += last;
                    }
                    while(ms_2.size() > ms_1.size()) {
                        int first = *ms_2.begin();
                        ms_2.erase(ms_2.begin());
                        ms_1.insert(first);
                        sum_1 += first;
                        sum_2 -= first;
                    }
                } else {
                    while(ms_1.size() >= ms_2.size()) {
                        int last = *ms_1.rbegin();
                        ms_1.erase(std::prev(ms_1.end()));
                        ms_2.insert(last);
                        sum_1 -= last;
                        sum_2 += last;
                    }
                    
                    while(ms_1.size() + 1 < ms_2.size()) {
                        int first = *ms_2.begin();
                        ms_2.erase(ms_2.begin());
                        ms_1.insert(first);
                        sum_1 += first;
                        sum_2 -= first;
                    }
                }
                
                int64_t med = *ms_2.begin();
                best[l] = med * ms_1.size() - sum_1 + sum_2 - med * ms_2.size();
            }
        }
        
        std::vector<std::vector<int64_t>> dp(k + 1, std::vector<int64_t>(n + 1, INF));
        for(int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[j][i] = std::min(dp[j][i], dp[j][i - 1]);
                if(i - x >= 0 && j - 1 >= 0 && dp[j - 1][i - x] != INF) {
                    dp[j][i] = std::min(dp[j][i], dp[j - 1][i - x] + best[i - x]);
                }
            }
        }
        
        return dp[k][n];
    }
};
