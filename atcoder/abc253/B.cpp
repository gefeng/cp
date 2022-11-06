#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int M, N;
    cin >> M >> N;

    int sr = -1;
    int sc = -1;
    int tr = -1;
    int tc = -1;
    for(int i = 0; i < M; i++) {
        string S;
        cin >> S;

        for(int j = 0; j < N; j++) {
            if(S[j] == 'o') {
                if(sr == -1) {
                    sr = i;
                    sc = j;
                } else {
                    tr = i;
                    tc = j;
                }
            }
        }
    }
    
    cout << abs(sr - tr) + abs(sc - tc) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
