#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:
    int minimumSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    
        auto search = [&](int sr, int sc, int tr, int tc) {
            int min_r = INF;
            int max_r = 0;
            int min_c = INF;
            int max_c = 0;
            for(int r = sr; r <= tr; r++) {
                for(int c = sc; c <= tc; c++) {
                    if(grid[r][c] == 1) {
                        min_r = std::min(min_r, r);
                        max_r = std::max(max_r, r);
                        min_c = std::min(min_c, c);
                        max_c = std::max(max_c, c);
                    }
                }
            }
            if(min_r == INF) {
                return 0;
            }
            return (max_r - min_r + 1) * (max_c - min_c + 1);
        };
        
        int ans = INF;
        for(int c = 0; c < m - 1; c++) {
            int s1 = search(0, 0, n - 1, c);
            if(s1 == 0) {
                continue;
            }
            for(int r = 0; r < n - 1; r++) {
                int s2 = search(0, c + 1, r, m - 1);
                int s3 = search(r + 1, c + 1, n - 1, m - 1);
                if(s2 != 0 && s3 != 0) {
                    ans = std::min(ans, s1 + s2 + s3);
                }
            }
        }
        
        for(int c = m - 1; c > 0; c--) {
            int s1 = search(0, c, n - 1, m - 1);
            if(s1 == 0) {
                continue;
            }
            for(int r = 0; r < n - 1; r++) {
                int s2 = search(0, 0, r, c - 1);
                int s3 = search(r + 1, 0, n - 1, c - 1);
                if(s2 != 0 && s3 != 0) {
                    ans = std::min(ans, s1 + s2 + s3);
                }
            }
        }
        
        for(int r = 0; r < n - 1; r++) {
            int s1 = search(0, 0, r, m - 1);
            if(s1 == 0) {
                continue;
            }
            for(int c = 0; c < m - 1; c++) {
                int s2 = search(r + 1, 0, n - 1, c);
                int s3 = search(r + 1, c + 1, n - 1, m - 1);
                if(s2 != 0 && s3 != 0) {
                    ans = std::min(ans, s1 + s2 + s3);
                }
            }
        }
        
        for(int r = n - 1; r > 0; r--) {
            int s1 = search(r, 0, n - 1, m - 1);
            if(s1 == 0) {
                continue;
            }
            for(int c = 0; c < m - 1; c++) {
                int s2 = search(0, 0, r - 1, c);
                int s3 = search(0, c + 1, r - 1, m - 1);
                if(s2 != 0 && s3 != 0) {
                    ans = std::min(ans, s1 + s2 + s3);
                }
            }
        }
        
        for(int c1 = 0; c1 < m - 2; c1++) {
            for(int c2 = c1 + 1; c2 < m - 1; c2++) {
                int s1 = search(0, 0, n - 1, c1);
                int s2 = search(0, c1 + 1, n - 1, c2);
                int s3 = search(0, c2 + 1, n - 1, m - 1);
                if(s1 != 0 && s2 != 0 && s3 != 0) {
                    ans = std::min(ans, s1 + s2 + s3);
                }
            }
        }
        
        for(int r1 = 0; r1 <= n - 2; r1++) {
            for(int r2 = r1 + 1; r2 < n - 1; r2++) {
                int s1 = search(0, 0, r1, m - 1);
                int s2 = search(r1 + 1, 0, r2, m - 1);
                int s3 = search(r2 + 1, 0, n - 1, m - 1);
                if(s1 != 0 && s2 != 0 && s3 != 0) {
                    ans = std::min(ans, s1 + s2 + s3);
                }
            }
        }
        return ans;
    }
};
