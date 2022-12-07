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
    int N;
    cin >> N;

    set<vector<int>> s;
    for(int i = 0; i < N; i++) {
        int L;
        cin >> L;

        vector<int> A(L);
        for(int j = 0; j < L; j++) {
            cin >> A[j];
        }
        s.insert(A);
    }

    cout << s.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
