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
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long ans = 0LL;
        long long cur = 0LL;
        long long max_cash = 0LL;
        long long max_earn = 0LL;
        
        for(auto& t : transactions) {
            if(t[0] > t[1]) {
                max_cash = max(max_cash, (long long)t[1]);
                ans += t[0] - t[1];
            } else {
                max_earn = max(max_earn, (long long)t[0]);
            }
        }
        
        ans += max_cash;
        ans += max(0LL, max_earn - max_cash);
        
        return ans;
    }
};
