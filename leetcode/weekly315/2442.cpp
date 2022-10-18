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
    int countDistinctIntegers(vector<int>& nums) {
        set<int> seen;
        
        for(int x : nums) {
            seen.insert(x);    
            seen.insert(rev(x));
        }
        
        return seen.size();
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
