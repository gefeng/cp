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
    long long beautifulSubstrings(std::string s, int k) {
        std::string v = "aeiou";
        int n = s.size();
        int64_t ans = 0;
        
        int x = k;
        int nk = 1;
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                int cnt = 0;
                while(x % f == 0) {
                    x /= f;
                    cnt += 1;
                }
                
                cnt = f == 2 ? (cnt + 3) / 2 : (cnt + 1) / 2;
                for(int i = 0; i < cnt; i++) {
                    nk *= f;
                }
            }
        }
        
        if(x > 1) {
            nk *= x == 2 ? 4 : x;
        }
        
        int sum = 0;
        std::vector<std::map<int, int>> m(nk);
        m[nk - 1][0] = 1;
        for(int i = 0; i < n; i++) {
            sum += v.find(s[i]) != std::string::npos ? 1 : -1;
            int rem = i % nk;
            
            if(m[rem].find(sum) != m[rem].end()) {
                ans += m[rem][sum];
            }
            m[rem][sum] += 1;
        }
        
        return ans;
    }
};
