#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    int N, H, M;
    cin >> N >> H >> M;

    int ans = 24 * 60;
    int sleep_t = H * 60 + M;
    for(int i = 0; i < N; i++) {
        int h, m;
        cin >> h >> m;
         
        int alarm_t = h * 60 + m;
        int d = (alarm_t - sleep_t + 24 * 60) % (24 * 60);

        ans = min(ans, d);
    }

    cout << ans / 60 << ' ' << ans % 60 << '\n';
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
