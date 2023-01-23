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
    bool makeStringsEqual(string s, string target) {
        int cnt = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if(s[i] == '1' && target[i] == '1') {
                return true;
            }
        }
        
        bool has_one_zero = false;
        bool has_zero_one = false;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1' && target[i] == '0') {
                has_one_zero = true;
            }
            if(s[i] == '0' && target[i] == '1') {
                has_zero_one = true;
            }
        }
        
        if(has_one_zero && has_zero_one) {
            return true;
        }
        if(!has_one_zero && !has_zero_one) {
            return true;
        }
        
        return false;
    }
};
