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
    int removeAlmostEqualCharacters(std::string word) {
        int ans = 0;
        int n = word.size();
        
        for(int i = 0; i < n; i++) {
            int j = i;
            while(i + 1 < n && std::abs(word[i + 1] - word[i]) <= 1) {
                i += 1;
            }
            
            int len = i - j + 1;
            ans += len / 2;
        }
        
        return ans;
    }
};
