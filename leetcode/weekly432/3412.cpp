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
    long long calculateScore(std::string s) {
        int n = s.size();
        int64_t ans = 0;
        
        std::vector<std::set<int>> pos(26);
        for(int i = 0; i < n; i++) {
            pos[s[i] - 'a'].insert(i);
        }
        
        for(int i = 0; i < n; i++) {
            int c = 25 - (s[i] - 'a');
            auto it = pos[c].upper_bound(i);
            if(it == pos[c].begin()) {
                continue;
            }
            it--;
            ans += i - *it;
            pos[c].erase(it);
            pos[s[i] - 'a'].erase(i);
        }
        
        return ans;
    }
};
