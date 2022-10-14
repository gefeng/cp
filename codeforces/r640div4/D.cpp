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
    
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt_move = 0;
    int cnt_a = 0;
    int cnt_b = 0;
    int pre = 0;
    int turn = 0;
    for(int l = 0, r = N - 1; l <= r; ) {
        int sum = 0;
        if(turn == 0) {
            while(l <= r && sum <= pre) {
                sum += A[l++]; 
            }
            cnt_a += sum;
        } else {
            while(l <= r && sum <= pre) {
                sum += A[r--];
            }
            cnt_b += sum;
        }
        pre = sum;
        turn ^= 1;
        cnt_move++;
    }

    cout << cnt_move << ' ' << cnt_a << ' ' << cnt_b << '\n';
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
