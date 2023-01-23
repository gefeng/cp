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
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(int x : nums1) {
            s.insert(x);
        }
        
        int ans = (int)2e9;
        for(int x : nums2) {
            if(s.find(x) != s.end()) {
                ans = min(ans, x);
            }
        }
        
        return ans == (int)2e9 ? -1 : ans;
    }
};
