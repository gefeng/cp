#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = 2000;

class Solution {
public:
    int maxProduct(std::vector<int>& nums, int k, int limit) {
        int n = nums.size();
        int ans = -1;
        
        if(k < -MAX || k > MAX) {
            return -1;
        }
        
        std::vector<std::vector<std::unordered_set<int>>> dp(2, std::vector<std::unordered_set<int>>(MAX * 2));
        std::vector<std::vector<int>> ds(2, std::vector<int>(MAX * 2, 0));
        
        for(int i = 0; i < n; i++) {
            int v = nums[i];
            std::vector<std::vector<std::unordered_set<int>>> nxt(dp);
            std::vector<std::vector<int>> x(ds);
            
            if(k + MAX < MAX * 2 && (ds[0][k + MAX] || ds[1][k + MAX]) && v == 0) {
                ans = 0;
            }
            
            if(v + MAX < MAX * 2) {
                x[0][v + MAX] = 1;
            }
            
            if(v + MAX < MAX * 2 && v <= limit) {
                nxt[0][v + MAX].insert(v);
            }
            
            for(int j = 0; j < MAX * 2; j++) {
                
                if(j - v >= 0 && j - v < MAX * 2) {
                    for(int p : dp[0][j]) {
                        if(p * v <= limit) {
                            nxt[1][j - v].insert(p * v);
                        }
                    }
                }              
                
                if(j + v >= 0 && j + v < MAX * 2) {
                    for(int p : dp[1][j]) {
                        if(p * v <= limit) {
                            nxt[0][j + v].insert(p * v);
                        }
                    }
                }
                
                if(j - v >= 0 && j - v < MAX * 2) {
                    x[1][j - v] = x[1][j - v] || ds[0][j];
                }
                if(j + v >= 0 && j + v < MAX * 2) {
                    x[0][j + v] = x[0][j + v] || ds[1][j];
                }
            }
            std::swap(dp, nxt);
            std::swap(ds, x);
        }
        
        for(int p : dp[0][k + MAX]) {
            ans = std::max(ans, p);
        }
        
        for(int p : dp[1][k + MAX]) {
            ans = std::max(ans, p);
        }
        
        return ans;
    }
};
