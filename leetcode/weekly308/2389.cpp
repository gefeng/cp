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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        int m = nums.size();
        int n = queries.size();
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++) {
            int q = queries[i];
            
            int sum = 0;
            for(int j = 0; j < m; j++) {
                if(sum + nums[j] > q) {
                    break;
                }
                
                sum += nums[j];
                ans[i]++;
            }
        }
        
        return ans;
    } 
};
