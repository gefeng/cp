#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        LL ans = 0LL;
        int n = basket1.size();
        
        map<int, int> m1;
        map<int, int> m2;
        int min_v = (int)1e9;
        for(int i = 0; i < n; i++) {
            m1[basket1[i]] += 1;
            m2[basket2[i]] += 1;
            min_v = min(min_v, basket1[i]);
            min_v = min(min_v, basket2[i]);
        }
        
        for(int x : basket1) {
            if(m1.find(x) != m1.end() && m2.find(x) != m2.end()) {
                int d = min(m1[x], m2[x]);
                if(m1[x] == d) {
                    m1.erase(x);
                } else {
                    m1[x] -= d;
                }
                if(m2[x] == d) {
                    m2.erase(x);
                } else {
                    m2[x] -= d;
                }
            }
        }
        
        for(auto& [k, v] : m1) {
            if(v % 2 == 1) {
                return -1LL;
            }
        }
        
        for(auto& [k, v] : m2) {
            if(v % 2 == 1) {
                return -1LL;
            }
        }
        
        if(m1.empty() && m2.empty()) {
            return 0LL;
        }
        if(m1.empty() || m2.empty()) {
            return -1LL;
        }
        
        while(!m1.empty() && !m2.empty()) {
            if(m1.begin()->first < m2.begin()->first) {
                auto it1 = m1.begin();
                auto it2 = m2.end();
                it2--;
                int x = it1->second;
                int y = it2->second;
                
                int d = min(x / 2, y / 2);

                LL cost = min(2LL * min_v * d, 1LL * it1->first * d);
                
                if(it1->second == d * 2) {
                    m1.erase(it1);
                } else {
                    it1->second -= d * 2;
                }
                if(it2->second == d * 2) {
                    m2.erase(it2);
                } else {
                    it2->second -= d * 2;
                }
                
                ans += cost;
            } else {
                auto it1 = m1.end();
                auto it2 = m2.begin();
                it1--;
                int x = it1->second;
                int y = it2->second;
                
                int d = min(x / 2, y / 2);

                LL cost = min(2LL * min_v * d, 1LL * it2->first * d);
                
                if(it1->second == d * 2) {
                    m1.erase(it1);
                } else {
                    it1->second -= d * 2;
                }
                if(it2->second == d * 2) {
                    m2.erase(it2);
                } else {
                    it2->second -= d * 2;
                }
                
                ans += cost;
            }
        }
        
        return ans;
    }
};
