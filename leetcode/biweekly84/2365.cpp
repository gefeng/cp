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
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int n = tasks.size();
        long long ans = 0;
        
        unordered_map<int, long long> cd;
        for(int t : tasks) {
            long long x = cd.count(t) ? cd[t] : 0;
            ans = max(ans, x);
            
            cd[t] = ans + space + 1;
            
            ans++;
        }
        
        return ans;
    }
};
