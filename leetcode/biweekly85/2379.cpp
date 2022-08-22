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
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int ans = 100;
        int cnt = 0;
        for(int i = 0, j = 0; j < n; j++) {
            cnt += blocks[j] == 'W' ? 1 : 0;
            
            if(j - i + 1 > k) {
                cnt -= blocks[i++] == 'W' ? 1 : 0;
            } 
            
            if(j - i + 1 == k) {
                ans = min(ans, cnt);
            }
        }
        
        return ans;
    }
};
