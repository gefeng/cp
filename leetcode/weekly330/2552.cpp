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
using LL = long long;

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> l(n, vector<int>(n, 0));
        vector<vector<int>> r(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    cnt += 1;
                }
                if(nums[j] > nums[i]) {
                    l[j][i] = cnt;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            int cnt = 0; 
            for(int j = n - 1; j > i; j--) {
                if(nums[j] > nums[i]) {
                    cnt += 1;
                }
                if(nums[j] < nums[i]) {
                    r[i][j] = cnt;
                }
            }
        }
        
        LL ans = 0LL;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += l[i][j] * r[i][j];
            }
        }
        
        return ans;
    }
};
