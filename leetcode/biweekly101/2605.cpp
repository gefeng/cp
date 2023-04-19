#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    int minNumber(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::array<int, 10> cnt1 = {};
        std::array<int, 10> cnt2 = {};
        
        for(int x : nums1) {
            cnt1[x] += 1;
        }
        
        for(int x : nums2) {
            cnt2[x] += 1;
        }
        
        for(int i = 0; i < 10; i++) {
            if(cnt1[i] && cnt2[i]) {
                return i;
            }
        }
        
        int a = 0;
        int b = 0;
        for(int i = 0; i < 10; i++) {
            if(cnt1[i]) {
                a = i;
                break;
            }
        }
        for(int i = 0; i < 10; i++) {
            if(cnt2[i]) {
                b = i;
                break;
            }
        }
        
        if(a > b) {
            std::swap(a, b);
        }
        
        return a * 10 + b;
    }
};
