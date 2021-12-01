#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


template <typename T>
vector<T> load_from_file(string path){
    fstream f = fstream(path);
    string line;
    vector<int> v;
    while(getline(f,line)){
        v.push_back(stoi(line));
    }

    return v;
}


int main(){
    vector<int> v = load_from_file<int>("in.txt");

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
