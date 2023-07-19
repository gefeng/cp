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
    for(int x : A) {
        if(x == 0) {
            cnt += 1;
        }
    }

    if(cnt <= (N + 1) / 2) {
        cout << 0 << '\n';
    } else {
        cnt = 0;
        for(int x : A) {
            if(x == 1) {
                cnt += 1;
            }
        }

        if(cnt) {
            cnt = 0;
            for(int x : A) {
                if(x > 1) {
                    cnt += 1;
                }
            }
            if(cnt == 0) {
                cout << 2 << '\n';
            } else {
                cout << 1 << '\n';
            }
        } else {
            cout << 1 << '\n';
        }
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
