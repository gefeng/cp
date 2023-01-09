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
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> s;
        
        for(int x : nums) {
            for(int f = 2; f * f <= x; f++) {
                while(x % f == 0) {
                    s.insert(f);
                    x /= f;
                }
            }
            if(x > 1) {
                s.insert(x);
            }
        }
        
        return s.size();
    }
};
