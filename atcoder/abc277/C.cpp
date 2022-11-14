#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        if(A[i].first > A[i].second) {
            swap(A[i].first, A[i].second);
        }
    }

    sort(A.begin(), A.end());

    int ans = 1;
    for(auto& p : A) {
        if(p.first <= ans) {
            ans = max(ans, p.second);
        } else {
            break;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
