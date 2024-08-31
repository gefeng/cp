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
    int generateKey(int num1, int num2, int num3) {
        std::string s1 = std::to_string(num1);
        std::string s2 = std::to_string(num2);
        std::string s3 = std::to_string(num3);
        
        std::vector<std::string> a = {s1, s2, s3};
        for(int i = 0; i < 3; i++) {
            while(a[i].size() < 4) {
                a[i] = "0" + a[i];
            }
        }
    
        std::string ans = "";
        for(int i = 3; i >= 0; i--) {
            char c = '9';
            for(int j = 0; j < 3; j++) {
                c = std::min(c, a[j][i]);
            }
            ans.push_back(c);
        }
        
        std::reverse(ans.begin(), ans.end());
        
        return std::stoi(ans);
    }
};
