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
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        auto cmp = [](const auto& a, const auto& b) {
            return a[1] < b[1];
        };
        
        sort(tasks.begin(), tasks.end(), cmp);
        
        vector<bool> on(2001, false);
        for(auto& t : tasks) {
            int st = t[0];
            int ed = t[1];
            int need = t[2];
            
            int processed = 0;
            for(int i = st; i <= ed; i++) {
                if(on[i]) {
                    processed += 1;
                }
            }
            
            int left = max(0, need - processed);
            for(int i = ed; i >= st && left; i--) {
                if(!on[i]) {
                    left -= 1;
                    on[i] = true;
                } 
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= 2000; i++) {
            ans += on[i] ? 1 : 0;
        } 
        
        return ans;
    }
};
