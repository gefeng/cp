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
    int minLength(std::string s, int numOps) {
        int n = s.size();
        int ans = -1;
        
        auto solve = [&](int st) {
            int cnt = 0;
            for(int i = 0, j = st; i < n; i++, j ^= 1) {
                if(s[i] - '0' != j) {
                    cnt += 1;
                }
            }
            return cnt;
        };
        
        if(solve(0) <= numOps || solve(1) <= numOps) {
            return 1;
        }
        
        int lo = 2;
        int hi = n;
        
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            int cnt = 0;
            for(int i = 0; i < n; ) {
                int j = i;
                while(i < n && s[i] == s[j]) {
                    i += 1;
                }
                
                int len = i - j;
                if(len == 1) {
                    continue;
                }
                
                if(len == 2 && mid == 1) {
                    if(j == 0 || i == n) {
                        cnt += 1;
                    } else {
                        cnt += numOps + 1;
                    }
                    continue;
                }
                
                for(int k = j; k < i; ) {
                    if(k + mid < i) {
                        cnt += 1;
                        k += mid + 1;
                    } else {
                        break;
                    }
                }
            }
            
            if(cnt <= numOps) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
