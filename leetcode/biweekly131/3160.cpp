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
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>>& queries) {
        int n = queries.size();
        std::map<int, int> m1;
        std::map<int, int> m2;
        std::vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            int x = queries[i][0];
            int c = queries[i][1];
            
            if(m1.find(x) == m1.end()) {
                m1[x] = c;
                m2[c] += 1;
            } else {
                int pc = m1[x];
                if(--m2[pc] == 0) {
                    m2.erase(pc);
                }
                m1[x] = c;
                m2[c] += 1;
            }
            
            ans[i] = m2.size();
        }
        
        return ans;
    }
};
