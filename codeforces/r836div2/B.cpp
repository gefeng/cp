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

    if(N & 1) {
        for(int i = 0; i < N; i++) {
            cout << 1 << " \n"[i == N - 1];
        } 
    } else {
        if(N == 2) {
            cout << 1 << ' ' << 3 << '\n';
            return;
        }
        int sum = 2 * N;
        int x = (sum - 4) / (N - 2);

        for(int i = 0; i < N - 2; i++) {
            cout << x << ' ';
        }

        cout << 1 << ' ' << 3 << '\n';
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
