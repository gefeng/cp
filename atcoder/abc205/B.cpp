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

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    set<int> s;
    for(int i = 0; i < N; i++) {
        if(A[i] < 1 && A[i] > N) {
            cout << "No" << '\n';
            return;
        }
        s.insert(A[i]);
    }

    cout << (s.size() == N ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
