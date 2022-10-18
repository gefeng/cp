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
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++) {
            if(i + rev(i) == num) {
                return true;
            }
        }
        return false;
    }
    
    int rev(int x) {
        int res = 0;
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
