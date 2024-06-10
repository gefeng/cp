#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <bitset>

constexpr int MAX = (int)1e5;

class Solution {
public:
    int maxTotalReward(std::vector<int>& rewardValues) {
        std::sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(std::unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        int n = rewardValues.size();

        int bal = 0;
        std::bitset<MAX> ans;
        std::bitset<MAX> tmp;
        ans.set(0);
        for(int i = 0; i < n; i++) {
            while(bal < rewardValues[i]) {
                if(ans[bal]) {
                    tmp.set(bal);
                }
                bal += 1;
            }
            ans |= tmp << rewardValues[i];
        }
        
        for(int i = MAX - 1; i >= 0; i--) {
            if(ans[i]) {
                return i;
            }
        }
        return 0;
    }
};
