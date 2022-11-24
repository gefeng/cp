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
 
    if(N <= 2) {
        cout << N << '\n';
        return;
    }
 
    for(int i = 0; i < N; i++) {
        int l = (i - 1 + N) % N;
        int r = (i + 1) % N;
        if(A[l] != A[r]) {
            cout << N << '\n';
            return;
        }
    }
 
    cout << (N - 2) / 2 + 2 << '\n';
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
