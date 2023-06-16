#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;

class Solution {
public:
    long long matrixSumQueries(int n, std::vector<std::vector<int>>& queries) {
        std::vector<std::pair<int, int>> row(n, {-1, 0});
        std::vector<std::pair<int, int>> col(n, {-1, 0});
        
        int m = queries.size();
        LL ans = 0LL;
        std::set<int> sr;
        std::set<int> sc;
        for(int i = m - 1; i >= 0; i--) {
            if(queries[i][0] == 0) {
                int r = queries[i][1];
                int v = queries[i][2];
                
                if(sr.find(r) == sr.end()) {
                    ans += 1LL * (n - sc.size()) * v;
                    sr.insert(r);
                }
            } else {
                int c = queries[i][1];
                int v = queries[i][2];
                
                if(sc.find(c) == sc.end()) {
                    ans += 1LL * (n - sr.size()) * v;
                    sc.insert(c);
                }
            }
        }
        
        return ans;
    }
};
