#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
    
        int lo = 0;
        int hi = (int)1e9;
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + hi >> 1;

            if(is_ok(stones, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
    
    bool is_ok(vector<int>& stones, int mid) {
        int n = stones.size();
        bool ok = true;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; ) {
            int j = i;
            while(i + 1 < n && stones[i + 1] - stones[j] <= mid) {
                i += 1;
            }
            
            if(i == n - 1) {
                break;
            }
            
            if(i == j) {
                ok = false;
                break;
            }

            if(i != 0 || i != n - 1) {
                vis[i] = true;
            }
        }

        if(ok) {
            int pre = 0;
            for(int i = 1; i < n; i++) {
                if(!vis[i]) {
                    if(stones[i] - pre > mid) {
                        ok = false;
                        break;
                    }
                    pre = stones[i];
                }
            }
        }
        return ok;
    }
};
