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
            if(save[i] == -INF) {
                save[i] = energy[i];
                for(int j = i + k; j < n; j += k) {
                    if(save[j] != -INF) {
                        save[i] += save[j];
                        break;
                    } else {
                        save[i] += energy[j];
                    }
                }
            }
            ans = std::max(ans, save[i]);
        }
        
        return ans;
    }
};
