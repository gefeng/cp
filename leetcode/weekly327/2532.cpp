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

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        auto cmp1 = [](const auto& a, const auto& b) {
            if(a[1] + a[3] == b[1] + b[3]) {
                return a[0] < b[0];
            }
            return a[1] + a[3] < b[1] + b[3];
        };
        
        auto cmp2 = [](const auto& a, const auto& b){
            return a[0] > b[0];
        };
        
        priority_queue<array<int, 5>, vector<array<int, 5>>, decltype(cmp1)> wait_l(cmp1); 
        priority_queue<array<int, 5>, vector<array<int, 5>>, decltype(cmp1)> wait_r(cmp1); 
        priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp2)> busy_l(cmp2);
        priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp2)> busy_r(cmp2);
        
        for(int i = 0; i < k; i++) {
            busy_l.push({0, i});
        }
        
        int t = 0;
        int ans = 0;
        while(true) {
            while(!busy_l.empty() && busy_l.top()[0] <= t) {
                array<int, 2> x = busy_l.top();
                busy_l.pop();
                
                wait_l.push({x[1], time[x[1]][0], time[x[1]][1], time[x[1]][2], time[x[1]][3]});
            }
            
            while(!busy_r.empty() && busy_r.top()[0] <= t) {
                array<int, 2> x = busy_r.top();
                busy_r.pop();
                
                wait_r.push({x[1], time[x[1]][0], time[x[1]][1], time[x[1]][2], time[x[1]][3]});
            }
            
            if(n == 0 && wait_r.empty() && !busy_r.empty()) {
                t = busy_r.top()[0];
                continue;
            }
            
            if(wait_l.empty() && wait_r.empty() && n) {
                if(!busy_l.empty() && !busy_r.empty()) {
                    t = min(busy_l.top()[0], busy_r.top()[0]);
                } else if(busy_l.empty()) {
                    t = busy_r.top()[0];
                } else if(busy_r.empty()) {
                    t = busy_l.top()[0];
                }
                continue;
            }
            
            if(!wait_r.empty()) {
                array<int, 5> x = wait_r.top();
                wait_r.pop();
                
                t += x[3];
                ans = t;
                //cout << ans << '\n';
                
                busy_l.push({t + x[4], x[0]});
            } else {
                if(n) {
                    if(wait_l.empty()) {
                        t = busy_l.top()[0];
                        continue;
                    }
                    
                    array<int, 5> x = wait_l.top();
                    wait_l.pop();

                    t += x[1];

                    busy_r.push({t + x[2], x[0]});
                    
                    n -= 1;
                } else {
                    break;   
                }
            }
        }
        
        return ans;
    }
};
