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
    long long maximumSumOfHeights(std::vector<int>& maxHeights) {
        int64_t ans = 0;
        int n = maxHeights.size();
        
        std::vector<int> pre_smaller(n, -1);
        std::vector<int> nxt_smaller(n, n);
        std::vector<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && maxHeights[s.back()] > maxHeights[i]) {
                s.pop_back();
            }
            if(!s.empty()) {
                pre_smaller[i] = s.back();
            }
            s.push_back(i);
        }
        
        s = std::vector<int>();
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && maxHeights[s.back()] > maxHeights[i]) {
                s.pop_back();
            }
            if(!s.empty()) {
                nxt_smaller[i] = s.back();
            }
            s.push_back(i);
        }
        
        std::vector<int64_t> save_l(n, 0);
        std::vector<int64_t> save_r(n, 0);
        for(int i = 1; i < n; i++) {
            int l = pre_smaller[i];
            if(l == -1) {
                save_l[i] = (int64_t)i * maxHeights[i];
            } else {
                save_l[i] = (int64_t)(i - l - 1) * maxHeights[i] + save_l[l] + maxHeights[l];
            }
        }
        
        for(int i = n - 2; i >= 0; i--) {
            int r = nxt_smaller[i];
            if(r == n) {
                save_r[i] = (int64_t)(n - i - 1) * maxHeights[i];
            } else {
                save_r[i] = (int64_t)(r - i - 1) * maxHeights[i] + save_r[r] + maxHeights[r];
            }
        }
        
        for(int i = 0; i < n; i++) {
            ans = std::max(ans, save_l[i] + save_r[i] + maxHeights[i]);
        }
        
        return ans;
    }
};
