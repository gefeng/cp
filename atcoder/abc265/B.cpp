#include <iostream>
#include <array>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, M, T;
    cin >> N >> M >> T;

    vector<int> A(N - 1, 0);
    for(int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }

    vector<int> B(N + 1, 0);
    for(int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;

        B[X] += Y;
    }

    LL t = T;
    for(int i = 1; i <= N; i++) {
        t += B[i];
        
        t -= A[i - 1];

        if(t <= 0) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
