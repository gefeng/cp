#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> digits;
        while(n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        
        reverse(digits.begin(), digits.end());
        
        int sign = 1;
        int ans = 0;
        for(int x : digits) {
            ans += sign * x;
            sign *= -1;
        }
        
        return ans;
    }
};
