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
    std::string minimizeStringValue(std::string s) {
        int n = s.size();
        
        std::vector<std::vector<int>> suffix(n, std::vector<int>(26, 0));

        for(int i = n - 1; i >= 0; i--) {
            if(i < n - 1) {
                for(int j = 0; j < 26; j++) {
                    suffix[i][j] = suffix[i + 1][j];
                }            
                if(s[i + 1] != '?') {
                    suffix[i][s[i + 1] - 'a'] += 1;
                }
            }
        }
        
        std::array<int, 26> cnt = {};
        std::vector<int> replace;

        for(int i = 0; i < n; i++) {
            if(s[i] != '?') {
                cnt[s[i] - 'a'] += 1;
            } else {
                int min_d = INF;
                int c = 0;
                for(int j = 0; j < 26; j++) {
                    int delta = cnt[j] + suffix[i][j];
                    if(delta < min_d) {
                        min_d = delta;
                        c = j;
                    }
                }
                cnt[c] += 1;
                replace.push_back(c);
            }
        }
        
        std::sort(replace.begin(), replace.end());
        
        for(int i = 0, j = 0; i < n; i++) {
            if(s[i] == '?') {
                s[i] = (char)(replace[j++] + 'a');
            }
        }
        
        return s;
    }
};
