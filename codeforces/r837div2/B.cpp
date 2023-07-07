#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N, N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        
        U -= 1;
        V -= 1;

        if(U > V) {
            swap(U, V);
        }

        A[U] = min(A[U], V);
    }

    LL ans = 1LL;
    int r = N;
    for(int i = N - 2; i >= 0; i--) {
        r = min(r, A[i]); 
        ans += r - i;
    }

    cout << ans << '\n';
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
