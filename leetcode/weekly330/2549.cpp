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
    int distinctIntegers(int n) {
        if(n == 1) {
            return 1;
        }
        return n - 1;
    }
};
