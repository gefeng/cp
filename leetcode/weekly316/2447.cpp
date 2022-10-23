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
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int g = -1;
            for(int j = i; j < n; j++) {
                if(j == i) {
                    g = nums[j];
                } else {
                    g = gcd(g, nums[j]);
                }
                if(g == k) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    int gcd(int a, int b) {
        if(a == 0) return b;
        return gcd(b % a, a);
    }
};
