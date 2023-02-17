#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    int cnt_s = 0;
    for(int i = 1; i < N; i++) {
        if(S[i] == S[i - 1]) {
            cnt_s += 1;
        } 
    }

    if(cnt_s > 1) {
        cout << "NO" << '\n';
        return;
    } 

    int cnt_t = 0;
    for(int i = 1; i < M; i++) {
        if(T[i] == T[i - 1]) {
            cnt_t += 1;
        }
    }

    if(cnt_t > 1) {
        cout << "NO" << '\n';
        return;
    }

    if(cnt_s == 0 && cnt_t == 0) {
        cout << "YES" << '\n';
        return;
    }

    if(cnt_s == 1 && cnt_t == 1) {
        cout << "NO" << '\n';
        return;
    }

    cout << (S[N - 1] != T[M - 1] ? "YES" : "NO") << '\n';
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
