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
    std::vector<std::vector<int>> findPrimePairs(int n) {
        std::vector<std::vector<int>> ans;
        std::vector<int> is_prime(n + 1, true);
        is_prime[1] = false;
        
        std::set<int> primes;
        for(int i = 2; i <= n; i++) {
            if(is_prime[i]) {
                primes.insert(i);
                for(int j = i + i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        
        for(int x : primes) {
            if(x <= n - x && primes.find(n - x) != primes.end()) {
                ans.emplace_back();
                ans.back().push_back(x);
                ans.back().push_back(n - x);
            }
        }
        
        return ans;
    }
};
