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
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        set<int> s;
        for(int l = 0, r = n - 1; l < r; l++, r--) {
            s.insert(nums[l] + nums[r]);
        }
        
        return s.size();
    }
};
