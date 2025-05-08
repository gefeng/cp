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
    int maxProduct(int n) {
        std::vector<int> digits;
        while(n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        
        int prod = 0;
        int size = digits.size();
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                prod = std::max(prod, digits[i] * digits[j]);
            }
        }
        
        return prod;
    }
};
