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
    std::vector<long long> unmarkedSumArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        std::vector<long long> ans;
        int n = nums.size();
        int m = queries.size();
        
        std::vector<std::pair<int, int>> a(n);
        std::vector<int> vis(n, 0);
        int64_t sum = 0;
        for(int i = 0; i < n; i++) {
            a[i] = {nums[i], i};
            sum += nums[i];
        }
        
        std::sort(a.begin(), a.end());
        
        for(int i = 0, j = 0; i < m; i++) {
            int idx = queries[i][0];
            int k = queries[i][1];
            
            if(!vis[idx]) {
                vis[idx] = 1;
                sum -= nums[idx];
            }
            
            while(k) {
                if(j < n) {
                    if(!vis[a[j].second]) {
                        sum -= a[j].first;
                        vis[a[j].second] = 1;
                        k -= 1;
                    }
                    j += 1;
                } else {
                    break;
                }
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};
