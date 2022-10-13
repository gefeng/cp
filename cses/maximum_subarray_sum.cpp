#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = A[0];
    LL sum = 0LL;
    for(int x : A) {
        sum += x;
        ans = max(ans, sum);
        sum = max(sum, 0LL);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
