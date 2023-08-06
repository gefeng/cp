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

class Solution {
public:
    long long findMaximumElegance(std::vector<std::vector<int>>& items, int k) {
        int n = items.size();
        
        std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
            return a[0] > b[0];
        });
        
        auto cmp = [](const auto& a, const auto& b) {
            return a.first > b.first;
        };
        
        std::set<int> have;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
        
        int64_t ans = 0;
        int64_t sum = 0;
        int64_t cnt = 0;
        int64_t profit = 0;
        for(int i = 0; i < n; i++) {
            auto item = items[i];
            int v = item[0];
            int t = item[1];
            
            if(i < k) {
                sum += v;
                if(have.find(t) == have.end()) {
                    cnt += 1;
                    have.insert(t);
                } else {
                    pq.emplace(v, t);
                }
                profit = sum + cnt * cnt;
            } else {
                if(!pq.empty() && have.find(t) == have.end()) {
                    auto [x, y] = pq.top();
                    pq.pop();
                    sum += v - x;
                    cnt += 1;

                    have.insert(t);

                    profit = sum + cnt * cnt;
                }   
            }
            ans = std::max(ans, profit);
        }
        
        return ans;
    }
};
