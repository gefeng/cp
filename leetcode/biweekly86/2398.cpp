#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int lo = 0;
        int hi = n;
        int ans = 0;
        
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            
            if(isOk(chargeTimes, runningCosts, budget, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
    
    bool isOk(vector<int>& ct, vector<int>& rc, long long budget, int k) {
        int n = ct.size();
        long long sum = 0LL;
        deque<int> s;
        
        for(int l = 0, r = 0; r < n; r++) {
            while(!s.empty() && r - s.front() + 1 > k) {
                s.pop_front();
            }
            
            while(!s.empty() && ct[s.back()] <= ct[r]) {
                s.pop_back();
            }
            
            s.push_back(r);
            
            sum += rc[r];
            if(r - l + 1 > k) {
                sum -= rc[l++];
            }
            
            if(r - l + 1 == k) {
                long long cost = k * sum + ct[s.front()];
                if(cost <= budget) {
                    return true;
                } 
            }
        }
        
        return false;
    }
};
