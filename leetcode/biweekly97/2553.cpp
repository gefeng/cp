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
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        
        int pre = 0;
        for(int x : nums) {
            while(x) {
                ans.push_back(x % 10);
                x /= 10;
            }
            
            reverse(ans.begin() + pre, ans.end());
            
            pre = ans.size();
        }
        
        return ans;
    }
};
