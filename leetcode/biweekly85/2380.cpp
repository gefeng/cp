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
    int secondsToRemoveOccurrences(string s) {
        int ans = 0;
        int n = s.length();
        
        while(true) {
            bool flag = false;
            string nxt = s;
            for(int i = 0; i < n - 1; i++) {
                if(s[i] == '0' && s[i + 1] == '1') {
                    nxt[i] = '1';
                    nxt[i + 1] = '0';
                    i++;
                    flag = true;
                } 
            }
            
            if(!flag) {
                break;
            }
            
            s = nxt;
            ans++;
        }
        
        return ans;
    }
};
