#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> z_function(std::string s) {
        int n = s.size();
        std::vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = std::min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    
    int minimumTimeToInitialState(std::string word, int k) {
        int n = word.size();
        int ans = (n + k - 1) / k;
        
        std::vector<int> z = z_function(word);
        for(int i = 0; i < n; i++) {
            if(z[i] == n - i && i % k == 0) {
                ans = std::min(ans, i / k);
            }
        }
        
        return ans;
    }
};
