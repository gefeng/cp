#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N, 0);
    vector<int> B(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        auto it = lower_bound(B.begin(), B.end(), A[i]);
        cout << *it - A[i] << " \n"[i == N - 1];
    }

    vector<int> ans_max(N, 0);
    auto last = B.end();
    for(int i = N - 1; i >= 0; i--) {
        ans_max[i] = *(last - 1) - A[i];
        auto it = lower_bound(B.begin(), last, A[i]);
         
        if(it - B.begin() == i) {
            last = it;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << ans_max[i] << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
