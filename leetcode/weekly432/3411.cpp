#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = 3628800;

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

class Solution {
public:
    int maxLength(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        
        for(int i = 0; i < n; i++) {
            int g = 1;
            int l = 1;
            int p = 1;
            for(int j = i; j < n; j++) {
                g = j == i ? nums[j] : gcd(g, nums[j]);
                l = j == i ? nums[j] : lcm(l, nums[j]);
                p *= nums[j];
                if(p == g * l) {
                    ans = std::max(ans, j - i + 1);
                } else if(p > MAX) {
                    break;
                }
            }   
        }
        
        return ans;
    }
};
