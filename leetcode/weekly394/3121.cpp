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
    int numberOfSpecialChars(std::string word) {
        int ans = 0;
        int n = word.size();
        std::vector<int> last(26, -1);
        std::vector<int> first(26, -1);
        
        for(int i = 0; i < n; i++) {
            char c = word[i];
            if(c >= 'a' && c <= 'z') {
                last[c - 'a'] = i;
            } else {
                first[c - 'A'] = first[c - 'A'] == -1 ? i : first[c - 'A'];
            }
        }
        
        for(int i = 0; i < 26; i++) {
            if(last[i] != -1 && first[i] != -1 && last[i] < first[i]) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
