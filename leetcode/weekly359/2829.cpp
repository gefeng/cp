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
    int minimumSum(int n, int k) {
        std::set<int> s;
        int sum = 0;
        int cur = 1;
        while(s.size() != n) {
            if(s.find(k - cur) == s.end()) {
                s.insert(cur);
                sum += cur;
            }
            cur += 1;
        }
        
        return sum;
    }
};
