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
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.length();
        array<int, 26> d;
        d.fill(-1);
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(d[c] == -1) {
                d[c] = i;
            } else {
                if(i - d[c] - 1 != distance[c]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
