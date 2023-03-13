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
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        LL ans = 0LL;
        
        map<int, int> m;
        m[0] += 1;
        int mask = 0;
        for(int i = 0; i < n; i++) {
            mask ^= nums[i];
            
            if(m.find(mask) != m.end()) {
                ans += m[mask];
            }
            
            m[mask] += 1;
        }
        
        return ans;
    }
};
