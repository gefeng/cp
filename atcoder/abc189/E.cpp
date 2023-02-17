#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

vector<vector<LL>> mul(vector<vector<LL>>& m1, vector<vector<LL>>& m2) {
    int p = m1.size();
    int q = m1[0].size();
    int r = m2[0].size();

    vector<vector<LL>> m(p, vector<LL>(r, 0LL));

    for(int i = 0; i < p; i++) {
        for(int j = 0; j < r; j++) {
            for(int k = 0; k < q; k++) {
                m[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return m;
}

void run_case() {
    int N;
    cin >> N;

    vector<pair<LL, LL>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    int M;
    cin >> M;
    
    vector<vector<vector<LL>>> seq(1, vector<vector<LL>>(3, vector<LL>(3, 0LL)));
    
    for(int i = 0; i < 3; i++) {
        seq[0][i][i] = 1LL;
    }

    for(int i = 1; i <= M; i++) {
        int T;
        cin >> T;

        vector<vector<LL>> mat(3, vector<LL>(3, 0LL));

        LL P;
        switch (T) {
            case 1:
                // rotation matrix - rotate 90 degrees clockwise
                mat[0][1] = 1LL;
                mat[1][0] = -1LL;
                break;
            case 2:
                // rotation matrix - rotate 90 degress anti-clockwise
                mat[0][1] = -1LL;
                mat[1][0] = 1LL;
                break;
            case 3:
                // rotation matrix - reflection against x = p
                cin >> P;
                mat[0][0] = -1LL;
                mat[0][2] = 2LL * P;
                mat[1][1] = 1LL;
                break;
            case 4:
                // rotation matrix - reflection against y = p
                cin >> P;
                mat[0][0] = 1LL;
                mat[1][1] = -1LL;
                mat[1][2] = 2LL * P;
                break;
        }
        mat[2][2] = 1LL;
        seq.push_back(mul(mat, seq[i - 1]));
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int O, I;
        cin >> O >> I;
        I -= 1;

        vector<vector<LL>> v(3, vector<LL>(1, 0LL));
        v[0][0] = A[I].first;
        v[1][0] = A[I].second;
        v[2][0] = 1LL; 
        vector<vector<LL>> res = mul(seq[O], v);

        cout << res[0][0] << ' ' << res[1][0] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
