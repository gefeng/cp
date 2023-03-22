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
    int maximizeGreatness(vector<int>& nums) {
        map<int, int> m;
        for(int x : nums) {
            m[x] += 1;
        }
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for(int x : nums) {
            auto it = m.upper_bound(x);
            if(it == m.end()) {
                break;
            }
            
            ans += 1;
            if(it->second == 1) {
                m.erase(it);
            } else {
                it->second -= 1;
            }
        }
        
        return ans;
    }
};
