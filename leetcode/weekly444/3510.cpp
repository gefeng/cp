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
    int minimumPairRemoval(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        std::vector<int64_t> a(nums.begin(), nums.end());
        std::vector<int> nxt(n, -1);
        std::vector<int> pre(n, -1);
        std::set<int> inv;
        std::multiset<std::pair<int64_t, int>> ms;
        
        for(int i = 0; i < n; i++) {
            nxt[i] = i + 1;
            pre[i] = i - 1;
        }
        
        for(int i = 0; i < n - 1; i++) {
            if(a[i + 1] < a[i]) {
                inv.insert(i);
            }
            ms.emplace(a[i] + a[i + 1], i);
        }
        
        while(!inv.empty()) {
            auto [sum, i] = *ms.begin();
            ms.erase(ms.begin());
            
            if(inv.find(i) != inv.end()) {
                inv.erase(i);
            }
            
            int j = nxt[i];
            int l = pre[i];
            int r = nxt[j];
            if(l != -1) {
                nxt[l] = i;
                ms.erase({a[l] + a[i], l});
                if(inv.find(l) != inv.end()) {
                    inv.erase(l);
                }
                ms.emplace(a[l] + sum, l);
                if(sum < a[l]) {
                    inv.insert(l);
                }
            }
            
            if(r != n) {
                pre[r] = i;
                ms.erase({a[j] + a[r], j});
                if(inv.find(j) != inv.end()) {
                    inv.erase(j);
                }
                ms.emplace(sum + a[r], i);
                if(sum > a[r]) {
                    inv.insert(i);
                }
            }
            a[i] = sum;
            pre[i] = l;
            nxt[i] = r;
            ans += 1;
        }
        
        return ans;
    }
};
