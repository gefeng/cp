#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    array<int, 3> A;
    for(int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    array<array<int, 4>, 4> D;
    D[1][2] = A[0];
    D[2][1] = A[0];
    D[2][3] = A[1];
    D[3][2] = A[1];
    D[1][3] = A[2];
    D[3][1] = A[2];

    for(int i = 1; i < 4; i++) {
        vector<int> children;
        int sum = 0;
        for(int j = 1; j < 4; j++) {
            if(i != j) {
                children.push_back(j);
                sum += D[i][j];
            }
        }

        if(sum == D[children[0]][children[1]] && sum < N) {
            cout << "YES" << '\n'; 

            int d = D[i][children[0]];
            int parent = i;
            int cur_node = 4;
            while(d > 1) {
                cout << parent << ' ' << cur_node << '\n';
                parent = cur_node++;
                d--;
            }
            
            cout << parent << ' ' << children[0] << '\n';
            
            d = D[i][children[1]];
            parent = i;
            while(d > 1) {
                cout << parent << ' ' << cur_node << '\n';
                parent = cur_node++;
                d--;
            }

            cout << parent << ' ' << children[1] << '\n';

            while(cur_node <= N) {
                cout << i << ' ' << cur_node++ << '\n';
            }

            return;
        }
    }

    for(int i = 1; i < 4; i++) {
        int res = 0;
        vector<int> children;
        for(int j = 1; j < 4; j++) {
            if(i != j) {
                children.push_back(j); 
                res += D[i][j];
            }
        }
        
        res -= D[children[0]][children[1]]; 
        
        if(res > 0 && res % 2 == 0 && res / 2 <= N - 3 && 
                res / 2 <= D[i][children[0]] && res / 2 <= D[i][children[1]] &&
                res / 2 + D[children[0]][children[1]] < N) {
            cout << "YES" << '\n';
            res /= 2;

            int parent = i;
            int cur_node = 4;
            int left = res;
            while(left) {
                cout << parent << ' ' << cur_node << '\n';
                parent = cur_node++;
                left--;
            }

            int d = D[i][children[0]] - res;
            int sub_root = parent;
            while(d > 1) {
                cout << parent << ' ' << cur_node << '\n';
                parent = cur_node++;
                d--;
            }
            cout << parent << ' ' << children[0] << '\n';

            d = D[i][children[1]] - res;
            parent = sub_root;
            while(d > 1) {
                cout << parent << ' ' << cur_node << '\n';
                parent = cur_node++;
                d--;
            }
            cout << parent << ' ' << children[1] << '\n';

            while(cur_node <= N) {
                cout << i << ' ' << cur_node++ << '\n';
            }
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
