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
    int minimumChairs(std::string s) {
        int cnt = 0;
        int ans = 0;
        for(char c : s) {
            if(c == 'E') {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            ans = std::max(ans, cnt);
        }
        
        return ans;
    }
};
