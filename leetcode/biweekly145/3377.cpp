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

constexpr int MAX = 99999;
constexpr int64_t INF = int64_t(2e18);

class Solution {
public:
    int minOperations(int n, int m) {
        std::vector<int> is_prime(MAX + 1, 1);
        is_prime[1] = 0;
        for(int i = 2; i <= MAX; i++) {
            if(is_prime[i]) {
                for(int j = i + i; j <= MAX; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
        
        if(is_prime[n] || is_prime[m]) {
            return -1;
        }
        
        std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> pq;
        std::vector<int64_t> best(MAX + 1, INF);
        best[n] = n;
        pq.emplace(n, n);
        while(!pq.empty()) {
            auto [c, x] = pq.top();
            pq.pop();
            
            if(best[x] != c) {
                continue;
            }
     
            for(int i = 1; x / i > 0; i *= 10) {
                int d = x / i % 10;
                if(d != 9) {
                    int nx = x + i;
                    if(!is_prime[nx] && best[nx] > c + nx) {
                        best[nx] =  c + nx;
                        pq.emplace(c + nx, nx);
                    }
                } 
                if(d != 0) {
                    int nx = x - i;
                    if(!is_prime[nx] && best[nx] > c + nx) {
                        best[nx] =  c + nx;
                        pq.emplace(c + nx, nx);
                    }
                }
            }
        }

        
        int64_t ans = best[m];
        
        return ans == INF ? -1 : ans;
    }
};
