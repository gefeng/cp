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
    std::vector<int> survivedRobotsHealths(std::vector<int>& positions, std::vector<int>& healths, std::string directions) {
        int n = positions.size();
        std::vector<int> ans;
        
        std::vector<std::array<int, 4>> v(n);
        for(int i = 0; i < n; i++) {
            v[i][0] = positions[i];
            v[i][1] = directions[i] == 'L' ? 0 : 1;
            v[i][2] = healths[i];
            v[i][3] = i;
        }
        
        std::sort(v.begin(), v.end());
        
        std::vector<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && v[s.back()][1] == 1 && v[i][1] == 0) {
                if(healths[v[s.back()][3]] == healths[v[i][3]]) {
                    healths[v[s.back()][3]] = 0;
                    healths[v[i][3]] = 0;
                    s.pop_back();
                    break;
                } else if(healths[v[s.back()][3]] > healths[v[i][3]]) {
                    healths[v[i][3]] = 0;
                    if(--healths[v[s.back()][3]] == 0) {
                        s.pop_back();
                    }
                    break;
                } else {
                    healths[v[s.back()][3]] = 0;
                    s.pop_back();
                    if(--healths[v[i][3]] == 0) {
                        break;
                    }
                }
            }
            
            if(healths[v[i][3]]) {
                s.push_back(i);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        
        return ans;
    }
};
