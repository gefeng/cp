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
    bool isStrictlyPalindromic(int n) {
        for(int b = 2; b <= n - 2; b++) {
            vector<int> digits;
            int x = n;
            
            while(x) {
                digits.push_back(x % b);
                x /= b;
            }
            
            int sz = digits.size();
            for(int l = 0, r = sz - 1; l < r; l++, r--) {
                if(digits[l] != digits[r]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
