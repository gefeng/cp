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
    std::string minimumString(std::string a, std::string b, std::string c) {
        std::array<std::string, 3> s = {a, b, c};
        std::sort(s.begin(), s.end());
        
        std::string ans = "";
        do {
            std::string cand = s[0];
            
            for(int i = 1; i < 3; i++) {
                std::string t = s[i];

                if(cand.find(t) != std::string::npos) {
                    continue;
                }

                int n = cand.size();
                bool found = false;
                for(int j = n; j > 0; j--) {
                    std::string suffix = cand.substr(n - j, j);
                    if(t.find(suffix) != std::string::npos && t.find(suffix) == 0) {
                        cand.append(t.substr(j, t.size() - j));
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cand.append(t);
                }
            }
            
            if(ans.empty()) {
                ans = cand;
            } else {
                if(cand.size() < ans.size()) {
                    ans = cand;
                } else if(cand.size() == ans.size()) {
                    ans = std::min(ans, cand);
                }
            }
        } while(next_permutation(s.begin(), s.end()));
        
        
        
        return ans;
    }
};
