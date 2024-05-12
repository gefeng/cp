#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

class Solution {
public:
    int maximumEnergy(std::vector<int>& energy, int k) {
        int n = energy.size();
        int ans = -INF;
        
        std::vector<int> save(n, -INF);
        for(int i = n - 1; i >= 0; i--) {
            if(i + k >= n) {
                save[i] = energy[i];
            } else {
                save[i] = energy[i] + save[i + k];
            }
            ans = std::max(ans, save[i]);
        }
        
        return ans;
    }
};
