#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    unordered_map<int, int> seen;
    seen.reserve(N);
    for(int i = 0; i < N; i++) {
        if(seen.find(X - A[i]) != seen.end()) {
            cout << seen[X - A[i]] + 1 << ' ' << i + 1 << '\n';
            return;
        }

        seen[A[i]] = i;
    }

    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
