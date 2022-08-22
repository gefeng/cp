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
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        map<long long, int> sum_cnt;
        map<int, pair<int, long long>> seg;
        vector<long long> psum(n + 1, 0);
    
        for(int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + nums[i - 1];
        }
        
        seg[nums.size() - 1] = pair<int, long long>(0, psum[n]);
        sum_cnt[psum[n]] = 1;
        
        vector<long long> ans;
        for(int q : removeQueries) {
            auto it = seg.lower_bound(q);
            int r = it->first;
            int l = it->second.first;
            long long seg_sum = it->second.second;
            
            if(--sum_cnt[seg_sum] == 0) {
                sum_cnt.erase(seg_sum);
            }
            seg.erase(it);
            
            if(r != l) {
                if(q != l) {
                    long long l_sum = psum[q] - psum[l];
                    seg[q - 1] = pair<int, long long>(l, l_sum);
                    sum_cnt[l_sum]++;
                }
                if(q != r) {
                    long long r_sum = psum[r + 1] - psum[q + 1];
                    seg[r] = pair<int, long long>(q + 1, r_sum);
                    sum_cnt[r_sum]++;
                }
            }
            
            if(sum_cnt.empty()) {
                ans.push_back(0LL);
            } else {
                ans.push_back(sum_cnt.rbegin()->first);
            }
        }
        
        return ans;
    }
};
