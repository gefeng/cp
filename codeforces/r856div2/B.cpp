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

    for(int i = 0; i < N - 1; i++) {
        if(A[i] == 1) { 
            A[i] += 1;
        }
    }

    for(int i = 1; i < N; i++) {
        if(A[i - 1] % 2 == 0) {
            if(A[i] % A[i - 1] == 0) {
                A[i] += 1;
            }
        } else {
            if(A[i] % A[i - 1] == 0) {
                A[i] += 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << A[i] << " \n"[i == N - 1];
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
