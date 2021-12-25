
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <climits>
#include <queue>
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
            
vector<int> ok = {0,0,0,0,0,0,0,0,0,0,0, 1,1,1,1, 2,2,2,2, 3,3,3,3,4,4,4,4};
bool sol_ok(vector<int> &v){
    return v == ok;
}

vector<int> vv = {0,1,3,5,7,9,10};
vector<int> tezina = {0, 1, 10, 100, 1000};
vector<int> rupa= {2,4,6,8};


set<pair< vector<int> ,vector<vector<int>> >>  st;
int cnt = 0;


int get_x(vector<int> &v, int i){
    i = i *4 + 11;
    int k = 5;
    while (k-- && v[i] == 0){
        i++;
    }
    if (k == 0) return -1;
    return i;
}

int ok_to_push(vector<int> &v, int pil){
    int loc = (pil - 1)*4 + 11;
    for (int i = 0; i < 4; i++){
        if (v[loc + i] != 0 && v[loc+ i] != pil) return 0;
    }
    for (int i = 3; ~i; i--){
        if (v[loc + i] == 0) return loc + i;
    }

    return loc;
}

void pr(vector<int> &v){
    for (int i =0 ; i < 11; i++){
        cout << v[i]<<" ";
    }
    cout << endl;
    for (int i = 11; i < v.size() ;i++){
        cout << v[i]<<" "; 
        if ((i - 11 + 1) %4 == 0) cout << endl;
    }
    cout << endl;
}

void do_sol(vector<int> &v){
   // priority_queue< pair<int,vector<int> >> q;
    priority_queue<pair<int,vector<int> >, std::vector<pair<int,vector<int> >>, std::greater<pair<int,vector<int> >>> q;


    q.push({0, v});
    //cout << v.size()<< endl;
    int tr = 0;
    set<vector<int>> st;
    int x = 0;
  
    while (!q.empty()){
        v = q.top().second; 
        tr = q.top().first;
        q.pop();
        //cout << q.size()<< endl;
        if (sol_ok(v)){
            cout << "nsaoo "<<tr<<endl;
            return ;
        }
         
        
        if (st.count(v)){ continue ; }
        st.insert(v);
       
        // dobi sljedeca stanjea
        // g - > v;
        for (int i = 0; i < 4; i++){
            x = get_x(v,i);
            
            if (x == -1) continue;
            for (int j = i + 2; j < 7; j++){
                if (v[vv[j]]) break;
               // pr(v);
                v[vv[j]] = v[x];
                v[x] = 0;
                pair<int, vector<int>> w = make_pair(tr + (abs( vv[j] - rupa[i]) + 1 + ((x - 11)%4 ) )*tezina[v[vv[j]]], v);
                q.push(w);
              //  pr(v);
                v[x] = v[vv[j]];
                v[vv[j]] = 0;
               // cout <<"1.1... "<< abs( vv[j] - rupa[i] + 1 + ((x - 11)%4 ) )*tezina[ v[x]]<<endl;
            }

            for (int j = i + 1; ~j; j--){
                if (v[vv[j]]) break;
               // pr(v);
                v[vv[j]] = v[x];
                v[x] = 0;
                pair<int, vector<int>> w = make_pair(tr + (abs( vv[j] - rupa[i]) + 1 + ((x - 11)%4 ) )*tezina[v[vv[j]]], v);
                q.push(w);
                //pr(v);

                v[x] = v[vv[j]];
                v[vv[j]] = 0;
                //cout <<"1.2... " << (abs( vv[j] - rupa[i]) + 1 + ((x - 11)%4 ) )*tezina[ v[x]] << endl;
            }
        }
        //v -> g
        for (int i = 0; i < 7; i++){
            if (v[vv[i]] == 0) continue;

            x = ok_to_push(v, v[vv[i]]);
            
            if (!x) continue;
            
            int poc = min(vv[i], rupa[v[vv[i]] - 1]);
            int ma = max(vv[i], rupa[v[vv[i]] - 1]);
            bool ok = 1;
            //cout << poc << " "<< ma<< endl;
            for (int j = poc + 1; j <ma; j++ ) {
                //cout << j<<endl;
                if (v[j]) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 0) continue;
            //pr(v);
            v[x]= v[vv[i]];
            v[vv[i]] = 0;
            //tr = 
            //q.push({tr + (ma - poc + 1  +((x - 11)%4 ))*tezina[v[x]] ,v}); 
            pair<int, vector<int>> w = make_pair(tr + (ma - poc + 1  +((x - 11)%4 ))*tezina[v[x]], v);
            q.push(w);
           // pr(v);
            v[vv[i]] = v[x];
            v[x] = 0;
            //cout << "2.... " <<(ma - poc + 1  +((x - 11)%4 ))*tezina[v[vv[i]]] << endl;

        }
    }
}



int main(){
    fstream f = fstream("in_1.txt");
    string line ;

    vector<int> v(11 + 2*4,0);
    //vector<vector<int>> g(4);


    //   v = {0, 0, 0, 0, 0, 0,0 ,0,0,0,0};
    //   g={{2,4,4,1},{3,3,2,4},{2,2,1,3},{4,1,3,1}};


   // v = {0,0,0,0,0,0,0,0,0,0,0, 2,4,4,1, 3,3,2,4, 2,2,1,3,4,1,3,1};
    //v = {1, 1, 0, 4, 0, 0,0 ,0,0,0,4, 2,4,4,1 , 0,2,2,2, 3,3,3,3, 0,0,0,1};
    //v =  {1,1,0,0,0,0,0,2,0,2,4, 2,4,4,1, 0,3,2,4 , 0,0,3,3,0,0,3,1};
    //v = {1,1,0,1,0,1,0,0,0,0,0, 0,0,0,0, 2,2,2,2, 3,3,3,3,4,4,4,4};
    v = {0,0,0,0,0,0,0,0,0,0,0, 3,4,4,4, 1,3,2,4, 2,2,1,2, 3,1,3,1};

    //g ={{0,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
    //v = {0,0,0,0,0,0,0,0,0,0,0};
    //g={{2,1},{3,4},{2,3},{4,1}};
    do_sol(v);
    return 0;
}


// #############
// #...........#
// ###C#A#B#C###
//   #D#D#B#A#
//   #########
//18354
//18322
//18300


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
