
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <climits>
using namespace std;


void pr(vector<int> &v,vector<vector<int>> &g){
    cout <<"//////////////"<<endl;
  for (int i = 0; i  < v.size(); i++){
        cout << v[i]<<" ";
    }
    cout << endl;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < g[i].size(); j++){
            cout << g[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
}

int sol = INT_MAX;

bool sol_ok(vector<vector<int>> &g){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < g[i].size(); j++){
            if (i + 1 != g[i][j]) return 0;
        }
    }

    return 1;
}
vector<int> vv = {2,4,6,8};
set<int> kset = {2,4,6,8};
vector<int> tezina = {0, 1, 10, 100, 1000};

set<pair< vector<int> ,vector<vector<int>> >>  st;
int cnt = 0;
void do_sol( vector<int> &v,vector<vector<int>> &g, int tr_sol){
    
   
    // cnt++;
    //cout << sol << endl;
    if (sol_ok(g)){
        //pr(v,g);
        sol = min(sol, tr_sol);
        cout <<"sol " <<sol << endl;
        return ;
    }
    if (st.count({v,g})) return ;
    st.insert({v,g});

    //  sa g na v
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < g[i].size(); j++){
            if ( g[i][j] == 0) continue;
            if (j == 1 && g[i][0] != 0) continue;

            for (int z = vv[i] ; z < v.size(); z++){

                if (v[z] != 0) break;
                if (kset.count(z)) continue;
                v[z] = g[i][j];
                g[i][j] = 0;

                if (st.count({v,g}) == 0) 
                do_sol(v,g,tr_sol + (z - vv[i]  + j +1 ) * tezina[v[z]] );
                g[i][j] = v[z];
                v[z] = 0;
            }   

            for (int z = vv[i] ; ~z ; z--){
                if (v[z] != 0) break;
                if (kset.count(z)) continue;
                v[z] = g[i][j];
                g[i][j] = 0;
                
                if (st.count({v,g}) == 0) 
                do_sol(v,g,tr_sol + (vv[i] - z  + j + 1 ) * tezina[v[z]] );
                g[i][j] = v[z];
                v[z] = 0;
            }           
        }

        for (int z =  vv[i] ; z<11; z++){
            if (kset.count(z)) continue;
            if (v[z] == 0) continue;            
            if (v[z] != i + 1) break;
            int p = 0;
            if (g[i][1] == 0) p = 1;
            g[i][p] = v[z];
            v[z] = 0;
            if (st.count({v,g}) == 0) 
            do_sol(v,g,tr_sol + (z - vv[i] + p + 1)*tezina[g[i][p]] );

            v[z] = g[i][p];
            g[i][p] = 0;
            
            break;
        }

        for (int z =  vv[i]; ~z; z--){
            if (kset.count(z)) continue;
            if (v[z] == 0) continue;            
            if (v[z] != i + 1) break;
            int p = 0;
            if (g[i][1] == 0) p = 1;
            g[i][p] = v[z];
            v[z] = 0;
           if (st.count({v,g}) == 0) 
            do_sol(v,g,tr_sol  + ( vv[i] -z  + p + 1 )*tezina[g[i][p]]);

            v[z] = g[i][p];
            g[i][p] = 0;
            
            break;

        }

       

    }
    // sa v na g
}

int main(){
    fstream f = fstream("in_1.txt");
    string line ;

    vector<int> v(11,0);
    vector<vector<int>> g(4);
    
    // while(getline(f, line)){
    //     cout <<line << endl;
    //     int p = 0; 
    //     for (int i = 0; i < line.size(); i++){
    //         if (line[i] >= 'A' && line[i] <= 'D'){
    //             g[p].push_back(line[i] -'A' + 1);
    //             p++;
    //         }
    //     }
    // }

     v = {0, 0, 0, 0, 0, 0,0 ,4,0,0,4};
     g={{1,1},{2,2},{3,3},{0,0}};
    cout <<sol_ok(g)<<endl;
    do_sol(v, g, 0);
    cout << sol << endl;
    return 0;
}
//#############
// #.....D.D.A.#
// ###.#B#C#.###
//   #A#B#C#.#
//   #########


//1005809
//12521
//23782
//21213
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
