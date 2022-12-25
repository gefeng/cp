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
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        
        int lo = 0;
        int hi = (int)1e9;
        int ans = 0;
        
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            
            int cnt = 1;
            for(int i = 0; i < n; ) {
                int j = i;
                i += 1;
                while(i < n && price[i] - price[j] < mid) {
                    i += 1;
                }
                
                if(i < n) {
                    cnt += 1;
                }
            }
            
            if(cnt >= k) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
