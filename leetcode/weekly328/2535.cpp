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
    int differenceOfSum(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        for(int x : nums) {
            sum1 += x;
            
            while(x) {
                sum2 += x % 10;
                x /= 10;
            }
        }
        
        return abs(sum1 - sum2);
    }
};
