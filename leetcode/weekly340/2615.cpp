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
    std::vector<long long> distance(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<LL> ans(n, 0LL);
        
        std::map<int, LL> sum_m;
        std::map<int, int> cnt_m;
        
        for(int i = 0; i < n; i++) {
            int v = nums[i];
            if(cnt_m.find(v) != cnt_m.end()) {
                LL sum = sum_m[v];
                int cnt = cnt_m[v];
                
                ans[i] += 1LL * cnt * i - sum;
            }
            
            cnt_m[v] += 1;
            sum_m[v] += i;
        }
        
        sum_m = std::map<int, LL>();
        cnt_m = std::map<int, int>();
        for(int i = n - 1; i >= 0; i--) {
            int v = nums[i];
            if(cnt_m.find(v) != cnt_m.end()) {
                LL sum = sum_m[v];
                int cnt = cnt_m[v];
                
                ans[i] += sum - 1LL * cnt * i;
            }
            
            cnt_m[v] += 1;
            sum_m[v] += i;
        }
        
        return ans;
    }
};
