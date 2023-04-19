#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:
    int maximumCostSubstring(std::string s, std::string chars, std::vector<int>& vals) {
        int n = s.size();
        std::vector<int> v(n);
        std::vector<int> cost(26);
        
        for(int i = 0; i < 26; i++) {
            cost[i] = i + 1;
        }
        
        for(int i = 0; i < chars.size(); i++) {
            cost[chars[i] - 'a'] = vals[i];
        }
        
        for(int i = 0; i < n; i++) {
            v[i] = cost[s[i] - 'a'];
        }
        
        int max_v = -INF;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += v[i];
            max_v = std::max(max_v, sum);
            sum = std::max(0, sum);
        }
        
        return std::max(0, max_v);
    }
};
