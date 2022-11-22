#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    vector<int> A(10);
    for(int i = 0; i < 10; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for(int i = 0; i < 3; i++) {
        ans = A[ans];
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
