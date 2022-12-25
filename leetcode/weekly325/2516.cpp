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
    int takeCharacters(string s, int k) {
        int n = s.length();
        int ans = n;
        
        if(k == 0) {
            return 0;
        }
        
        array<int, 3> cnt{0};
        for(int i = 0; i < n; i++) {
            cnt[s[i] - 'a'] += 1;
        }
        
        for(int i = 0; i < 3; i++) {
            if(cnt[i] < k) {
                return -1;
            }
        }
        
        auto encode = [&](const auto& a) {
            return 1LL * a[0] * k * k + 1LL * a[1] * k + a[2];
        };
        
        vector<vector<int>> save(k + 1, vector<int>(3, -1));
        cnt.fill(0);
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(cnt[c] < k) {
                cnt[c] += 1;
                save[cnt[c]][c] = i + 1;
            }
        }
        
        cnt.fill(0);
        for(int i = 0; i <= n; i++) {
            int x = 0;
            for(int j = 0; j < 3; j++) {
                int need = k - cnt[j];
                if(need) {
                    x = max(x, save[need][j]);
                }
            }
            
            ans = min(ans, x + i);
            
            if(i != n) {
                int c = s[n - i - 1] - 'a';
                if(cnt[c] < k) {
                    cnt[c] += 1;
                }
            }
        }
        
        return ans;
    }
};
