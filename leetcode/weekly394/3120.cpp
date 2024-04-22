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
        std::array<int, 26> cnt1{};
        std::array<int, 26> cnt2{};
        for(char c : word) {
            if(c >= 'a' && c <= 'z') {
                cnt1[c - 'a'] += 1;
            } else {
                cnt2[c - 'A'] += 1;
            }
        }
        
        for(int i = 0; i < 26; i++) {
            if(cnt1[i] && cnt2[i]) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
