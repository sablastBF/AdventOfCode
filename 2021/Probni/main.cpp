#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    fstream f = fstream("in.txt");
    string line;
    vector<int> v;
    while(getline(f,line)){
        v.push_back(stoi(line));
    }
    int sol = 0;
    for (int i = 0; i < v.size() - 1; i++){
        for (int j = i + 1; j < v.size(); j++){
            if (v[i] + v[j] == 2020){
                sol = max(sol, v[i] * v[j]);
            }
        }
    }

    cout << sol << endl;
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
