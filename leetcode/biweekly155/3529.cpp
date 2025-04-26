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
    std::vector<int> prefix_function(std::string s) {
        int n = (int)s.length();
        std::vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    
    int countCells(std::vector<std::vector<char>>& grid, std::string pattern) {
        int n = grid.size();
        int m = grid[0].size();
        int len = pattern.size();
        
        std::string s_h = "";
        std::string s_v = "";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                s_h.push_back(grid[i][j]);
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                s_v.push_back(grid[j][i]);
            }
        }
        
        std::string s = pattern + "#" + s_h;
        std::string t = pattern + "#" + s_v;
        
        std::vector<int> a = prefix_function(s);
        std::vector<int> b = prefix_function(t);
        
        int size = a.size();
        int rolling = 0;
        std::vector<int> diff(n * m + 1, 0);
        std::vector<std::vector<int>> cnt(n, std::vector<int>(m, 0));
        for(int i = len + 1; i < size; i++) {
            if(a[i] == len) {
                // [i - len + 1, i]
                diff[i - len + 1 - len - 1] += 1;
                diff[i + 1 - len - 1] -= 1;
            }
        }
        
        for(int i = 0; i < n * m; i++) {
            rolling += diff[i];
            if(rolling) {
                cnt[i / m][i % m] = 1;
            }
        }
        
        size = b.size();
        rolling = 0;
        diff.assign(m * n, 0);
        for(int i = len + 1; i < size; i++) {
            if(b[i] == len) {
                diff[i - len + 1 - len - 1] += 1;
                diff[i + 1 - len - 1] -= 1;
            }
        }
        
        for(int i = 0; i < n * m; i++) {
            rolling += diff[i];
            if(rolling) {
                cnt[i % n][i / n] += 1;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(cnt[i][j] > 1) {
                    ans += 1;
                } 
            }
        }
        
        return ans;
    }
};
