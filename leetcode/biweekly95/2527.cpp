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
    int xorBeauty(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(int x : nums) {
            sum ^= x;
        }
        
        return sum;
    }
};
