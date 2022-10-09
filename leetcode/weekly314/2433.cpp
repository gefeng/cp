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
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n, 0);
        
        ans[0] = pref[0];
        for(int i = 1; i < n; i++) {
            ans[i] = pref[i] ^ pref[i - 1];
        }
        
        return ans;
    }
};
