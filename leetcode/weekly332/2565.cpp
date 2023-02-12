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
    int minimumScore(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<int> save1(m, -2);
        for(int i = 0, j = 0; i < n && j < m; ) {
            if(s[i] == t[j]) {
                save1[j] = i;
                i += 1;
                j += 1;
            } else {
                i += 1;
            }
        }
        
        vector<int> save2(m, -2);
        for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; ) {
            if(s[i] == t[j]) {
                save2[j] = i;
                i -= 1;
                j -= 1;
            } else {
                i -= 1;
            }
        }
        
        int lo = 0;
        int hi = m;
        int ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            bool ok = false;
            for(int l = -1, r = l + mid + 1; r <= m; l++, r++) {
                int i = l == -1 ? -1 : save1[l];
                int j = r == m ? n : save2[r];
                if(i != -2 && j != -2 && i < j) {
                    ok = true;
                    break;
                }
            }
            
            if(ok) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
