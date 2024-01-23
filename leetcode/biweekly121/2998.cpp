#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

constexpr int MAX = (int)1e4;
constexpr int INF = (int)1e9;

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y >= x) {
            return y - x;
        }
        
        std::vector<int> mul11;
        std::vector<int> mul5;
        for(int i = 1, j = 5; i * j <= MAX + 100; i++) {
            mul5.push_back(j * i);
        }
        
        for(int i = 1, j = 11; i * j <= MAX + 100; i++) {
            mul11.push_back(j * i);
        }
        
        auto cmp = [](const auto& a, const auto& b) {
            return a.second > b.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.emplace(x, 0);
        std::vector<int> best(MAX + 100, INF);
        best[x] = 0;
        while(!pq.empty()) {
            auto [v, d] = pq.top();
            pq.pop();
            
            if(best[v] != d) {
                continue;
            }
            
            if(v == y) {
                break;
            }
            
            if(v < y) {
                best[y] = std::min(best[y], d + y - v);
            } else {
                int nv = y;
                int nd = d + v - y;
                if(best[nv] > nd) {
                    best[nv] = nd;
                    pq.emplace(nv, nd);
                }
                
                auto it = std::lower_bound(mul5.begin(), mul5.end(), v);
                nv = *it / 5;
                nd = d + std::abs(*it - v) + 1;
                if(best[nv] > nd) {
                    best[nv] = nd;
                    pq.emplace(nv, nd);
                }
                if(it != mul5.begin()) {
                    it--;
                    nv = *it / 5;
                    nd = d + std::abs(*it - v) + 1;
                    if(best[nv] > nd) {
                        best[nv] = nd;
                        pq.emplace(nv, nd);
                    }
                }
                
                it = std::lower_bound(mul11.begin(), mul11.end(), v);
                nv = *it / 11;
                nd = d + std::abs(*it - v) + 1;
                if(best[nv] > nd) {
                    best[nv] = nd;
                    pq.emplace(nv, nd);
                }
                if(it != mul11.begin()) {
                    it--;
                    nv = *it / 11;
                    nd = d + std::abs(*it - v) + 1;
                    if(best[nv] > nd) {
                        best[nv] = nd;
                        pq.emplace(nv, nd);
                    }
                }
            }
        }
        
        return best[y];
    }
};
