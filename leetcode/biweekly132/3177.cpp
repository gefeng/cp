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
    int maximumLength(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::map<int, int> m;
        for(int x : nums) {
            m[x] = 0;
        }
        
        int id = 0;
        for(auto& [_, v] : m) {
            v = id++;
        }
        
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = m[nums[i]];
        } 
        
        std::vector<std::vector<int>> dp1(k + 1, std::vector<int>(id, -1));
        std::vector<std::array<int, 4>> dp2(k + 1, {0, -1, 0, -1});
        dp1[0][a[0]] = 1;
        dp2[0][0] = 1;
        dp2[0][1] = a[0];
        
        int ans = 1;
        for(int i = 1; i < n; i++) {
            std::vector<std::array<int, 4>> ndp2(dp2);
            
            for(int j = 0; j <= k; j++) {
                if(j && dp1[j][a[i]] == -1) {
                    continue;
                }
                
                if(j == 0 && dp1[j][a[i]] == -1) {
                    dp1[j][a[i]] = 1;
                } else {
                    dp1[j][a[i]] += 1; 
                }
                
                int v = dp1[j][a[i]];
                std::array<int, 4>& n_info = ndp2[j];
                if(v > n_info[0]) {
                    if(a[i] == n_info[1]) {
                        n_info[0] = v;
                    } else {
                        n_info[2] = n_info[0];
                        n_info[3] = n_info[1];
                        n_info[0] = v;
                        n_info[1] = a[i];
                    }
                } else if(v > n_info[2]) {
                    if(a[i] != n_info[1]) {
                        n_info[2] = v;
                        n_info[3] = a[i];
                    }
                }
                ans = std::max(ans, dp1[j][a[i]]);
            }
            
            for(int j = 1; j <= k; j++) {
                std::array<int, 4>& info = dp2[j - 1];
                if(info[1] == -1) {
                    continue;
                }
                
                if(a[i] != info[1]) {
                    dp1[j][a[i]] = std::max(dp1[j][a[i]], info[0] + 1);
                } else {
                    if(info[3] != -1) {
                        dp1[j][a[i]] = std::max(dp1[j][a[i]], info[2] + 1);
                    }
                }
                
                int v = dp1[j][a[i]];
                std::array<int, 4>& n_info = ndp2[j];
                if(v > n_info[0]) {
                    if(a[i] == n_info[1]) {
                        n_info[0] = v;
                    } else {
                        n_info[2] = n_info[0];
                        n_info[3] = n_info[1];
                        n_info[0] = v;
                        n_info[1] = a[i];
                    }
                } else if(v > n_info[2]) {
                    if(a[i] != n_info[1]) {
                        n_info[2] = v;
                        n_info[3] = a[i];
                    }
                }
                ans = std::max(ans, v);
            }
            std::swap(dp2, ndp2);
        }
        
        return ans;
    }
};
