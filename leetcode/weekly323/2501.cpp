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
    using LL = long long;
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> m;
        for(int x : nums) {
            m[x] += 1;
        }
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        int n =  nums.size();
        for(int i = 0; i < n; i++) {
            if(m.find(nums[i]) == m.end()) {
                continue;
            }
            
            LL x = nums[i];
            int len = 0;
            while(m.find(x) != m.end()) {
                if(--m[x] == 0) {
                    m.erase(x);
                }
                
                len += 1;
                
                x = x * x;
            }
            ans = max(ans, len);
        }
        
        if(ans <= 1) {
            return -1;
        }
        return ans;
    }
};
