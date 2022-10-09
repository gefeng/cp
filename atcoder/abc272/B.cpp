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

    vector<vector<int>> attend(N, vector<int>(M, 0));
    for(int i = 0; i < M; i++) {
        int K;
        cin >> K;
        for(int j = 0; j < K; j++) {
            int X;
            cin >> X;
            X--;
            attend[X][i] = 1;
        }
    } 
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            bool ok = false;
            if(i == j) continue;
            for(int k = 0; k < M; k++) {
                if(attend[i][k] == 1 && attend[j][k] == 1) {
                    ok = true;
                    break;
                }
            } 
            if(!ok) {
                cout << "No" << '\n';
                return;
            }
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
