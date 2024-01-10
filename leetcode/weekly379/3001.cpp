#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int x = a;
        int y = b;
        while(x >= 1 && y >= 1 && x < 9 && y < 9) {
            if(x == e && y == f) {
                return 1;
            }
            if(x == c && y == d) {
                break;
            }
            x -= 1;
        }
        
        x = a;
        y = b;
        while(x >= 1 && y >= 1 && x < 9 && y < 9) {
            if(x == e && y == f) {
                return 1;
            }
            if(x == c && y == d) {
                break;
            }
            x += 1;
        }
        
        x = a;
        y = b;
        while(x >= 1 && y >= 1 && x < 9 && y < 9) {
            if(x == e && y == f) {
                return 1;
            }
            if(x == c && y == d) {
                break;
            }
            y += 1;
        }
        
        x = a;
        y = b;
        while(x >= 1 && y >= 1 && x < 9 && y < 9) {
            if(x == e && y == f) {
                return 1;
            }
            if(x == c && y == d) {
                break;
            }
            y -= 1;
        }
        
        x = c;
        y = d; 
        while(x >= 1 && y >= 1 && x < 9 && y < 9) {
            if(e == x && f == y) {
                return 1;
            }
            if(x == a && y == b) {
                break;
            }
            x -= 1;
            y -= 1;
        }
        
        x = c;
        y = d;
        while(x >= 1 && y >= 1 && x < 9 && y < 9) {
            if(e == x && f == y) {
                return 1;
            }
            if(x == a && y == b) {
                break;
            }
            x += 1;
            y += 1;
        }
        
        x = c;
        y = d;
        while(x >= 1 && y >= 1 && x < 9 && y < 9) {
            if(e == x && f == y) {
                return 1;
            }
            if(x == a && y == b) {
                break;
            }
            x -= 1;
            y += 1;
        }
        
        x = c;
        y = d;
        while(x >= 1 && y >= 1 && x < 9 && y < 9) {
            if(e == x && f == y) {
                return 1;
            }
            if(x == a && y == b) {
                break;
            }
            x += 1;
            y -= 1;
        }
        
        return 2;
    }
};
