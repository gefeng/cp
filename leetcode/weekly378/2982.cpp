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
        
        std::vector<std::vector<int>> cnt(26, std::vector<int>(n + 2, 0));
        for(int i = 0; i < n;) {
            int j = i; 
            int c = s[j] - 'a';
            while(i < n && s[j] == s[i]) {
                cnt[c][1] += 1;
                cnt[c][i - j + 2] -= 1;
                i += 1;
            }
        }
        
        int ans = -1;
        for(int i = 0; i < 26; i++) {
            int sum = 0;
            for(int j = 0; j <= n; j++) {
                sum += cnt[i][j];
                if(sum >= 3) {
                    ans = std::max(ans, j);
                }
            }
        }
        
        return ans;
    }
};
