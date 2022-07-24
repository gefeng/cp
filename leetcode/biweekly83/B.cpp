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
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cnt = 0;
        for(int x : nums) {
            if(x) {
                cnt = 0;
            } else {
                cnt++;
            }
            ans += cnt;
        }

        return ans;    
    }
};
