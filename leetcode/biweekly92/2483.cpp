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
    int bestClosingTime(string customers) {
        int n = customers.length();
        
        vector<int> cum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            cum[i] = cum[i - 1] + (customers[i - 1] == 'Y' ? 1 : 0);
        }
        
        int ans = 0;
        int min_p = cum[n];
        for(int i = 0; i < n; i++) {
            int p = cum[n] - cum[i] + i - cum[i];
            if(p < min_p) {
                min_p = p;
                ans = i;
            }
        }
        
        if(n - cum[n] < min_p) {
            ans = n;
        }
        
        return ans;
    }
};
