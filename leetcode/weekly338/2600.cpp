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
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = std::min(numOnes, k);
        k -= std::min(numOnes, k);
        
        k -= std::min(numZeros, k);
        
        ans -= std::min(numNegOnes, k);
        
        return ans;
    }
};
