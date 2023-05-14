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
    bool doesValidArrayExist(std::vector<int>& derived) {
        int n = derived.size();
        
        auto solve = [&](int first) {
            int x = first;
            for(int i = 0; i < n - 1; i++) {
                x = x ^ derived[i];
            }
            if((x ^ first) != derived[n - 1]) {
                return false;
            }
            return true;
        };
        
        return solve(0) || solve(1);
    }
};
