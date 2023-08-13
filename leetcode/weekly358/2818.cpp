#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

class Solution {
public:
    int64_t q_pow(int64_t x, int64_t y) {
        int64_t res = 1;
        for(; y; x *= x, x %= MOD, y >>= 1) {
            if(y & 1) {
                res *= x;
                res %= MOD;
            }
        }
        return res;
    }
    
    int maximumScore(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        std::vector<int> freq(n, 0);
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            int cnt = 0;
            for(int f = 2; f * f <= x; f++) {
                if(x % f == 0) {
                    cnt += 1;
                    while(x % f == 0) {
                        x /= f;
                    }
                }
            }
            if(x > 1) {
                cnt += 1;
            }
            
            freq[i] = cnt;
        }
        
        std::vector<int> pre_greater(n, -1);
        std::vector<int> nxt_greater(n, n);
        std::vector<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && freq[s.back()] < freq[i]) {
                s.pop_back();
            }
            
            if(!s.empty()) {
                pre_greater[i] = s.back();
            }
            
            s.push_back(i);
        }
        
        s = std::vector<int>();
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && freq[s.back()] <= freq[i]) {
                s.pop_back();
            }
            
            if(!s.empty()) {
                nxt_greater[i] = s.back();
            }
            
            s.push_back(i);
        }
        
        std::vector<std::pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {nums[i], i};
        }
        
        std::sort(a.begin(), a.end(), std::greater<std::pair<int, int>>());
        
        int64_t score = 1;
        for(auto [x, i] : a) {
            int l = pre_greater[i];
            int r = nxt_greater[i];
            
            int64_t cnt = (int64_t)(i - l) * (r - i);
            int64_t take = std::min(cnt, (int64_t)k);
            
            score *= q_pow(x, take) % MOD;
            score %= MOD;
            k -= take;
        }
        
        return score;
    }
};
