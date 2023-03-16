#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAX = (int)1e6;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> seen(MAX + 1, 0);
    for(int x : A) {
        seen[x] += 1;
    }

    int ans = 0;
    for(int x : A) {
        if(seen[x] > 1) {
            continue;
        }
        if(seen[1] && x != 1) {
            continue;
        }

        bool ok = true;
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                if(seen[f]) {
                    ok = false;
                    break;
                }
                if(x / f != f && seen[x / f]) {
                    ok = false;
                    break;
                }
            }
        }

        if(ok) {
            ans += 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
