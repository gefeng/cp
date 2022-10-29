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
    string oddString(vector<string>& words) {
        int n = words.size();
        int m = words[0].length();
        vector<vector<int>> diff(n, vector<int>(m - 1, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                diff[i][j - 1] = words[i][j] - words[i][j - 1];
            }    
        }
        
        int cnt = 0;
        string ans = "";
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m - 1; j++) {
                if(diff[i][j] != diff[0][j]) {
                    ans = words[i];
                    cnt++;
                    break;
                }
            }
        }
        
        if(cnt == n - 1) {
            return words[0];
        } else {
            return ans;
        }
    }
};
