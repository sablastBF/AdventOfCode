#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;


int main(){

    fstream f = fstream("in_3.txt");
    string line; 
    vector<vector<int>> mat;
    while(getline(f,line)){
        string br = "";
        vector <int> v;
        for (int i = 0; i < line.size(); i++){
            if (line[i] == ',' || line[i] == '-' || line[i] == '>' || line[i] == ' '){
                if (br.size()){
                    v.push_back(stoi(br));
                    br.clear();
                }
            } else {
                br.push_back(line[i]);
            }
        }
        v.push_back(stoi(br));
        mat.push_back(v);
        v.clear();
    }
    vector<vector<int>> sol(1000, vector<int>(1000));
    int matx = 0,maty = 0;
    
    for (int i = 0; i < mat.size(); i++){
     
        int sx = 1, sy = 1, duz = 0;
        if (mat[i][1] > mat[i][3]) sy = -1;
        if (mat[i][0] > mat[i][2]) sx = -1;
        if (mat[i][0] == mat[i][2]) sx = 0;  
        if (mat[i][1] == mat[i][3]) sy = 0;
   
        sol[mat[i][0] ][mat[i][1]]++;

        while(mat[i][0] != mat[i][2] || mat[i][1] != mat[i][3]){
            mat[i][0]+=sx;
            mat[i][1]+=sy;
            sol[mat[i][0] ][mat[i][1]]++;
        }

    }
    int val = 0;
    for (int i = 0; i < sol.size(); i++){
        for (int j = 0; j < sol[0].size(); j++){
            if (sol[i][j] > 1) val++;
        }
    }


    cout << val<<el;

    
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
