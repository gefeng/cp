#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        std::vector<int> a(n, 1);
        
        for(int i = 0; i < k; i++) {
            for(int j = 1; j < n; j++) {
                a[j] += a[j - 1];
                a[j] %= MOD;
            }
        }
        
        return a.back();
    }
};
