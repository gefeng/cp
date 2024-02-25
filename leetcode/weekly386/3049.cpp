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
    int earliestSecondToMarkIndices(std::vector<int>& nums, std::vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();
        
        int64_t sum = n;
        for(int x : nums) {
            sum += x;
        }
        
        int lo = 1;
        int hi = m;
        int ans = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            int64_t need = sum;
            
            std::vector<int> first(n, -1);
            for(int i = 1; i <= mid; i++) {
                int j = changeIndices[i - 1] - 1;
                first[j] = first[j] == -1 ? i : first[j];
            }
        
            std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
            int cnt_free = 0;
            for(int i = mid; i >= 1; i--) {
                int j = changeIndices[i - 1] - 1;
                if(first[j] == i && nums[j]) {
                    pq.push(nums[j]);
                } else {
                    cnt_free += 1;
                }
                
                if(pq.size() > cnt_free) {
                    pq.pop();
                    cnt_free += 1;
                }
            }
            
            while(!pq.empty()) {
                need -= pq.top() - 1;
                pq.pop();
            }
                   
            if(need <= mid) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
