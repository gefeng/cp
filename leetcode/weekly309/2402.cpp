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
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used;
        priority_queue<int, vector<int>, greater<int>> free;
        
        sort(meetings.begin(), meetings.end());
        
        for(int i = 0; i < n; i++) {
            free.emplace(i);
        }
        
        vector<int> cnt(n, 0);
        long long time = 0;
        for(vector<int>& m : meetings) {
            time = max(time, (long long)m[0]);
        
            while(!used.empty() && used.top().first <= time) {
                pair<int, int> cur = used.top();
                used.pop();
                free.emplace(cur.second);
            }
            
            int room = free.top();
            free.pop();
            
            long long nxt_available = time + m[1] - m[0];
            
            cnt[room]++;
            used.emplace(nxt_available, room);
            
            if(free.empty()) {
                time = used.top().first;
            }
        }
        
        int ans = 0;
        int max_v = 0;
        for(int i = 0; i < n; i++) {
            if(cnt[i] > max_v) {
                max_v = cnt[i];
                ans = i;
            }
        }
        
        return ans;
    }
};
