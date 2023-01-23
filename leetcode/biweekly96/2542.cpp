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
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        
        int n = nums1.size();
        for(int i = 0; i < n; i++) {
            v.emplace_back(nums1[i], nums2[i]);
        }
        
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        
        auto cmp = [](const auto& a, const auto& b) {
            if(a.second == b.second) {
                return a.first > b.first;
            }
            return a.second > b.second;
        };
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        LL sum = 0LL;
        LL min_v = (LL)2e5;
        LL ans = 0LL;
        for(int i = 0; i < n; i++) {
            pair<int, int> p = v[i];
            sum += p.first;
            min_v = min(min_v, (LL)p.second);
            pq.emplace(p.first, p.second);
            
            if(pq.size() > k) {
                pair<int, int> cur = pq.top();
                pq.pop();
                
                sum -= cur.first;
                if(pq.top().second > min_v) {
                    min_v = pq.top().second;
                }
            }
            
            if(pq.size() == k) {
                ans = max(ans, sum * min_v);
            }
        }
        
        return ans;
    }
};
