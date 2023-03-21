#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<int, int> m;
    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        if(m.find(i - A[i]) != m.end()) {
            ans += m[i - A[i]];
        }

        m[A[i] + i] += 1;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
