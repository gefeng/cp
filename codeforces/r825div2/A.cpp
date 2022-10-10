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
    vector<int> B(N, 0);
    int cnt_a_1 = 0;
    int cnt_b_1 = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cnt_a_1 += A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
        cnt_b_1 += B[i];
    }

    
    if(cnt_a_1 == cnt_b_1) {
        cout << (A == B ? 0 : 1) << '\n';
        return;
    }

    if(cnt_a_1 < cnt_b_1) {
        int cnt = 0;
        int d = cnt_b_1 - cnt_a_1;
        for(int i = 0; i < N && d; i++) {
            if(A[i] == 0 && B[i] == 1) {
                d--;
                A[i] = 1;
                cnt++;
            } 
        }
        
        cnt += A == B ? 0 : 1;
        cout << cnt << '\n';
    } else {
        int cnt = 0;
        int d = cnt_a_1 - cnt_b_1;
        for(int i = 0; i < N && d; i++) {
            if(A[i] == 1 && B[i] == 0) {
                d--;
                A[i] = 0;
                cnt++;
            }
        }
        cnt += A == B ? 0 : 1;
        cout << cnt << '\n';
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
