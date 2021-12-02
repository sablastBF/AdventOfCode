#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;




int main(){

    fstream f = fstream("in_1.txt");
    string line;
   
    int x = 0, y = 0;
    while(getline(f,line)){
        string s = "";
        string smjer = "";
        for (int i = 0; i < line.size(); i++){
            if (line[i] == ' '){
                smjer = s;
                s.clear();
            } else {
                 s.push_back(line[i]);
            }
        }

        int p = stoi(s);
        if (smjer == "forward"){
            x+=p;
        } else if (smjer == "down"){
            y+=p;
        } else if (smjer == "up"){
            y-=p;
        }

    }
    cout <<"X " << x<<endl;
    cout <<"Y "<< y<< endl;
    cout << x*y<<endl;
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
