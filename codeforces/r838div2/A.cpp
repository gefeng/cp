#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] & 1) {
            cnt += 1;
        }
    }

    if(cnt % 2 == 0) {
        cout << 0 << '\n';
    } else {
        int ans = 2e9;
        for(int i = 0; i < N; i++) {
            if(A[i] & 1) {
                int x = A[i];
                int y = 0;
                while(x % 2 == 1) {
                    x /= 2;
                    y += 1;
                }

                ans = min(ans, y);
            }
        }

        for(int i = 0; i < N; i++) {
            if(A[i] % 2 == 0) {
                int x = A[i];
                int y = 0;
                while(x % 2 == 0) {
                    x /= 2;
                    y += 1;
                }
                
                ans = min(ans, y);
            }
        }

        cout << ans << '\n';
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
