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
    int partitionString(string s) {
        array<int, 26> cnt{0};
        
        int ans = 1;
        for(char c : s) {
            if(cnt[c - 'a'] > 0) {
                cnt = array<int, 26>();
                cnt.fill(0);
                cnt[c - 'a'] = 1;
                ans++;
            } else {
                cnt[c - 'a']++;
            }
        }
        
        return ans;
    }
};
