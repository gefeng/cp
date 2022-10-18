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
    string S, T;
    cin >> N >> S >> T;

    int hd_1 = 0;
    int hd_2 = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            hd_1++;
        }
        if(T[i] == '1') {
            hd_2++;
        }
    }

    string ans(N, '0');
    for(int i = N - 1; i >= 0; i--) {
        if(hd_1 == hd_2) {
            break;
        } 
        
        if(S[i] != T[i]) {
            if(hd_1 > hd_2) {
                if(S[i] == '1') {
                    ans[i] = '1';
                    hd_1--;
                    hd_2++;
                }
            } else {
                if(S[i] == '0') {
                    ans[i] = '1';
                    hd_1++;
                    hd_2--;
                } 
            }
        }
    }
    
    if(hd_1 == hd_2) {
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
