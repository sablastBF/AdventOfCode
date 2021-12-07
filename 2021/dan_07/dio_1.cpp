#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


long long  fff(vector<int> &bin, int x){
    long long  sol = 0;
    for (int i = 0; i < bin.size(); i++){
        long long  l = abs((x - bin[i]));
        sol += abs(l * (l + 1) / 2 );
    }

    return sol;
}

int main(){

    fstream f = fstream("in_1.txt");
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

    long long  sol = 1<<30;
   
    for (int i = 0; i < 10000; i++){
        sol = min(sol, fff(bin,i));
        
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
