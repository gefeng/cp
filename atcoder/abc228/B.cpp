#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;

    X -= 1;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= 1;
    }
    
    vector<bool> know(N, false);
    int cur = X;
    int ans = 0;
    while(!know[cur]) {
        know[cur] = true;
        cur = A[cur];
        ans += 1;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
