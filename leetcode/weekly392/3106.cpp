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
    std::string getSmallestString(std::string s, int k) {
        std::string ans = "";
        int n = s.size();
        
        int dist = 0;
        for(int i = 0; i < n; i++) {
            int d = std::min(s[i] - 'a', 26 - s[i] + 'a');
            
            if(dist + d <= k) {
                ans.push_back('a');
                dist += d;
            } else {
                int c = std::min((s[i] - 'a' + k - dist) % 26, (s[i] - 'a' - k + dist + 26) % 26);
                ans.push_back((char)(c + 'a'));
                dist += k - dist;
            }
        }
        
        return ans;
    }
};
