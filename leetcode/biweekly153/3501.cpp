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

class Solution {
public:
    std::vector<int> maxActiveSectionsAfterTrade(std::string s, std::vector<std::vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        std::vector<int> ans(m, 0);
        
        std::vector<std::pair<int, int>> seg;
        int active = 0;
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && s[i] == s[j]) {
                i += 1;
            }
            if(s[j] == '1') {
                active += i - j;
            }
            seg.emplace_back(j, i - 1);
        }
        
        int size = seg.size();
        // pre-calculate sparse table for rmq
        std::vector<std::vector<int>> st(LOG + 1, std::vector<int>(size, 0));
        for(int j = 0; j < size; j++) {
            auto [l, r] = seg[j];
            if(s[l] == '0' && j + 2 < size) {
                st[0][j] = r - l + 1 + seg[j + 2].second - seg[j + 2].first + 1;
            }
        }
        
        for(int i = 1; i <= LOG; i++) {
            for(int j = 0; j < size; j++) {
                if(j + (1 << (i - 1)) < size) {
                    st[i][j] = std::max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                }
            }
        }
        
        auto which_seg = [&](int i) {
            int lo = 0;
            int hi = size - 1;
            int res = -1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                auto [l, r] = seg[mid];
                if(i >= l && i <= r) {
                    res = mid;
                    break;
                }
                if(i > r) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            return res;
        };
        
        auto query = [&](int l, int r) {
            if(l > r) {
                return 0;
            }
            
            int i = 0;
            int p_2 = 1;
            while(p_2 <= r - l + 1) {
                p_2 *= 2;
                i += 1;
            }
            i -= 1;
            
            return std::max(st[i][l], st[i][r - (1 << i) + 1]);
        };
        
        for(int i = 0; i < m; i++) {
            int q_l = queries[i][0];
            int q_r = queries[i][1];
            
            int l = which_seg(q_l);
            int r = which_seg(q_r);
        
            if(r - l <= 1) {
                ans[i] = active;
                continue;
            }
            
            if(s[seg[l].first] == '0') {
                ans[i] = std::max(ans[i], active + seg[l].second - q_l + 1 + (r - l > 2 ? seg[l + 2].second - seg[l + 2].first + 1 : q_r - seg[l + 2].first + 1));
            }
            
            if(s[seg[r].first] == '0') {
                ans[i] = std::max(ans[i], active + q_r - seg[r].first + 1 + (r - l > 2 ? seg[r - 2].second - seg[r - 2].first + 1 : seg[r - 2].second - q_l + 1));
            }
            
            ans[i] = std::max(ans[i], active + query(l + 1, r - 3));
        }
        
        return ans;
    }
};
