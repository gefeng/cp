#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;

    int ans = 0;
    int l = 0;
    int r = 0;
    for(int i = 0; i < N; i++) {
        int v;
        cin >> v;
        if(i == 0) {
            l = v - X; 
            r = v + X;
        } else {
            if((v - X <= r && v + X >= l) || (v + X >= l && v - X <= r)) {
                l = max(l, v - X);
                r = min(r, v + X);
            } else {
                l = v - X;
                r = v + X;
                ans++;
            }
        }
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
