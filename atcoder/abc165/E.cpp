#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<bool> exclude(N + 1, false);

    int flag = 0;
    for(int l = 0, r = N - 1; M; ) {
        int d = r - l;
        if(d * 2 == N || exclude[d]) {
            if(flag == 0) {
                l += 1;
            } else {
                r -= 1;
            }
            flag ^= 1;
        } else {
            cout << l + 1 << ' ' << r + 1 << '\n';
            l += 1;
            r -= 1;
            M -= 1;
            exclude[N - d] = true;
            exclude[d] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
