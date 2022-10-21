#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for(int k = N; k >= 0; k--) {
        int j = -1;
        for(int i = N - 1; i >= 0; i--) {
            if(A[i] <= k) {
                j = i;
                break;
            }
        }

        if(j + 1 >= k * 2 - 1) {
            j = k * 2 - 2;
            bool ok = true;
            for(int i = 1; i <= k; i++) {
                if(A[j - i + 1] > k - i + 1) {
                    ok = false;
                    break;
                }
            }

            if(ok) {
                cout << k << '\n';
                return;
            }
        }
    }

    cout << 0 << '\n';
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
