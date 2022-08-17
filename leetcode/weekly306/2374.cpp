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
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> s(n, 0);
        
        for(int i = 0; i < n; i++) {
            s[edges[i]] += i;
        }
        
        long long max_s = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] > max_s) {
                max_s = s[i];
                ans = i;
            }
        }
        
        return ans;
    }
};
