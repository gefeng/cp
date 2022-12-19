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
    
    
    A.erase(unique(A.begin(), A.end()), A.end()); 
    N = A.size();

    int x = 0;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            x = max(x, (A[i] + A[i - 1] + 1) / 2);
        } 
    }
    
    for(int i = 1; i < N; i++) {
        if(abs(A[i] - x) < abs(A[i - 1] - x)) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << x << '\n';
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
