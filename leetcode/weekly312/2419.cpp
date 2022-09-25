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
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_v = 0;
        
        for(int x : nums) {
            max_v = max(max_v, x);
        }
        
        int ans = 0;
        int cnt = 0;
        for(int x : nums) {
            if(x == max_v) {
                cnt++;
            } else {
                cnt = 0;
            }
            
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};
