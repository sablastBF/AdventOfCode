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
    vector<string> v;
    while(getline(f,line)){
        siz = line.size();
        v.push_back(line);
    }
    vector<string> vv,ss;
    ss = v;
    int kk = 0;
    int p = 0;
    char sol;
    while(v.size() > 1){
        p = 0;
        for (int i = 0; i < v.size(); i++){
            if (v[i][kk] == '1') p++;
            else p--;
        }
        if (p >= 0){
            sol = '1';
        } else {
            sol = '0';
        }
        for (int i = 0; i < v.size(); i++){
            if (v[i][kk] == sol){
                vv.push_back(v[i]);
            } 
        }

        v = vv;
        vv.clear();
        kk++; 
    }
    string sol1 = v[0];
     cout << v[0] << endl;
    v = ss;
    vv.clear();
    kk = 0;
     while(v.size() > 1){
        p = 0;
        for (int i = 0; i < v.size(); i++){
            if (v[i][kk] == '1') p++;
            else p--;
        }
        if (p >= 0){
            sol = '0';
        } else {
            sol = '1';
        }
        for (int i = 0; i < v.size(); i++){
            if (v[i][kk] == sol){
                vv.push_back(v[i]);
            } 
        }

        v = vv;
        vv.clear();
        kk++; 
    }
    string sol2 = v[0];

    cout << v[0] << endl;
    int sol__1 = 0;
    for (int i = 0; i < sol1.size(); i++){
        sol__1 = sol__1 * 2;
        if (sol1[i] == '1') sol__1+=1;
    }
     int sol__2 = 0;
    for (int i = 0; i < sol2.size(); i++){
        sol__2 = sol__2 * 2;
        if (sol2[i] == '1') sol__2+=1;
    }

    cout << sol__1 <<" "<< sol__2<<" "<< sol__2 * sol__1 << endl;
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
