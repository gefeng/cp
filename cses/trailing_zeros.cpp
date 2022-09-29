#include <iostream>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    int ans = 0;
    while(N) {
        ans += N / 5;
        N /= 5;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
