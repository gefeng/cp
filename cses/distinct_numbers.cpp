#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int ans = 1;
    for(int i = 1; i < N; i++) {
        if(A[i] != A[i - 1]) {
            ans++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
