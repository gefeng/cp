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

using namespace std;
using LL = long long;

class Solution {
public:
   long long kSum(vector<int>& nums, int k) {
        long long ans = 0;
        long long max_sum = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0) {
                max_sum += nums[i];
            } else {
                nums[i] = -nums[i];
            }
        }
        
        sort(nums.begin(), nums.end());
        
        priority_queue<pair<LL, int>> pq;
        pq.push(pair<LL, int>(max_sum, 0));
        
        while(k > 1) {
            pair<LL, int> cur = pq.top();
            pq.pop();
            
            LL v = cur.first;
            int i = cur.second;
            
            if(i < n) {
                pq.push(pair<LL, int>(v - nums[i], i + 1));
                if(i) {
                    pq.push(pair<LL, int>(v + nums[i - 1] - nums[i], i + 1));
                }
            }
            
            k--;
        }
        
        return pq.top().first;
    } 
};
