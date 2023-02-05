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
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        
        for(int x : gifts) {
            pq.push(x);
        }
        
        while(!pq.empty() && k) {
            int cur = pq.top();
            pq.pop();
            
            cur = (int)sqrt(cur);
            
            pq.push(cur);
            k -= 1;
        }
        
        long long ans = 0LL;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};
