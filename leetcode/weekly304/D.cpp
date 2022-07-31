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
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int ans = -1;

        vector<bool> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(vis[i]) {
                continue;
            }

            unordered_set<int> seen;
            int head = -1;
            int cur = i;
            while(true) {
                if(cur == -1 || vis[cur]) {
                    break;
                }
                if(seen.count(cur)) {
                    head = cur;
                    break;
                }

                seen.insert(cur);
                cur = edges[cur];
            }

            if(head != -1) {
                int len = 1;
                cur = edges[head];
                while(cur != head) {
                    cur = edges[cur];
                    len++;
                }
                ans = max(ans, len);
            }

            for(int x : seen) {
                vis[x] = true;
            }
        }

        return ans;
    }
};
