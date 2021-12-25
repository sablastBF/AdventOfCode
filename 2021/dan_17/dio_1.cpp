#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <queue>
using namespace std;


int pos(int n){
    return n*(n + 1) /2;
}



int main(){
    int n, m;
    int max_X, max_Y, min_X, min_Y;
    cin >> min_X >> max_X;
    cin >> min_Y >> max_Y;
    int sol = 0;
    for (int x = 1;x < 1000; x++){
        for (int y = -1090; y < 1000; y++){
            int X = 0, Y = 0, vx = x, vy = y;
            while (vx&&X < min_X){
                X+=vx; vx--;
                Y+=vy; vy--;
            }

        
            while (Y>max_Y){
                Y+=vy; vy--;
                if (vx != 0){
                X+=vx; vx--;}
            }
            cout <<x<<" "<< y<<" "<< X<<" "<<Y<<endl;

            if (X >= min_X && X <= max_X && Y >= min_Y && Y <= max_Y) {sol++;}
            
        }
    }
    
    cout << sol<<el;
    return 0;
}


/*
//
//             *
//                               *
//                         *  _|_
//                         .-' * '-. *
//                        /       * \
//                     *  ^^^^^|^^^^^
//                         .~. |  .~.
//                        / ^ \| / ^ \
//                       (|   |J/|   |)
//                       '\   /`"\   /`
//             -- '' -'-'  ^`^    ^`^  -- '' -'-'
*/
;