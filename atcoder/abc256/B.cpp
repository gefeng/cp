#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    array<int, 4> cnt{0};
    int ans = 0;
    for(int i = 0; i < N; i++) {
        array<int, 4> nxt{0};
        cnt[0] += 1;

        for(int j = 0; j < 4; j++) {
            if(j + A[i] < 4) {
                nxt[j + A[i]] += cnt[j];
            } else {
                ans += cnt[j];
            }
        }
        
        swap(cnt, nxt);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
