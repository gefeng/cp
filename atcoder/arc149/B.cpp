#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int lis(vector<int>& A) {
    int n = A.size();

    vector<int> lis;
    lis.reserve(n);
    for(int i = 0; i < n; i++) {
        if(lis.empty() || lis.back() < A[i]) {
            lis.push_back(A[i]);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), A[i]);
            *it = A[i];
        }
    }
    return lis.size();
}

void run_case() {
    int N;
    cin >> N;

    vector<pair<int, int>> A(N, {0, 0});

    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        cin >> A[i].second;
    }

    sort(A.begin(), A.end());

    vector<int> B(N, 0);
    for(int i = 0; i < N; i++) {
        B[i] = A[i].second;
    }

    cout << N + lis(B) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
