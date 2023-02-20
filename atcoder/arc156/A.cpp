#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            cnt += 1;
        }
    }

    if(cnt == 0) {
        cout << 0 << '\n';
        return;
    }

    if(cnt % 2 == 1 || S == "11" || S == "011" || S == "110") {
        cout << -1 << '\n';
        return;
    }

    if(cnt > 2) {
        cout << cnt / 2 << '\n';
    } else {
        int p1 = -1;
        int p2 = -1;
        for(int i = 0; i < N; i++) {
            if(S[i] == '1') {
                if(p1 == -1) {
                    p1 = i;
                } else {
                    p2 = i;
                }
            }
        }

        if(p2 - p1 > 1) {
            cout << 1 << '\n';
            return;
        }

        if(p1 > 1 || N - p2 - 1 > 1) {
            cout << 2 << '\n';
        } else {
            cout << 3 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
