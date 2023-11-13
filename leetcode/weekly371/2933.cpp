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
    std::vector<std::string> findHighAccessEmployees(std::vector<std::vector<std::string>>& access_times) {
        std::map<std::string, std::vector<int>> m;
        for(auto& x : access_times) {
            m[x[0]].push_back(std::stoi(x[1].substr(0, 2)) * 60 + std::stoi(x[1].substr(2, 2)));
        }
        
        std::vector<std::string> ans;
        for(auto& [name, t] : m) {
            std::sort(t.begin(), t.end());
            
            int size = t.size();
            for(int i = 0; i < size; i++) {
                int j = i;
                while(j < size && t[j] - t[i] < 60) {
                    j += 1;
                }
                if(j - i >= 3) {
                    ans.push_back(name);
                    break;
                }
            }
        }
        
        return ans;
    }
};
