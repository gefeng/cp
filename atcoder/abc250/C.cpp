#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<int> pos(N);
    vector<int> val(N);
    for(int i = 0; i < N; i++) {
        pos[i] = i;
        val[i] = i;
    }

    for(int i = 0; i < Q; i++) {
        int X;
        cin >> X;

        X -= 1;
        
        if(pos[X] == N - 1) {
            pos[X] = N - 2; 
            
            int v = val[N - 2];
            pos[v] = N - 1;
            
            val[N - 2] = X;
            val[N - 1] = v;
        } else {
            pos[X] += 1;
            
            int v = val[pos[X]];
            pos[v] = pos[X] - 1;

            val[pos[X]] = X;
            val[pos[X] - 1] = v;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << val[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
