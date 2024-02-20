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
    std::string lastNonEmptyString(std::string s) {
        int n = s.size();
        std::array<int, 26> last = {};
        std::array<int, 26> freq = {};
        for(int i = 0; i < 26; i++) {
            last[i] = -1;
        }
        
        int max_f = 0;
        for(int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
            freq[s[i] - 'a'] += 1;
            max_f = std::max(max_f, freq[s[i] - 'a']);
        }
        
        for(int i = 0; i < 26; i++) {
            if(freq[i] != max_f) {
                last[i] = -1;
            }
        }
        
        std::string ans = "";
        while(true) {
            int min_v = n + 1;
            int c = -1;
            for(int j = 0; j < 26; j++) {
                if(last[j] != -1 && min_v > last[j]) {
                    min_v = last[j];
                    c = j;
                }
            }
            if(c == -1) {
                break;
            }
            
            ans.push_back((char)(c + 'a'));
            last[c] = -1;
        }
        
        return ans;
    }
};
