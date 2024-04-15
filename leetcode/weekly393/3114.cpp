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
    std::string findLatestTime(std::string s) {
        int max_t = 11 * 60 + 59;
        
        auto to_string = [](int t) {
            int h = t / 60;
            int m = t % 60;
            std::string res = "";
            if(h < 10) {
                res.push_back('0');
                res.push_back((char)(h + '0'));
            } else {
                res.append(std::to_string(h));
            }
            
            res.push_back(':');
            
            if(m < 10) {
                res.push_back('0');
                res.push_back((char)(m + '0'));
            } else {
                res.append(std::to_string(m));
            }
            
            return res;
        };
        
        std::string ans = "";
        for(int t = max_t; t >= 0; t--) {
            std::string ts = to_string(t);
            bool ok = true;
            for(int i = 0; i < 5; i++) {
                if(s[i] != ts[i] && s[i] != '?') {
                    ok = false;
                    break;
                }
            }
            
            if(ok) {
                ans = ts;
                break;
            }
        }
        
        return ans;
    }
};
