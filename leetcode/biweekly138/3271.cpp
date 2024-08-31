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
    std::string stringHash(std::string s, int k) {
        std::string ans = "";
        int n = s.size();
        
        for(int i = 0; i < n; i += k) {
            int sum = 0;
            for(int j = 0; j < k; j++) {
                sum += s[i + j] - 'a';
            }
            sum %= 26;
            ans.push_back((char)(sum + 'a'));
        }
        return ans;
    }
};
