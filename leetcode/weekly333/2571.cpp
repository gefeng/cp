#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minOperations(int n) {
        vector<int> p_2;
        for(int i = 0, x = 1; i < 17 && x < 2 * n; i++) {
            p_2.push_back(x);
            x *= 2;
        }
        
        queue<int> q;
        q.emplace(n);
        
        int ans = 0;
        vector<bool> vis(n * 4, false);
        vis[n] = true;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int x = q.front();
                q.pop();
                if(x == 0) {
                    return ans;
                }

                
                for(int y : p_2) {
                    int nx = x + y;
                    if(abs(nx) < 2 * n && !vis[nx + 2 * n]) {
                        vis[nx + 2 * n] = true;
                        q.emplace(nx);
                    }
                    nx = x - y;
                    if(abs(nx) < 2 * n && !vis[nx + 2 * n]) {
                        vis[nx + 2 * n] = true;
                        q.emplace(nx);
                    }
                }
            }
            
            ans += 1;
        }
        
        return -1;
    }
};
