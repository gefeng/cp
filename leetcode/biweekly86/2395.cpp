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
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        
        for(int i = 0; i < n - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if(seen.find(sum) != seen.end()) {
                return true;
            }
            seen.insert(sum);
        }
        
        return false;
    }
};
