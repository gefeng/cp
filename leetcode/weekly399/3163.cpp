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
    std::string compressedString(std::string word) {
        int n = word.size();
        std::string ans = "";
    
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && i - j < 9 && word[i] == word[j]) {
                i += 1;
            }
            ans.append(std::to_string(i - j));
            ans.push_back(word[j]);
        }
        
        return ans;
    }
};
