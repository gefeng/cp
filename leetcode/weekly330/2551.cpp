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
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(n == k) {
            return 0LL;
        }
        
        vector<int> w;
        for(int i = 1; i < n; i++) {
            w.push_back(weights[i - 1] + weights[i]);
        }
        
        sort(w.begin(), w.end());
        
        LL min_v = 0LL;
        LL max_v = 0LL;
        for(int i = 0; i < k - 1; i++) {
            min_v += w[i];
            max_v += w[n - 1 - i - 1];
        }

        return max_v - min_v;
    }
};
