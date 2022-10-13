#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run_case() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N, 0);
    vector<int> B(M, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int ans = 0;
    for(int i = 0, j = 0; i < N && j < M; ) {
        if(A[i] >= B[j] - K && A[i] <= B[j] + K) {
            ans++;
            i++;
            j++;
        } else if(A[i] > B[j] + K) {
            i++; 
        } else {
            j++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
