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
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        
        auto symmetric = [](int x) {
            std::vector<int> digits;
            while(x) {
                digits.push_back(x % 10);
                x /= 10;
            }
            int n = digits.size();
            if(n % 2 == 1) {
                return false;
            }
            
            int sum = 0;
            for(int i = 0; i < n / 2; i++) {
                sum += digits[i];
            } 
            for(int i = n / 2; i < n; i++) {
                sum -= digits[i];
            }
            
            return sum == 0;
        };
        
        for(int x = low; x <= high; x++) {
            if(symmetric(x)) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
