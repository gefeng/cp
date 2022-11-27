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
    int numberOfCuts(int n) {
        if(n == 1) {
            return 0;
        }
        
        if(n & 1) {
            return n;
        } else {
            return n / 2;
        }
    }
};
