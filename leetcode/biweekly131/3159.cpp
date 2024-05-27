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
    std::vector<int> occurrencesOfElement(std::vector<int>& nums, std::vector<int>& queries, int x) {
        int n = nums.size();
        int m = queries.size();
        std::vector<int> ans(m);
        
        std::vector<int> a;
        for(int i = 0; i < n; i++) {
            if(nums[i] == x) {
                a.push_back(i);
            }
        }
        
        for(int i = 0; i < m; i++) {
            ans[i] = queries[i] > a.size() ? -1 : a[queries[i] - 1];
        }
        
        return ans;
    }
};
