#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
using LL = long long;

void run_case() {
    int K;
    cin >> K;

    string S, T;
    cin >> S >> T;

    array<int, 10> h1{0};
    array<int, 10> h2{0};
    for(int i = 0; i < 4; i++) {
        h1[S[i] - '0'] += 1;
        h2[T[i] - '0'] += 1;
    }
    
    array<int, 6> ten = {1, 10, 100, 1000, 10000, 100000};

    auto f = [&](const auto& a) -> int {
        int res = 0;
        for(int i = 1; i < 10; i++) {
            res += i * ten[a[i]]; 
        }
        return res;
    };

    LL tot = 1LL * (9 * K - 8) * (9 * K - 9);
    LL cnt = 0LL;
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            h1[i] += 1;
            h2[j] += 1;
            if(i == j) {
                if(h1[i] + h2[i] <= K && f(h1) > f(h2)) {
                    LL x = K - h1[i] - h2[i] + 2;
                    cnt += x * (x - 1LL);
                }
            } else {
                if(h1[i] + h2[i] <= K && h1[j] + h2[j] <= K && f(h1) > f(h2)) {
                    LL x = K - h1[i] - h2[i] + 1;
                    LL y = K - h1[j] - h2[j] + 1;
                    cnt += x * y;
                }
            }
            h1[i] -= 1;
            h2[j] -= 1;
        } 
    }

    cout << setprecision(20) << (double)cnt / tot << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
