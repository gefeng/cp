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
    bool equalFrequency(string word) {
        array<int, 26> cnt{0};
        
        for(char c : word) {
            cnt[c - 'a']++;
        }
        
        for(char c = 'a'; c <= 'z'; c++) {
            if(!cnt[c - 'a']) {
                continue;
            }
            
            cnt[c - 'a']--;
            
            bool ok = true;
            int f = 0;
            for(int i = 0; i < 26; i++) {
                if(cnt[i]) {
                    if(f && f != cnt[i]) {
                        ok = false;
                        break;
                    }   
                    f = cnt[i];
                }
            }
            
            if(ok) {
                return true;
            }
            cnt[c - 'a']++;
        }
        
        return false;
    }
};
