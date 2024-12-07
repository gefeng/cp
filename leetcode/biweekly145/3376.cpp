#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    int findMinimumTime(std::vector<int>& strength, int K) {
        int n = strength.size();
        
        std::vector<int> a(n);
        std::iota(a.begin(), a.end(), 0);
        
        int ans = int(2e9);
        do {
            int x = 1;
            int sum = 0;
            for(int i = 0; i < n; i++) {
                int j = a[i];
                int s = strength[j];
                
                int need = (s + x - 1) / x;
                sum += need;
                
                x += K;
            }
            ans = std::min(ans, sum);
        } while(std::next_permutation(a.begin(), a.end()));
        
        return ans;
    }
};
