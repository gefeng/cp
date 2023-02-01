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

    vector<pair<int, string>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].second >> A[i].first;
    }

    sort(A.begin(), A.end());

    cout << A[N - 2].second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
