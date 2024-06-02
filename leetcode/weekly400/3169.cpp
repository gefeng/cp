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
    int countDays(int days, std::vector<std::vector<int>>& meetings) {
        int n = meetings.size();
        int ans = 0;
        
        std::sort(meetings.begin(), meetings.end());
        
        int last = 0;
        for(int i = 0; i < n; i++) {
            int l = meetings[i][0];
            int r = meetings[i][1];
            if(l <= last) {
                last = std::max(r, last);
            } else {
                ans += l - last - 1;
                last = r;
            }
        }
        return ans + days - last;
    }
};
