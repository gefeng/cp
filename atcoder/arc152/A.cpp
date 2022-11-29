#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, L;
    cin >> N >> L;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if(L <= 2) {
        cout << "Yes" << '\n';
        return;
    }
    
    int i = 0;
    int p = 0;
    while(p < L) {
        if(A[i] == 1) {
            if(p == L - 1) {
                p += 1;
            } else {
                p += 2;
            }
        } else {
            if(p == L - 1) {
                cout << "No" << '\n';
                return;
            }
            if(p == L - 2) {
                p += 2;
            } else {
                p += 3;
            }
        }
        i += 1;
    } 

    while(i < N) {
        if(A[i] == 2) {
            cout << "No" << '\n';
            return;
        }
        i += 1;
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
