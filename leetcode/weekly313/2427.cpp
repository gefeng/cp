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
    int commonFactors(int a, int b) {
        int ans = 0;
        for(int i = 1; i <= min(a, b); i++) {
            if(a % i == 0 && b % i == 0) {
                ans++;
            }
        }
        
        return ans;
    }
};
