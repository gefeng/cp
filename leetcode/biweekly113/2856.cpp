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
    int minLengthAfterRemovals(std::vector<int>& nums) {
        std::priority_queue<int> pq;
        int n = nums.size();
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && nums[i] == nums[j]) {
                i += 1;
            }
            pq.push(i - j);
        }
        
        int ans = n;
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            ans -= 2;
            if(x - 1) {
                pq.push(x - 1);
            }
            if(y - 1) {
                pq.push(y - 1);
            }
        }
        
        return ans;
    }
};
