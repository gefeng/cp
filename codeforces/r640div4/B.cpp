#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    if(K > N) {
        cout << "NO" << '\n';
        return;
    }

    if((N - K + 1) & 1) {
        cout << "YES" << '\n';
        for(int i = 0; i < K - 1; i++) {
            cout << 1 << ' ';
        }
        cout << N - K + 1 << '\n';
        return;
    } 

    int x = N - 2 * (K - 1);
    if(x >= 2 && x % 2 == 0) {
        cout << "YES" << '\n';
        for(int i = 0; i < K - 1; i++) {
            cout << 2 << ' ';
        }
        cout << N - 2 * (K - 1) << '\n';
        return;
    }

    cout << "NO" << '\n';
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
