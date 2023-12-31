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
    int maximumLength(std::string s) {
        int max_v = 0;
        int n = s.size();
        
        std::vector<std::vector<int>> cnt(26, std::vector<int>(n + 1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n && s[i] == s[j]; j++) {
                cnt[s[j] - 'a'][j - i + 1] += 1;
            }
        }
        
        int ans = -1;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j <= n; j++) {
                if(cnt[i][j] >= 3) {
                    ans = std::max(ans, j);
                }
            }
        }
        
        return ans;
    }
};
