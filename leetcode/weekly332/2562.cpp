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
    long long findTheArrayConcVal(vector<int>& nums) {
        LL ans = 0LL;
        for(int l = 0, r = nums.size() - 1; l <= r; l += 1, r -= 1) {
            if(l == r) {
                ans += nums[l];
            } else {
                ans += stoi(to_string(nums[l]) + to_string(nums[r]));
            }
        }
        
        return ans;
    }
};
