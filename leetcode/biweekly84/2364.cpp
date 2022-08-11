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
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            int d = nums[i] - i;
            long long cnt = map.count(d) ? map[d] : 0;
            ans += i - cnt;
            
            map[d] += 1;
        }
        
        return ans;
    }
};
