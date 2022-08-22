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
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int ans = 0;
        int cur = initialEnergy;
        for(int i = 0; i < n; i++) {
            if(cur <= energy[i]) {
                ans += energy[i] - cur + 1;
                cur = 1;
            } else {
                cur -= energy[i];
            }
        }
        
        cur = initialExperience;
        for(int i = 0; i < n; i++) {
            if(cur <= experience[i]) {
                ans += experience[i] - cur + 1;
                cur += experience[i] - cur + 1;
            } 
            cur += experience[i];
        }
        return ans;
    }
};
