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

    map<int, int> m;
    for(int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        m[A] += 1;
        m[A + B] -= 1;
    }

    vector<int> ans(N + 1, 0);
    int pre = 1;
    int sum = 0;
    for(auto& [k, v] : m) {
        ans[sum] += k - pre;
        sum += v;
        pre = k;
    }

    ans[sum] += 1;

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " \n"[i == N];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
