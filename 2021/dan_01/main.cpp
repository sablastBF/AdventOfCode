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
    for (int i = 1; i < v.size(); i++){
        if (v[i- 1] < v[i]) sol++;
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
