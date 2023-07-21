#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    int M;
    cin >> M;

    vector<int> R1(M, 0);
    vector<int> R2(M, 0);
    for(int i = 0; i < M; i++) {
        cin >> R1[i];
        R1[i]++;
    }

    for(int i = 0; i < M; i++) {
        cin >> R2[i];
        R2[i]++;
    }

    R1[0] = 0;

    // pre-calculate the minimum waiting time to complete a 
    // suffix traversal start from column j ending with column j
    // a_i <= t + k - 1 => t >= a_i - k + 1

    // clockwise suffix
    vector<int> t_wait_suffix1(M, 0);
    // anti-clockwise suffix
    vector<int> t_wait_suffix2(M, 0);
    int max1 = -1;
    int max2 = -1;
    int max1_reverse = -1;
    int max2_reverse = -1;
    for(int i = M - 1; i >= 0; i--) {
        max1 = max(max1, R1[i]);
        max2 = max(max2, R2[i]);
        max1_reverse = max(max1_reverse, max1 - (M - i) * 2 + 1);
        max2_reverse = max(max2_reverse, max2 - (M - i) * 2 + 1);
        t_wait_suffix1[i] = max(max1, max2_reverse) - 1;
        t_wait_suffix2[i] = max(max2, max1_reverse) - 1;
        max1--;
        max2--;
        max1_reverse--;
        max2_reverse--;
    } 

    int ans = max(-1, t_wait_suffix1[0]) + 2 * M;
    int cur = -1;
    int dir = 0;
    for(int i = 0; i < M; i++) {
        if(!dir) {
            cur++;
            cur = max(cur, R1[i]);
            cur++;
            cur = max(cur, R2[i]);
            if(i + 1 < M) {
                ans = min(ans, max(cur, t_wait_suffix2[i + 1]) + 2 * (M - i - 1));
            } else {
                ans = min(ans, cur);
            }
        } else {
            cur++;
            cur = max(cur, R2[i]);
            cur++;
            cur = max(cur, R1[i]);
            if(i + 1 < M) {
                ans = min(ans, max(cur, t_wait_suffix1[i + 1]) + 2 * (M - i - 1));
            } else {
                ans = min(ans, cur);
            }
        }

        dir ^= 1;
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
