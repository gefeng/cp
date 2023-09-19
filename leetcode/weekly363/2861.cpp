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
    int maxNumberOfAlloys(int n, int k, int budget, std::vector<std::vector<int>>& composition, std::vector<int>& stock, std::vector<int>& cost) {
        int ans = 0;
        
        for(int i = 0; i < k; i++) {
            int lo = 0;
            int hi = 1e9;
            int res = 0;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                
                int64_t sum = 0;
                for(int j = 0; j < n; j++) {
                    int64_t need = std::max((int64_t)0, (int64_t)composition[i][j] * mid - stock[j]);
                    
                    sum += need * cost[j];
                }
                
                if(sum <= budget) {
                    res = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            ans = std::max(ans, res);
        }
        
        return ans;
    }
};
