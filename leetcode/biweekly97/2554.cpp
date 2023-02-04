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
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s;
        for(int x : banned) {
            s.insert(x);
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(s.find(i) == s.end() && maxSum >= i) {
                maxSum -= i;
                ans += 1;
            }
        }
        
        return ans;
    }
};
