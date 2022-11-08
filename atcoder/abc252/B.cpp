#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    set<int> s;
    for(int i = 0; i < K; i++) {
        int X;
        cin >> X;
        s.insert(X);
    }

    int max_v = 0;
    for(int x : A) {
        max_v = max(max_v, x);
    }

    for(int i = 0; i < N; i++) {
        if(A[i] == max_v && s.find(i + 1) != s.end()) {
            cout << "Yes" << '\n';
            return;
        }
    }

    cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
