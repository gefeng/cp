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
    const LL MOD = (LL)1e9 + 7LL;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> p;
        int cur = (int)pow(2, 30);
        while(n) {
            if(n >= cur) {
                p.push_back(cur);
                n -= cur;
            }
            cur /= 2;
        }

        reverse(p.begin(), p.end());

        int m = queries.size();
        vector<int> ans(m, 0);
        for(int i = 0; i < m; i++) {
            auto& q = queries[i];
            
            LL prod = 1LL;
            for(int j = q[0]; j <= q[1]; j++) {
                prod *= p[j];
                prod %= MOD;
            }

            ans[i] = (int)prod;
        }

        return ans;
    }
};
