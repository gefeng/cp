#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr std::array<int, 8> DR = {0, 1, 0, -1, 1, -1, 1, -1};
constexpr std::array<int, 8> DC = {1, 0, -1, 0, 1, -1, -1, 1};

class Solution {
public:
    int mostFrequentPrime(std::vector<std::vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        std::map<int, int> freq;
        
        auto is_prime = [](int x) {
            for(int f = 2; f * f <= x; f++) {
                if(x % f == 0) {
                    return false;
                }
            }
            return true;
        };
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int d = 0; d < 8; d++) {
                    int r = i;
                    int c = j;
                    int x = 0;
                    while(r >= 0 && c >= 0 && r < n && c < m) {
                        x = x * 10 + mat[r][c];
                        
                        if(x > 10 && is_prime(x)) {
                            freq[x] += 1;
                        }
                        
                        r += DR[d];
                        c += DC[d];
                    }
                }
            }
        }
        
        int max_f = 0;
        for(auto [v, f] : freq) {
            max_f = std::max(max_f, f);
        }
        
        int ans = -1;
        for(auto [v, f] : freq) {
            if(f == max_f) {
                ans = v;
            }
        }
        
        return ans;
    }
};
