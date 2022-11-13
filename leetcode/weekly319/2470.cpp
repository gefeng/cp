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
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int x = 1;
            for(int j = i; j < n; j++) {
                x = lcm(x, nums[j]);
                if(x == k) {
                    ans += 1;
                } else if(x > k) {
                    break;
                }
            }
        }
        
        return ans;
    }
    
    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
    
    int gcd(int a, int b) {
        if(a == 0) return b;
        return gcd(b % a, a);
    }
};
