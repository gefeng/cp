#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, K;
    cin >> N >> K;

    LL a = 1LL * N;
    for(int i = 1; i <= K; i++) {
        array<int, 10> f{0};
        LL x = a;
        while(x) {
            f[x % 10] += 1;
            x /= 10;
        }

        LL b = 0LL;
        LL c = 0LL;
        for(int i = 9; i >= 0; i--) {
            int cnt = f[i];
            while(cnt) {
                b = b * 10LL + i;
                cnt -= 1;
            }
            cnt = f[i];
        }

        for(int i = 0; i < 10; i++) {
            int cnt = f[i];
            while(cnt) {
                c = c * 10LL + i;
                cnt -= 1;
            }
        }

        a = b - c;
    } 

    cout << a << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
