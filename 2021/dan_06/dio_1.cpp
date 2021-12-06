#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

    fstream f = fstream("in_2.txt");
    string line;
 
    vector<int> bin;
 
    while(getline(f,line)){
        string broj;

        for (int i = 0; i < line.size(); i++){
            if (line[i] == ','){
                if (broj.size())
                bin.push_back(stoi(broj));
                broj.clear();
            } else {
                broj.push_back(line[i]);
            }
        }
        bin.push_back(stoi(broj));
        
    }
    int n = 256;
    vector<long long> v(9, 0), v2(9, 0);
    for (int i = 0; i < bin.size(); i++){
        v[bin[i]]++;
    }
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    for (int dan = 0; dan < n; dan++){

       v2[8] = v[0];
       v2[6] = v[0];
       for (int i = 1; i <= 8; i++){
           v2[i - 1] += v[i];
       }
       v = v2;
       v2.clear();
       v2.resize(9 ,0 );
    //      for (int i = 0; i < v.size(); i++){
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    }
    long long sol = 0;
    for (int i = 0; i < 9; i++){
        sol += v[i];

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
