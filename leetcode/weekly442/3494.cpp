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
    long long minTime(std::vector<int>& skill, std::vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        
        std::vector<int64_t> pre(n, 0);
        for(int i = 0; i < m; i++) {
            if(i == 0) {
                int64_t t = 0;
                for(int j = 0; j < n; j++) {
                    t += skill[j] * mana[i];
                    pre[j] = t;
                }
            } else {
                std::vector<int64_t> nxt(n, 0);
                int64_t t = 0;
                int64_t st = 0;
                for(int j = 0; j < n; j++) {
                    if(t < pre[j]) {
                        st += pre[j] - t;
                        t = pre[j];
                    }
                    t += skill[j] * mana[i];
                }
                t = st;
                for(int j = 0; j < n; j++) {
                    t += skill[j] * mana[i];
                    nxt[j] = t;
                }
                std::swap(nxt, pre);
            }
        }
        
        return pre.back();
    }
};
