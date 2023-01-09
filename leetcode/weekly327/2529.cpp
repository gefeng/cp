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
    int maximumCount(vector<int>& nums) {
        int cnt_1 = 0;
        int cnt_2 = 0;
        for(int x : nums) {
            if(x < 0) {
                cnt_1 += 1;
            }
            if(x > 0) {
                cnt_2 += 1;
            }
        }
        return max(cnt_1, cnt_2);
    }
};
