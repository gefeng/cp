#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <set>

constexpr int INF = (int)2e9;

class Solution {
public:
    std::vector<int> minReverseOperations(int n, int p, std::vector<int>& banned, int k) {
        std::vector<int> ans(n, INF);
        
        std::vector<bool> ban(n, false);
        std::vector<std::set<int>> good(2);
        for(int pos : banned) {
            ban[pos] = true;
        }
        
        //k = eve  +1 +3 +5
        //k = odd  +2 +4 +6
        for(int i = 0; i < n; i++) {
            if(!ban[i] && i != p) {
                good[i & 1].insert(i);
            }
        }
        
        auto is_valid = [&](int pre, int cur) {
            if(k % 2 == 0) {
                int mid = (pre + cur) >> 1;
                if(mid + k / 2 > n - 1 || mid - (k / 2) + 1 < 0) {
                    return false;
                }
            } else {
                int mid = (pre + cur) >> 1;
                if(mid + k / 2 > n - 1 || mid - k / 2 < 0) {
                    return false;
                }
            }
            
            return cur >= 0 && cur < n && !ban[cur];
        };
        
        std::queue<int> q;
        q.push(p);
        ans[p] = 0;
        
        int d = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int x = q.front();
                q.pop();
                
                int l = x - (k - 1);
                int r = x + (k - 1);
                if(x < k) {
                    l = k - (x + 1);
                }
                if(n - x - 1 < k) {
                    r = n - k + n - x - 1;
                }
                
                std::set<int>& s = good[k % 2 == 0 ? (x & 1) ^ 1 : (x & 1)];
                
                auto it = s.lower_bound(l);
                std::vector<int> remove;
                while(it != s.end() && *it <= r) {
                    q.push(*it);
                    ans[*it] = d;
                    remove.push_back(*it);
                    it++;
                }
                
                for(int pos : remove) {
                    s.erase(pos);
                }
            }
            d += 1;
        }
        
        for(int i = 0; i < n; i++) {
            if(ans[i] == INF) {
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};
