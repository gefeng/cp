#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> P(N + 1, 0);
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        P[X] = i;
    }

    int ans = 0;
    int cur = 1;
    while(cur <= N) {
        int cur_pos = -1;
        while(P[cur] > cur_pos) {
            cur_pos = P[cur];
            cur++;
        }
        ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
