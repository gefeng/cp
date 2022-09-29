#include <iostream>

using namespace std;
using LL = long long;

void run_case() {
    LL N;
    cin >> N;

    while(N != 1LL) {
        cout << N << ' ';
        if(N & 1LL) {
            N *= 3LL;
            N += 1LL;
        } else {
            N /= 2LL;
        }
    }

    cout << 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
