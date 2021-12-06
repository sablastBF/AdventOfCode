#define el '\n'

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;



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
    int ww = 0;
    for (int i = 0; i < mat.size(); i++){
        matx = max({matx, mat[i][0],mat[i][2]});
        maty = max({maty, mat[i][1]
        , mat[i][3]});
        if (mat[i][1] == mat[i][3]){
            for (int j = min(mat[i][0], mat[i][2]); j <= max(mat[i][0], mat[i][2]); j++){
                sol[j][mat[i][1]]++;
            }
        }else
         if (mat[i][0] == mat[i][2]){
            for (int j = min(mat[i][1], mat[i][3]); j <= max(mat[i][1], mat[i][3]); j++){
                sol[mat[i][0]][j]++;
            }
        }
        else {
            int sx = 1;
            if (mat[i][0] > mat[i][2]) sx = -1;
            int sy = 1;
            if (mat[i][1] > mat[i][3]) sy = -1;
            int duz = abs(mat[i][0] - mat[i][2]);
            for (int q = 0; q <= duz; q++){
                //cout << mat[i][0]<<endl;
                sol[mat[i][0] ][mat[i][1]]++;
                mat[i][0]+=sx;
                mat[i][1]+=sy;
                ww = max(  sol[mat[i][0] ][mat[i][1]], ww);
            }
        }

     }
    int val = 0;
    for (int i = 0; i < sol.size(); i++){
        for (int j = 0; j < sol[0].size(); j++){
            if (sol[i][j] > 1) val++;
        }
    }
    cout << val<<el;

    string path = "";
    Mat image(1000, 1000, CV_8UC3, Scalar(0, 0, 0)); 
    float w = ww;
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            // int pixel = image.at<uchar>(r, c);
            // pixel += sol[i][j];
            //Vec3b color = image.at<Vec3b>(Point(i,j));
            int ss = round(255*sol[i][j]/w);
            //cout << sol[i][j]<<" "<< sol[i][j]/w<<" " <<ss <<endl;
            image.at<Vec3b>(Point(i,j)) += Vec3b(ss, ss, ss);
        }
    }
   ;
    imwrite("./slika.png", image);
    waitKey(0);
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
