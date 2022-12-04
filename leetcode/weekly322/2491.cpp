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
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        
        sort(skill.begin(), skill.end());
        
        LL ans = 0LL;
        LL pre = -1LL;
        for(int l = 0, r = n - 1; l < r; l++, r--) {
            LL sum = skill[l] + skill[r];
            if(pre != -1 && sum != pre) {
                return -1LL;
            }
            pre = sum;
            ans += 1LL * skill[l] * skill[r]; 
        }
        
        return ans;
    }
};
