#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> permutation(N, 0);
    for(int i = 0; i < N; i++) {
        permutation[i] = i + 1;
    }

    cout << N << '\n';
    for(int i = 0, k = N - 1; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << permutation[j] << " \n"[j == N - 1];
        }

        swap(permutation[k], permutation[k - 1]);
        k--;
    }
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
