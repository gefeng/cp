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
using LL = long long;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        
        LL sum = 0LL;
        LL ans = 0LL;
        for(int i = 0, j = 0; i < n; i++) {
            sum += nums[i];
            
            while(s.find(nums[i]) != s.end()) {
                s.erase(nums[j]);
                sum -= nums[j];
                j += 1;
            }
            
            while(i - j + 1 > k) {
                s.erase(nums[j]);
                sum -= nums[j];
                j += 1;
            }
            
            if(i - j + 1 == k) {
                ans = max(ans, sum);
            }
            
            s.insert(nums[i]);
        }
        
        return ans;
    }
};
