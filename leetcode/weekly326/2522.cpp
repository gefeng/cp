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
    int minimumPartition(string s, int k) {
        int ans = 0;
        int n = s.length();
        
        LL cur = 0LL;
        for(int i = 0; i < n; i++) {
            LL nxt = cur * 10LL + s[i] - '0';
            
            if(nxt > k) {
                cur = s[i] - '0';
                if(cur > k) {
                    return -1;
                }
                ans += 1;
            } else {
                cur = nxt;
            }
        }
        
        if(cur) {
            ans += 1;
        }
        
        return ans;
    }
};
