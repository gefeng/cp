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
    int maximumSetSize(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        std::set<int> s1;
        std::set<int> s2;
        std::set<int> ans;
        for(int x : nums1) {
            s1.insert(x);
        }
        
        for(int x : nums2) {
            s2.insert(x);
        }
        
        int cnt1 = 0;
        int cnt2 = 0;
        for(int x : s1) {
            if(cnt1 < n / 2 && s2.find(x) == s2.end()) {
                ans.insert(x);
                cnt1 += 1;
            } 
        }
        
        for(int x : s2) {
            if(cnt2 < n / 2 && s1.find(x) == s1.end()) {
                ans.insert(x);
                cnt2 += 1;
            } 
        }
        
        for(int x : nums1) {
            if(cnt1 < n / 2 && ans.find(x) == ans.end()) {
                ans.insert(x);
                cnt1 += 1;
            }
        }
        
        for(int x : nums2) {
            if(cnt2 < n / 2 && ans.find(x) == ans.end()) {
                ans.insert(x);
                cnt2 += 1;
            }
        }
        
        return ans.size();
    }
};
