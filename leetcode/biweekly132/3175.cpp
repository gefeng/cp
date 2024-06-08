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
    int findWinningPlayer(std::vector<int>& skills, int k) {
        int ans = -1;
        int n = skills.size();
        
        for(int i = 0; i < n; i++) {
            int j = i;
            while(i + 1 < n && skills[i + 1] < skills[j]) {
                i += 1;
            }
            int cnt = j == 0 ? i - j : i - j + 1;
            if(cnt >= k) {
                ans = j;
                break;
            }
        }
        
        if(ans == -1) {
            ans = std::max_element(skills.begin(), skills.end()) - skills.begin();
        }
        
        return ans;
    }
};
