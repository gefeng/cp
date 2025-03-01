#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = 23;

class Solution {
public:
    std::vector<int> permute(int n, long long k) {
        std::vector<int> ans(n);
        std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(n + 1, 0));
        
        std::vector<int> used(n + 1, 0);
        std::vector<int64_t> perm(21, 1);
        
        for(int i = 1; i <= 20; i++) {
            perm[i] = perm[i - 1] * i;
        }
        
        auto count_1 = [&](int n) {
            int64_t res = 0;
            if(n % 2 == 0) {
                res = perm[n / 2] * perm[n / 2] * 2;
            } else {
                res = perm[(n + 1) / 2] * perm[n / 2];
            }
            return res;
        };
        
        auto count_2 = [&](int n) {
            return perm[(n + 1) / 2] * perm[n / 2];
        };
        
        if(n <= MAX) {
            int64_t tot = count_1(n);
            if(tot < k) {
                ans.clear();
                return ans;
            }
        }
        
        for(int i = 0; i < n; i++) {
            bool found = false;
            for(int x = 1; x <= n; x++) {
                if(used[x] || (i - 1 >= 0 && x % 2 == ans[i - 1] % 2)) {
                    continue;
                }
                if(i == 0 && n % 2 == 1 && x % 2 == 0) {
                    continue;
                }
                
                int len = n - 1 - i;
                if(len > MAX || count_2(len) >= k) {
                    ans[i] = x;
                    used[x] = 1;
                    break;
                }
                
                k -= count_2(len);
            }
        }
        
        return ans;
    }
};
