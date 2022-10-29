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
    int destroyTargets(vector<int>& nums, int space) {
        int ans = 1e9;
        
        unordered_map<int, int> m;
        int max_f = 0;
        for(int x : nums) {
            m[x % space] += 1;
            max_f = max(max_f, m[x % space]);
        }
    
        for(int x : nums) {
            if(m[x % space] == max_f) {
                ans = min(ans, x);            
            }
        }
        
        return ans;
    }
};
