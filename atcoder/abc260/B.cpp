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
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<array<int, 3>> A(N, {0});
    for(int i = 0; i < N; i++) {
        cin >> A[i][0];
    }

    for(int i = 0; i < N; i++) {
        cin >> A[i][1];
        A[i][2] = i;
    }

    set<int> passed;
    auto cmp_1 = [](const auto& a, const auto& b) {
        if(a[0] == b[0]) {
            return a[2] > b[2];
        } 
        return a[0] < b[0];
    };

    sort(A.begin(), A.end(), cmp_1);
    for(int i = N - 1; i >= 0 && X; i--, X--) {
        passed.insert(A[i][2]);
    }

    auto cmp_2 = [](const auto& a, const auto& b) {
        if(a[1] == b[1]) {
            return a[2] > b[2];
        }
        return a[1] < b[1];
    };

    sort(A.begin(), A.end(), cmp_2);
    for(int i = N - 1; i >= 0 && Y; i--) {
        int id = A[i][2];
        if(passed.find(id) == passed.end()) {
            passed.insert(id);
            Y -= 1;
        }
    }

    auto cmp_3 = [](const auto& a, const auto& b) {
        if(a[0] + a[1] == b[0] + b[1]) {
            return a[2] > b[2];
        }

        return a[0] + a[1] < b[0] + b[1];
    };

    sort(A.begin(), A.end(), cmp_3);
    for(int i = N - 1; i >= 0 && Z; i--) {
        int id = A[i][2];
        if(passed.find(id) == passed.end()) {
            passed.insert(id);
            Z -= 1;
        }
    }

    for(int x : passed) {
        cout << x + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
