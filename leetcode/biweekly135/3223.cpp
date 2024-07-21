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
    int minimumLength(std::string s) {
        std::array<int, 26> freq = {};
        
        for(char c : s) {
            freq[c - 'a'] += 1;
        }
        
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            ans += freq[i] % 2 == 1 ? std::min(1, freq[i]) : std::min(2, freq[i]);
        }
        
        return ans;
    }
};
