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
 
    int min_v = 1;
    int max_v = N;
    for(int l = 0, r = N - 1; l < r; ) {
        if(A[l] != min_v && A[l] != max_v && A[r] != min_v && A[r] != max_v) {
            cout << l + 1 << ' ' << r + 1 << '\n';
            return;
        }
 
        if(A[l] == min_v && A[r] == max_v) {
            l += 1;
            r -= 1;
            min_v += 1;
            max_v -= 1;
        } else if(A[l] == max_v && A[r] == min_v) {
            l += 1;
            r -= 1;
            min_v += 1;
            max_v -= 1;
        } else if(A[l] == min_v) {
            l += 1;
            min_v += 1;
        } else if(A[l] == max_v) {
            l += 1;
            max_v -= 1;
        } else if(A[r] == min_v) {
            r -= 1;
            min_v += 1;
        } else {
            r -= 1;
            max_v -= 1;
        }
    }
 
    cout << -1 << '\n';
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
