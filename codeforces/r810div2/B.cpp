#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n + 1, 0);
    vector<int> D(n + 1, 0);
    vector<pair<int, int>> B;
    
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        D[x]++;
        D[y]++;
        B.emplace_back(x, y);
    }
    
    int ans = 0;
    if(m % 2 != 0) {
        int min_v = 20000;

        for(auto& p : B) {
            int x = p.first;
            int y = p.second;

            if(D[x] % 2 == 1) {
                min_v = min(min_v, A[x]);
            }
            if(D[y] % 2 == 1) {
                min_v = min(min_v, A[y]);
            } 
            if(D[x] % 2 == 0 && D[y] % 2 == 0) {
                min_v = min(min_v, A[x] + A[y]);
            }
        }

        ans = min_v;
    }
   
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
