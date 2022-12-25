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
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        
        int ans = 0;
        for(int i = 0; i < n; ) {
            if(forts[i] == 1) {
                i += 1;
                int j = i;
                while(i < n && forts[i] == 0) {
                    i += 1;
                }
                if(i < n && forts[i] == -1) {
                    ans = max(ans, i - j);
                }
            } else {
                i += 1;
            }
        }
        
        for(int i = n - 1; i >= 0; ) {
            if(forts[i] == 1) {
                i -= 1;
                int j = i;
                while(i >= 0 && forts[i] == 0) {
                    i -= 1;
                }
                if(i >= 0 && forts[i] == -1) {
                    ans = max(ans, j - i);
                }
            } else {
                i -= 1;
            }
        }
        
        return ans;
    }
};
