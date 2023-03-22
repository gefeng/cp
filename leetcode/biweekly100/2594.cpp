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
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        
        LL lo = 1LL;
        LL hi = (LL)2e18;
        LL ans = 0LL;
        while(lo <= hi) {
            LL mid = (lo + hi) >> 1;
            
            LL sum = 0LL;
            for(int r : ranks) {
                LL x = (LL)sqrt(mid / r);
                if((x + 1LL) * (x + 1LL) <= mid / r) {
                    sum += x + 1LL;
                } else if(x * x <= mid / r) {
                    sum += x;
                } else {
                    sum += x - 1LL;
                }
            }
            
            if(sum >= cars) {
                ans = mid;
                hi = mid - 1LL;
            } else {
                lo = mid + 1LL;
            }
        }
        return ans;
    }
};
