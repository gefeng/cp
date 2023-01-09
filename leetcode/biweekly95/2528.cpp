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
using LL = long long;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        
        LL lo = 0LL;
        LL hi = (LL)1e14;
        LL ans = 0LL;
        while(lo <= hi) {
            LL mid = (lo + hi) >> 1LL;
            
            vector<int> v(stations);
            vector<LL> d(n + 1, 0LL);
            int x = k;
            
            for(int i = 0; i < n; i++) {
                int left = max(0, i - r);
                int right = min(n - 1, i + r);
                
                d[left] += v[i];
                d[right + 1] -= v[i];
            }
            
            LL sum = 0LL;
            bool ok = true;
            for(int i = 0; i < n; i++) {
                sum += d[i];
                if(sum < mid) {
                    LL need = min(mid - sum, (LL)x);
                    if(mid - sum > x) {
                        ok = false;
                        break;
                    }
                    
                    x -= need;
                    sum += need;
                    d[min(n, i + 2 * r + 1)] -= need;
                }
            }
            
            if(ok) {
                ans = mid;
                lo = mid + 1LL;
            } else {
                hi = mid - 1LL;
            }
        }
        
        return ans;
    }
};
