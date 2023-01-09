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
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int x : nums) {
            pq.push(x);
        }
        
        LL ans = 0LL;
        while(!pq.empty() && k) {
            int x = pq.top();
            pq.pop();
            
            ans += x;
            
            x = (x + 3 - 1) / 3;
            if(x) {
                pq.push(x);
            }
            
            k -= 1;
        }
        
        return ans;
    }
};
