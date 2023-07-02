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
    int sumImbalanceNumbers(std::vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            std::map<int, int> m;
            int sum = 0;
            for(int j = i; j < n; j++) {
                if(m.find(nums[j]) != m.end()) {
                    m[nums[j]] += 1;
                } else {
                    auto it = m.upper_bound(nums[j]);
                    
                    if(it == m.end()) {
                        if(it != m.begin()) {
                            it--;
                            sum += (nums[j] - it->first > 1) ? 1 : 0;
                        }
                    } else if(it == m.begin()) {
                        sum += (it->first - nums[j] > 1) ? 1 : 0;
                    } else {
                        auto pre = std::prev(it);
                        sum -= (it->first - pre->first > 1) ? 1 : 0;
                        
                        sum += (it->first - nums[j] > 1) ? 1 : 0;
                        sum += (nums[j] - pre->first > 1) ? 1 : 0;
                    }
                    
                    m[nums[j]] += 1;
                }
                
                ans += sum;
            }
            
            
        }
        
        return ans;
    }
};
