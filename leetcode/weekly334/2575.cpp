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
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans(n);
        
        LL x = 0LL;
        for(int i = 0; i < n; i++) {
            x = x * 10LL + word[i] - '0';
            ans[i] = x % m == 0LL ? 1 : 0;
            
            x = x % m;
        }
        
        return ans;
    }
};
