#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(M, 0);
    for(int i = 0; i < M; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<int> D;
    for(int i = 1; i < M; i++) {
        D.push_back(A[i] - A[i - 1] - 1);
    }
    D.push_back(N - A[M - 1] + A[0] - 1);

    sort(D.begin(), D.end(), greater<int>());

    int save = 0;
    int past = 0;
    for(int d : D) {
        d = max(0, d - 2 * past);
        if(d) {
            save += max(1, d - 1);
        }
        past += 2;
    }

    cout << N - save << '\n';
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
