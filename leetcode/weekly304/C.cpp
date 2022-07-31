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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        unordered_set<int> a;
        unordered_set<int> b;
        vector<int> d1(n, 0);
        vector<int> d2(n, 0);

        vector<bool> vis(n, 0);
        int x = node1;
        int d = 0;
        while(x != -1 && !vis[x]) {
            a.insert(x);
            d1[x] = d;
            vis[x] = true;
            x = edges[x];
            d++;
        }

        vis = vector<bool>(n, 0);
        x = node2;
        d = 0;
        while(x != -1 && !vis[x]) {
            b.insert(x);
            d2[x] = d;
            vis[x] = true;
            x = edges[x];
            d++;
        }

        int ans = -1;
        int min_d = 1e9;
        for(int v : a) {
            if(b.count(v)) {
                int max_d = max(d1[v], d2[v]);
                if(ans == -1) {
                    min_d = max_d;
                    ans = v;
                } else {
                    if(max_d < min_d) {
                        ans = v;
                        min_d = max_d;
                    } else if(max_d == min_d && ans > v) {
                        ans = v;
                    }
                }
            }
        }

        return ans;
    }
};
