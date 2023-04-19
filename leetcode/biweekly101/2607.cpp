#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;

class Solution {
public:
    long long makeSubKSumEqual(std::vector<int>& arr, int k) {
        int n = arr.size();
        
        if(n == 1) {
            return 0;
        }
        if(k == n) {
            return 0;
        }
        
        LL ans = 0LL;
        std::vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(vis[i]) {
                continue;
            }
            
            int j = i;
            std::vector<int> v;
            while(!vis[j]) {
                vis[j] = true;
                v.push_back(arr[j]);
                j = (j + k) % n;
            }
            
            std::sort(v.begin(), v.end());
            for(int x : v) {
                ans += abs(x - v[v.size() / 2]);
            }
        }
        
        return ans;
    }
};
