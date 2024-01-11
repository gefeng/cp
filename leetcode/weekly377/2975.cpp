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
    int maximizeSquareArea(int m, int n, std::vector<int>& hFences, std::vector<int>& vFences) {
        std::sort(hFences.begin(), hFences.end());
        std::sort(vFences.begin(), vFences.end());
        
        std::set<int64_t> s;
        std::vector<int> v;
        std::vector<int> h;
        v.push_back(1);
        h.push_back(1);
        for(int i = 0; i < vFences.size(); i++) {
            v.push_back(vFences[i]);
        }
        
        for(int i = 0; i < hFences.size(); i++) {
            h.push_back(hFences[i]);
        }
        
        h.push_back(m);
        v.push_back(n);
                        
        for(int i = 0; i < v.size(); i++) {
            for(int j = i + 1; j < v.size(); j++) {
                s.insert(v[j] - v[i]);
            }
        }
        
        int64_t ans = -1;
        for(int i = 0; i < h.size(); i++) {
            for(int j = i + 1; j < h.size(); j++) {
                int64_t x = h[j] - h[i];
                if(s.find(x) != s.end()) {
                    ans = std::max(ans, x * x);
                }
            }
        }
        
        ans %= (int64_t)1e9 + 7;
        return ans;
    }
};
