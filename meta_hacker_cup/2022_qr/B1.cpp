#include <iostream>
#include <fstream>
#include <vector>
#include <array>

using namespace std;

ifstream in;
ofstream out;

void run_case(int T) {
    int R, C;
    in >> R >> C;
    
    vector<string> G(R);
    int cnt_tree = 0;
    for(int i = 0; i < R; i++) {
        in >> G[i];
        for(int j = 0; j < C; j++) {
            cnt_tree += G[i][j] == '^' ? 1 : 0;
        }
    }

    bool ok = true;
    if(R == 1 || C == 1) {
        if(cnt_tree) {
            ok = false;
        } 
    } else {
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                G[i][j] = '^';
            }
        } 
    }
    if(ok) {
        out << "Case #" << T << ": " << "Possible" << '\n';
        for(int i = 0; i < R; i++) {
            out << G[i] << '\n';
        } 
    } else {
        out << "Case #" << T << ": " << "Impossible" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    in.open("input.txt");
    out.open("output.txt");

    int T;
    in >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }

    in.close();
    out.close();
}
