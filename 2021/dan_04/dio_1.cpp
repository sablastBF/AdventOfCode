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
    bool first_line = 0;
    vector<int> bin;


    vector<vector<vector<int>>> v;
    vector<vector<int>> mat;
    int kk = 0;
    while(getline(f,line)){
        if (first_line == 0){
            first_line = 1;
            string broj;
            for (int i = 0; i < line.size(); i++){
                if (line[i] == ','){
                    bin.push_back(stoi(broj));
                    broj.clear();
                } else {
                    broj.push_back(line[i]);
                }
            }
            bin.push_back(stoi(broj));
            continue;
        }
        if (line.size() == 0) continue;
        
        string broj;
        vector<int> vv;
        for (int i = 0; i < line.size(); i++){
                if (line[i] == ' '){
                    if (broj.size())
                    vv.push_back(stoi(broj));
                    broj.clear();
                } else {
                    broj.push_back(line[i]);
                }
        }   vv.push_back(stoi(broj));

        mat.push_back(vv);
        vv.clear();
        kk++;
        if (kk == 5){
            v.push_back(mat);
            mat.clear();
            kk = 0;
        }
    }
    vector<vector<int>> ver(v.size() ,vector<int>(5,0)), hor(v.size(), vector<int>(5,0));

    for (int i = 0; i < bin.size(); i++){
        
        for (int q = 0 ;q  < v.size(); q++){
            for (int j = 0; j < v[0].size(); j++){
                for (int z = 0; z < v[0][0].size(); z++){
                    if (bin[i] == v[q][j][z]){
                        v[q][j][z] = -1;
                        ver[q][j]++;
                        hor[q][z]++;
                        if (ver[q][j] == 5 ||  hor[q][z] == 5){
                            cout << bin[i] << " "<< i<< endl;
                            int xxx = 0;
                            for (int zzz = 0; zzz < v[0].size(); zzz++){
                                for (int yyy =0 ; yyy < v[0][0].size(); yyy++){
                                    if (v[q][zzz][yyy] == -1) continue;
                                    xxx+= v[q][zzz][yyy];
                                }
                            }
                            cout << xxx << endl;
                            cout << xxx * bin[i] << el;
                            return 0;
                        }
                    }
                }
            }
        }


    }
  
    
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
