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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        int n = garbage.size();
        array<char, 3> type{'M', 'P', 'G'};
        
        for(int i = 0; i < 3; i++) {
            int tot = 0;
            int last = 0;
            for(int j = 0; j < n; j++) {
                string g = garbage[j];
                for(char c : g) {
                    if(c == type[i]) {
                        tot++;
                        last = j;
                    }
                }
            }
            
            ans += tot;
            for(int j = 1; j <= last; j++) {
                ans += travel[j - 1];
            }
        }
        
        return ans;
    }
};
