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
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        
        bool ok = false;
        for(string s : words) {
            if(s == target) {
                ok = true;
                break;
            }
        }
        
        if(!ok) {
            return -1;
        }
        
        int d1 = 0;
        for(int i = 0, j = startIndex; i < n; i++, j = (j + 1) % n) {
            d1 += 1;
            if(target == words[j]) {
                break;
            }
        }
        
        int d2 = 0;
        for(int i = 0, j = startIndex; i < n; i++, j = (j - 1 + n) % n) {
            d2 += 1;
            if(target == words[j]) {
                break;
            }
        }
        
        return min(d1, d2) - 1;
    }
};
