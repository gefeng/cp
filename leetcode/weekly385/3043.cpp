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
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        int ans = 0;
        
        std::set<int> s;
        for(int x : arr1) {
            std::vector<int> d;
            while(x) {
                d.push_back(x % 10);
                x /= 10;
            }
            
            int cur = 0;
            for(int i = d.size() - 1; i >= 0; i--) {
                cur = cur * 10 + d[i]; 
                s.insert(cur);
            }
        }
        
        for(int x : arr2) {
            std::vector<int> d;
            while(x) {
                d.push_back(x % 10);
                x /= 10;
            }
            
            int cur = 0;
            for(int i = d.size() - 1; i >= 0; i--) {
                cur = cur * 10 + d[i]; 
                if(s.find(cur) != s.end()) {
                    ans = std::max(ans, (int)d.size() - i);
                }
            }
        }
        
        return ans;
    }
};
