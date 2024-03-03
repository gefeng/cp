#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        int ans = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for(int x : nums) {
            if(x < k) {
                pq.push(x);
            }
        }
        
        while(!pq.empty()) {
            if(pq.size() == 1) {
                ans += 1;
                break;
            }
            
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            int64_t z = (int64_t)x * 2 + y;
            ans += 1;
            if(z < k) {
                pq.push((int)z);
            }
        }
        
        return ans;
    }
};
