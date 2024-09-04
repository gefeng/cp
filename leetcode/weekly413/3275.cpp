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
    std::vector<int> resultsArray(std::vector<std::vector<int>>& queries, int k) {
        int n = queries.size();
        std::vector<int> ans(n);
        std::priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            pq.push(std::abs(x) + std::abs(y));
            if(pq.size() > k) {
                pq.pop();
            }
            ans[i] = pq.size() < k ? -1 : pq.top();
        }
        
        return ans;
    }
};
