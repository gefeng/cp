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
    int minimumOperationsToMakeKPeriodic(std::string word, int k) {
        int n = word.size();
        int ans = n;
        
        std::map<std::string, int> m;
        for(int i = 0; i < n; i += k) {
            m[word.substr(i, k)] += 1;
        }
        
        for(auto& [_, f] : m) {
            ans = std::min(ans, n / k - f);
        }
        
        return ans;
    }
};
