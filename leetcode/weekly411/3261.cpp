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
    std::vector<long long> countKConstraintSubstrings(std::string s, int k, std::vector<std::vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        std::vector<long long> ans(m, 0);
        std::vector<int> pos_0;
        std::vector<int> pos_1;
        std::vector<int> nxt(n, -1);
        std::vector<int64_t> psum(n + 1, 0);

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                pos_0.push_back(i);
            } else {
                pos_1.push_back(i);
            }
        }
        
        for(int i = 0; i < n; i++) {
            int j = std::lower_bound(pos_0.begin(), pos_0.end(), i) - pos_0.begin();
            if(j + k < pos_0.size()) {
                nxt[i] = std::max(nxt[i], pos_0[j + k] - 1);
            } else {
                nxt[i] = n - 1;
            }
            j = std::lower_bound(pos_1.begin(), pos_1.end(), i) - pos_1.begin();
            if(j + k < pos_1.size()) {
                nxt[i] = std::max(nxt[i], pos_1[j + k] - 1);
            } else {
                nxt[i] = n - 1;
            }
        }
        
        for(int i = 0; i < n; i++) {
            int len = nxt[i] - i + 1;
            psum[i + 1] = psum[i] + len;
        }
        
        auto bs = [&](int l, int r) {
            int lo = l;
            int hi = r;
            int res = -1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(nxt[mid] > r) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            return res;
        };
        
        for(int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            int j = bs(l, r);
            int64_t cnt = 0;
            if(j == -1) {
                cnt = psum[r + 1] - psum[l];
            } else {
                cnt = psum[j] - psum[l] + int64_t(1 + r - j + 1) * (r - j + 1) / 2;
                
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
