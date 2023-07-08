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
    std::vector<long long> countBlackBlocks(int m, int n, std::vector<std::vector<int>>& coordinates) {
        std::vector<long long> ans(5, 0);
        
        std::set<std::pair<int, int>> s;
        for(auto& p : coordinates) {
            int x = p[0];
            int y = p[1];
            s.insert({x, y});
        }
        
        auto is_ok = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < m && y < n;
        };
        
        std::set<std::pair<int, int>> vis;
        for(auto& p : coordinates) {
            int x = p[0];
            int y = p[1];
            
            int r = x - 1;
            int c = y - 1;
            int cnt = 0;
            if(is_ok(r, c) && vis.find({r, c}) == vis.end()) {
                for(int i = 0; i < 2; i++) {
                    for(int j = 0; j < 2; j++) {
                        if(s.find({r + i, c + j}) != s.end()) {
                            cnt += 1;
                        }
                    }
                }
                vis.emplace(r, c);
                ans[cnt] += 1;
            }
            
            r = x - 1;
            c = y + 1;
            cnt = 0;
            if(is_ok(r, c) && vis.find({r, y}) == vis.end()) {
                for(int i = 0; i < 2; i++) {
                    for(int j = -1; j < 1; j++) {
                        if(s.find({r + i, c + j}) != s.end()) {
                            cnt += 1;
                        }
                    }
                } 
                vis.emplace(r, y);
                ans[cnt] += 1;
            }
            
            r = x + 1;
            c = y - 1;
            cnt = 0;
            if(is_ok(r, c) && vis.find({x, c}) == vis.end()) {
                for(int i = -1; i < 1; i++) {
                    for(int j = 0; j < 2; j++) {
                        if(s.find({r + i, c + j}) != s.end()) {
                            cnt += 1;
                        }
                    }
                } 
                vis.emplace(x, c);
                ans[cnt] += 1;
            }
            
            r = x + 1;
            c = y + 1;
            cnt = 0;
            if(is_ok(r, c) && vis.find({x, y}) == vis.end()) {
                for(int i = -1; i < 1; i++) {
                    for(int j = -1; j < 1; j++) {
                        if(s.find({r + i, c + j}) != s.end()) {
                            cnt += 1;
                        }
                    }
                } 
                vis.emplace(x, y);
                ans[cnt] += 1;
            }
        }
        
        ans[0] = ((int64_t)m - 1) * (n - 1);
        for(int i = 1; i < 5; i++) {
            ans[0] -= ans[i];
        }
        
        return ans;
    }
};
