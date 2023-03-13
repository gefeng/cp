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
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        int ans = 0;
        LL sum = 0LL;
        for(int x : nums) {
            sum += x;
            if(sum <= 0) {
                break;
            }
            ans += 1;
        }
        
        return ans;
    }
};
