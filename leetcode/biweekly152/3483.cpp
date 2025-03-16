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
    int totalNumbers(std::vector<int>& digits) {
        int n = digits.size();
        int ans = 0;
        std::vector<int> seen(1000, 0);
        for(int i = 0; i < n; i++) {
            if(digits[i] % 2 == 1) {
                continue;
            }
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i != j && i != k && j != k && digits[j] != 0) {
                        seen[digits[j] * 100 + digits[k] * 10 + digits[i]] = 1;
                    }
                }
            }
        }
        
        for(int i = 100; i < 1000; i++) {
            ans += seen[i];
        }
        
        return ans;
    }
};
