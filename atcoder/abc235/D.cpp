#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void run_case() {
    int A, N;
    cin >> A >> N;

    queue<int> q;
    set<int> seen;
    q.push(1);
    seen.insert(1);
    
    int ans = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int cur = q.front();
            q.pop();
            
            if(cur == N) {
                cout << ans << '\n';
                return;
            }

            int x = cur * A;
            if(x / N < 10 && seen.find(x) == seen.end()) {
                q.push(x);
                seen.insert(x);
            }

            if(cur >= 10 && cur % 10 != 0) {
                string s = to_string(cur);
                s = s.substr(s.length() - 1, 1) + s.substr(0, s.length() - 1);
                int y = stoi(s);
                if(seen.find(y) == seen.end()) {
                    q.push(y);
                    seen.insert(y);
                }
            }
        }
        ans += 1;
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
