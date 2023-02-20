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
    int minImpossibleOR(vector<int>& nums) {
        set<int> s;
        for(int x : nums) {
            s.insert(x);
        }
        
        int ans = 0;
        for(int i = 0; i <= 30; i++) {
            int x = 1 << i;
            if(s.find(x) == s.end()) {
                ans = x;
                break;
            }
        }
        
        return ans;
    }
};
