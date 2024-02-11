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
    int maxPalindromesAfterOperations(std::vector<std::string>& words) {
        int ans = 0;
        int n = words.size();
        
        std::sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
            return a.size() < b.size();
        });
        
        std::array<int, 26> freq = {};
        
        for(std::string& s : words) {
            for(char c : s) {
                freq[c - 'a'] += 1;
            }
        }
        
        for(int i = 0; i < n; i++) {
            int m = words[i].size();
            int need = m / 2;
            
            for(int j = 0; j < 26; j++) {
                int take = std::min(freq[j] % 2 == 0 ? freq[j] : freq[j] - 1, need * 2);
                freq[j] -= take;
                need -= take / 2;
            }
            
            if(need == 0) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
