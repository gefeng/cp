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
    int numberOfBeautifulIntegers(int low, int high, int k) {
        auto get_digits = [](int x) {
            std::vector<int> d;
            while(x) {
                d.push_back(x % 10);
                x /= 10;
            }
            std::reverse(d.begin(), d.end());
            return d;
        };
        
        auto is_beauty = [&](int x){
            if(x % k != 0) {
                return false;
            }
            int cnt = 0;
            int len = 0;
            while(x) {
                int d = x % 10;
                if(d % 2 == 1) {
                    cnt += 1;
                }
                len += 1;
                x /= 10;
            }
            return len - cnt == cnt;
        };
        
        std::vector<int> d1 = get_digits(low);
        std::vector<int> d2 = get_digits(high);
    
        
        std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>> dp1(2, std::vector<std::vector<std::vector<std::vector<int>>>>(d1.size(), std::vector<std::vector<std::vector<int>>>(k, std::vector<std::vector<int>>(d1.size() + 1, std::vector<int>(d1.size() + 1, -1)))));
        std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>> dp2(2, std::vector<std::vector<std::vector<std::vector<int>>>>(d2.size(), std::vector<std::vector<std::vector<int>>>(k, std::vector<std::vector<int>>(d2.size() + 1, std::vector<int>(d2.size() + 1, -1)))));

        int cnt1 = dfs(d2, k, 0, (int)pow(10, d2.size() - 1), 0, 0, 1, 0, dp2);
        int cnt2 = dfs(d1, k, 0, (int)pow(10, d1.size() - 1), 0, 0, 1, 0, dp1);
        
        return cnt1 - cnt2 + (is_beauty(low) ? 1 : 0);
    }
    
    int dfs(std::vector<int>& digits, int k, int cur, int p, int len, int rem, int bounded, int cnt_eve, std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& dp) {
        int n = digits.size();
        if(cur == n) {
            return (rem == 0 && len - cnt_eve == cnt_eve && len) ? 1 : 0;
        }
        
        if(dp[bounded][cur][rem][cnt_eve][len] != -1) {
            return dp[bounded][cur][rem][cnt_eve][len];
        }
        
        int d = digits[cur];
        int res = 0;
        if(bounded) {
            //int st = cur == 0 ? 1 : 0;
            for(int i = 0; i <= d; i++) {
                res += dfs(digits, k, cur + 1, p / 10, len + ((len || i) ? 1 : 0), (rem + i * p) % k, i == d ? 1 : 0, cnt_eve + (i % 2 == 0 && (len || i != 0) ? 1 : 0), dp);
            }
        } else {
            for(int i = 0; i < 10; i++) {
                res += dfs(digits, k, cur + 1, p / 10, len + ((len || i) ? 1 : 0), (rem + i * p) % k, 0, cnt_eve + (i % 2 == 0 && (len || i != 0) ? 1 : 0), dp);
            }
        }
        
        return dp[bounded][cur][rem][cnt_eve][len] = res;
    }
};
