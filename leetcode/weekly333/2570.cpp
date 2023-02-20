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
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
    
        int m = nums1.size();
        int n = nums2.size();
        for(int i = 0, j = 0; i < m || j < n; ) {
            ans.emplace_back();
            if(i == m) {
                ans.back().push_back(nums2[j][0]);
                ans.back().push_back(nums2[j][1]);
                j += 1;
            } else if(j == n) {
                ans.back().push_back(nums1[i][0]);
                ans.back().push_back(nums1[i][1]);
                i += 1;
            } else {
                if(nums1[i][0] == nums2[j][0]) {
                    ans.back().push_back(nums1[i][0]);
                    ans.back().push_back(nums1[i][1] + nums2[j][1]);
                    i += 1;
                    j += 1;
                } else if(nums1[i][0] < nums2[j][0]) {
                    ans.back().push_back(nums1[i][0]);
                    ans.back().push_back(nums1[i][1]);
                    i += 1;
                } else {
                    ans.back().push_back(nums2[j][0]);
                    ans.back().push_back(nums2[j][1]);
                    j += 1;
                }
            }
        }
        
        return ans;
    }
};
