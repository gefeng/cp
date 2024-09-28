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
    struct hash {
        std::array<int64_t, 2> MOD = {int64_t(998244353), int64_t(1e9) + 7};
        std::array<int64_t, 2> BASE = {int64_t(37), int64_t(51)};
        
        std::vector<std::vector<int64_t>> h;
        std::vector<std::vector<int64_t>> d;
        
        hash(std::string& s) {
            int n = s.size();
            h = std::vector<std::vector<int64_t>>(2, std::vector<int64_t>(n + 1, 0));
            d = std::vector<std::vector<int64_t>>(2, std::vector<int64_t>(n + 1, 1));

            for(int i = 0; i < n; i++) {
                int c = s[i] - 'a' + 1;
                for(int j = 0; j < 2; j++) {
                    h[j][i + 1] = ((h[j][i] * BASE[j] % MOD[j]) + c) % MOD[j];
                    d[j][i + 1] = d[j][i] * BASE[j] % MOD[j];
                }    
            }
        }
        
        std::array<int64_t, 2> get(int l, int r) {
            std::array<int64_t, 2> res = {};
        
            int len = r - l + 1;
            for(int i = 0; i < 2; i++) {
                res[i] = (h[i][r + 1] - (h[i][l] * d[i][len] % MOD[i]) + MOD[i]) % MOD[i];
            }
            return res;
        }
    };
    
    std::vector<int> z_function(std::string s) {
        int n = s.size();
        std::vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = std::min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    
    int minStartingIndex(std::string s, std::string pattern) {
        int n = s.size();
        int m = pattern.size();
        
        std::string t = pattern;
        t.push_back('#');
        t.append(s);
        
        std::vector<int> z = z_function(t);
        
        hash h1(pattern);
        hash h2(s);
        
        auto is_identical = [&](int p1, int p2, int common) {
            if(p2 + m - 1 >= n) {
                return false;
            }
            
            std::array<int64_t, 2> res1 = h1.get(p1 + 1, m - 1);
            std::array<int64_t, 2> res2 = h2.get(p2 + common + 1, p2 + m - 1);
            return res1[0] == res2[0] && res1[1] == res2[1];
        };
        
        int ans = -1;
        for(int i = m + 1; i < n + m + 1; i++) {
            int common = z[i];
            if(common == m || (common == m - 1 && i + m <= n + m + 1) || is_identical(common, i - m - 1, common)) {
                ans = i - m - 1;
                break;
            }
        }
        
        return ans;
    }
};
