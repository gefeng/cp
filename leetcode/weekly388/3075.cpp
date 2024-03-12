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
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        int n = happiness.size();
    
        std::sort(happiness.begin(), happiness.end(), std::greater<int>());
        
        int64_t ans = 0;
        int t = 0;
        for(int x : happiness) {
            ans += std::max(0, x - t);
            t += 1;
            if(t == k) {
                break;
            }
        }
        
        return ans;
    }
};
