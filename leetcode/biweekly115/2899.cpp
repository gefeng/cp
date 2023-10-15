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
    std::vector<int> lastVisitedIntegers(std::vector<std::string>& words) {
        std::vector<int> a;
        std::vector<int> ans;
        
        int cnt = 0;
        for(std::string& s : words) {
            if(s == "prev") {
                cnt += 1;
                if(cnt > a.size()) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(a[a.size() - cnt]);
                }
            } else {
                cnt = 0;
                a.push_back(stoi(s));
            }
        }
        
        return ans;
    }
};
