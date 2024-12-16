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
    int buttonWithLongestTime(std::vector<std::vector<int>>& events) {
        int n = events.size();
        int ans = 0;
        
        std::map<int, int> m;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                m[events[i][0]] = std::max(m[events[i][0]], events[i][1]);
            } else {
                m[events[i][0]] = std::max(m[events[i][0]], events[i][1] - events[i - 1][1]);
            }
        }
        
        int max_t = 0;
        int max_i = -1;
        for(auto [i, t] : m) {
            if(t > max_t) {
                max_t = t;
                max_i = i;
            } else if(t == max_t) {
                max_i = std::min(max_i, i);
            }
        }
        
        return max_i;
    }
};
