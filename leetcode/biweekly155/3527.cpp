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
    std::string findCommonResponse(std::vector<std::vector<std::string>>& responses) {
        int n = responses.size();
        std::map<std::string, int> m;
        for(int i = 0; i < n; i++) {
            std::set<std::string> seen;
            for(auto& s : responses[i]) {
                seen.insert(s);
            }
            for(auto& s : seen) {
                m[s] += 1;
            }
        }
        
        int max_f = 0;
        std::string ans = "";
        for(auto& [s, f] : m) {
            if(f > max_f) {
                max_f = f;
                ans = s;
            } else if(f == max_f) {
                ans = std::min(ans, s);
            }
        }
        
        return ans;
    }
};
