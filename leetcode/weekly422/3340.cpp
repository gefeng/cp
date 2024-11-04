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
    bool isBalanced(std::string num) {
        int sum_eve = 0;
        int sum_odd = 0;
        int n = num.size();
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                sum_eve += num[i] - '0';
            } else {
                sum_odd += num[i] - '0';
            }
        }
        
        return sum_eve == sum_odd;
    }
};
