#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <queue>
using namespace std;

vector<int> parse(string &v, char del){
    vector<int> sol;
    string s;
    for (int i = 0; i < v.size(); i++){
        if (v[i] == del){
            if (s.length())
            sol.push_back(stoi(s));
            s.clear();
        } else{
            s.push_back(v[i]);
        }
    }
     if (s.length())
    sol.push_back(stoi(s));
    return sol;
}

vector<vector<int>> all_permutations = {
    {3 , -1 , -2},
    {-3 , -1 , 2},
    {-3 , 1 , -2},
    {3 , 1 , 2},
    {-2 , -1 , -3},
    {2 , -1 , 3},
    {2 , 1 , -3},
    {-2 , 1 , 3},
    {-3 , -2 , -1},
    {3 , -2 , 1},
    {3 , 2 , -1},
    {-3 , 2 , 1},
    {1 , -2 , -3},
    {-1 , -2 , 3},
    {-1 , 2 , -3},
    {1 , 2 , 3},
    {2 , -3 , -1},
    {-2 , -3 , 1},
    {-2 , 3 , -1},
    {2 , 3 , 1},
    {-1 , -3 , -2},
    {1 , -3 , 2},
    {1 , 3 , -2},
    {-1 , 3 , 2}
};

vector<int> get_scaner_pos(vector<int> &v1, vector<int> v2){
    vector<int> pos;
    for (int i = 0; i < 3; i++){
        pos.push_back(v1[i] - v2[i]);
    }
    return pos;
}

vector<vector<int>> get_from_perspective(vector<vector<int>> &scanes,vector<int> pos, vector<int> orj, vector<int> p){
    vector<vector<int>> sol;

    for (int i = 0; i < scanes.size(); i++){
        vector<int> v;
        for (int j = 0; j < 3; j++){
            v.push_back(scanes[i][orj[j]]*p[j] + pos[j]);
        }
        sol.push_back(v);
        v.clear();
    }

   

    return sol;
}

set<vector<int>> kset;

int count_same(vector<vector<int>> &w){
  
    int c = 0;
    for (int j = 0; j < w.size(); j++){
        c+=kset.count(w[j]);
    }
  
    return c;
}

int man(vector<int> &v1, vector<int> &v2){
    int k = 0;
    for (int i = 0; i < v1.size(); i++){
        k += abs(v1[i] - v2[i]);
    }
    return k;
}

int main(){
    fstream f = fstream("in_1.txt");
    string line;
    vector<vector<int>> sc;
    vector<vector<vector<int>>> scanes;
    while(getline(f,line)){
        if (line[0] == '-' && line[1] == '-'){
            continue;
        } else if (line.length() == 0){
            scanes.push_back(sc);
            sc.clear();
            continue;
        } else 
        sc.push_back(parse(line,','));
    }

    scanes.push_back(sc);
    sc.clear();
    // for (int i = 0; i< scanes.size(); i++){
    //     cout <<i<<" scan"<<el;
    //     for (int j = 0; j < scanes[i].size(); j++){
    //         for (int z = 0;z < scanes[i][j].size(); z++){
    //             cout << scanes[i][j][z]<<" ";
    //         }
    //         cout << endl;
    //     }
    // }
    // vector<vector<int>> v = get_from_perspective(scanes[1], {68,-1246,-43}, {0,1,2}, {-1, 1, -1});
    // cout << count_same(scanes[0], v) << el;
    vector<vector<int>> beak;
    beak = scanes[0];
    set<int> st;
    vector<vector<vector<int>>> soll;
    bool brk = 0;
    for (int zz = 0; zz < beak.size(); zz++){
        kset.insert(beak[zz]);
    }

    vector<vector<int>> positions;
    positions.push_back({0,0,0});
    int befor = 0;
    for (int i = 0; i < scanes.size(); i++){
        for (int j = 1; j < scanes.size(); j++){
            if (st.count(j)) continue;
            for (int frst = befor; frst< beak.size();frst++){
                for (int sec = 0; sec < scanes[j].size();sec++){
                    // za sve permutacije
                    for (int k = 0; k < all_permutations.size(); k++){
                        int x =  all_permutations[k][0], y=all_permutations[k][1], z =all_permutations[k][2];
                        int p1 = 1, p2 = 1, p3 = 1;
                        if (x<0) p1=-1;
                        if (y<0) p2=-1;
                        if (z<0) p3=-1;
                        x = abs(x) - 1;
                        y = abs(y) - 1;
                        z = abs(z) - 1;
                        vector<int> s = get_scaner_pos(beak[frst], {scanes[j][sec][x]*p1,scanes[j][sec][y]*p2,scanes[j][sec][z]*p3});
    
                        vector<vector<int>> pot = get_from_perspective(scanes[j] ,s, {x,y,z}, {p1,p2,p3});
                        int kk = count_same(pot);
                        
                        if (kk >= 12){
                            positions.push_back(s);
                            befor = beak.size() - 1;
                            for (int zz = 0; zz < pot.size(); zz++){
                                if (kset.count(pot[zz]) == 0){
                                    kset.insert(pot[zz]);
                                    beak.push_back(pot[zz]);
                                } 
                            }
                            
                            st.insert(j);
                            brk = 1;
                            break;
                        }
                    }   
                    if (brk){
                        break;
                    }
                }
                if (brk){
                        break;
                    }
            }
           
            brk = 0;
        }
        cout << beak.size() << endl;
    }
    for (int i = 0; i < positions.size(); i++){
        for (int j = 0; j < positions[i].size(); j++){
            cout << positions[i][j]<<" ";
        }
        cout << endl;
    }
    int dist = 0;
    for (int i = 0; i < positions.size() - 1; i++){
        for (int j = i + 1;  j < positions.size(); j++){
            dist = max(dist, man(positions[i], positions[j]));
        }
    }
    cout << dist << endl;
    cout << beak.size() << endl;
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
;