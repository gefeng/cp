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
    int findMaxK(vector<int>& nums) {
        set<int> seen;
        for(int x : nums) {
            if(x < 0) {
                seen.insert(x);
            }
        }
        
        int ans = -1;
        for(int x : nums) {
            if(x > 0 && seen.find(-x) != seen.end()) {
                ans = max(ans, x);
            }
        }
        
        return ans;
    }
};
