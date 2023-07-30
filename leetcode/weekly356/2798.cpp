#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(std::vector<int>& hours, int target) {
        int ans = 0;
        for(int x : hours) {
            if(x >= target) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
