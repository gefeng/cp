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
    std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
        std::vector<int> ans;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            std::string& s = words[i];
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
