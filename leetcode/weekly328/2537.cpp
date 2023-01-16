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
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        LL cnt = 0LL;
        LL ans = 0LL;
        for(int l = 0, r = 0; r < n; r++) {
            m[nums[r]] += 1;
            cnt += m[nums[r]] - 1;
            while(cnt >= k) {
                ans += n - r;
                cnt -= m[nums[l]] - 1;
                if(--m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l += 1; 
            }
        }
        
        return ans;
    }
};
