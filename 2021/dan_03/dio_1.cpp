#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;




int main(){

    fstream f = fstream("in_2.txt");
    string line;
   
    int x = 0, y = 0;
    vector<int> k(100, 0);
    int siz = 0;
    while(getline(f,line)){
        siz = line.size();
        for (int i = 0; i < line.size(); i++){
            if (line[i] == '1') k[i]++;
            else k[i]--;
        }  
    }

    int s1 = 0, s2 = 0;
    cout << siz << endl;
    for (int i = 0; i < siz; i++){
        if (k[i] > 0){
            s1 += 1;
        } else {
            s2 += 1;
        }
        s1 *= 2;
        s2 *= 2;
    }
    s1 = s1 / 2;
    s2 = s2 / 2;
    cout << s1  <<" "<< s2  <<" "<< s1 * s2 << el;
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
