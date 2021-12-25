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


class TreeNode{
    private:
        
        int h;
       
    public:
        bool is_right_child = 0, is_left_child = 0;
        TreeNode *left = nullptr, *right = nullptr;
        TreeNode *fad = nullptr;
        int value = -100;
         bool right_ = 0;
        TreeNode(){
        }
        ~TreeNode(){}

        TreeNode(int broj){
            this -> value = broj;
        }

        void set_bool_left(){
            right_ = !right_;
        }

        void set_int(int broj){
            if (right_){
                this -> right = new TreeNode(broj);
                this -> right -> fad = this;
                this -> right -> is_right_child = 1;
            } else {
                this -> left = new TreeNode(broj);
                this -> left -> fad = this;
                this -> left -> is_left_child = 1;
            }
        }
        void set_child(TreeNode *tr){
            tr -> fad = this;
            if (right_){
                this -> right = tr;
                tr -> is_right_child = 1;
            } else {
                this -> left = tr;
                tr -> is_left_child = 1;
            }
        }

        void set_h(int h_){
            h = h_;
        }
        int get_val(){
            return this -> value;
        }

        int get_h(){
            return h;
        }
        bool get_right_(){
            return right_;
        }
        void set_val(int val){
            this -> value = val;
        }
};

TreeNode *string_to_tree(string &str){
    vector<TreeNode *> tr;
    TreeNode *head = nullptr;
    for (int i = 0; i < str.size(); i++){

        if (str[i] == '['){
            TreeNode *nod = new TreeNode();
            if (tr.size() == 0) head = nod;
            else tr.back() -> set_child(nod);

            tr.push_back(nod);
        } else if (str[i] == ']'){
            tr.pop_back();
        } else if (str[i] == ','){
            tr.back() -> set_bool_left();
        }else {
            // broj
            int broj = 0;
            while(str[i] >= '0' && str[i] <='9' ){
                broj *= 10;
                broj += str[i] - '0';
                i++;
            } 
            i--;
            tr.back() -> set_int(broj);
        }
    }
    return head;
}


void update_hight(TreeNode *tr, int h){

    tr -> set_h(h);
    if (tr -> left) update_hight(tr -> left, h + 1);
    if (tr -> right) update_hight(tr -> right, h + 1);
  
}
bool print_zarez = 1;
void print_tree(TreeNode *tr){
    
    if (tr == nullptr) return;
    if (tr -> get_val() != -100)
    cout << tr -> get_val();
    else cout <<"[";
    if (tr -> left)
    print_tree(tr -> left);
    if (tr -> get_val() != -100 &&tr -> fad && tr -> fad -> get_right_() == 1){
    cout << ",";
    //tr -> fad -> set_bool_left();
    }
    
    if (tr -> right)
    print_tree(tr -> right);
    if (tr -> get_val() == -100){
        cout <<"]";
        
    }
}

TreeNode *add(TreeNode *tree, TreeNode *tr){
    TreeNode *novo = new TreeNode();
    novo -> set_child(tree);
    novo -> set_bool_left();
    novo -> set_child(tr);
    return novo;
}

bool is_child(TreeNode *tr){
    if (tr == nullptr) return 0;
    return (tr -> left == nullptr && tr -> right == nullptr);
}


TreeNode *find_first_left(TreeNode *tr){
    while(tr){
       
        if (tr -> is_left_child == 1 && tr -> is_right_child == 0){
            tr = tr -> fad;
        } else if (tr -> is_left_child == 0 && tr -> is_right_child == 0){
            return nullptr;
        }else  if (tr -> is_left_child == 0 && tr -> is_right_child == 1){
            tr = tr -> fad;
            tr = tr -> left;
            while(tr -> right){
                tr = tr -> right;
            }
            return tr;
        }
    }
    return nullptr;
}


TreeNode *find_first_right(TreeNode *tr){
    while(tr){
       
        if (tr -> is_left_child == 0 && tr -> is_right_child == 1){
            tr = tr -> fad;
        } else if (tr -> is_left_child == 0 && tr -> is_right_child == 0){
            return nullptr;
        }else  if (tr -> is_left_child == 1 && tr -> is_right_child == 0){
            tr = tr -> fad;

            tr = tr -> right;
            while(tr -> left){
                tr = tr -> left;
            }
            return tr;
        }
    }
    return nullptr;
}

bool w = 0;
void fix(TreeNode *tr){
    if (w == 1) return ;
    if (tr == nullptr) return ;
    if (w == 1) return ;
    if (tr -> left) fix(tr -> left);
   
    

   // cout << tr -> get_h()<<" "<<tr -> regular << endl;

    if (w == 0 && tr -> get_h() >= 4 && is_child(tr -> left) && is_child(tr -> right)){
        cout << "ekspodirao"<< endl; 
        int l = tr -> left -> get_val(), r = tr -> right -> get_val();        
        cout << l <<" "<< r << endl;
        // left
        TreeNode *first_left = find_first_left(tr);
        //right
        TreeNode *first_right = find_first_right(tr);
        if (first_left) {
            cout << "l "<<first_left -> get_val() << endl;
            first_left -> value += l;
        }
        if (first_right){ 
            
            cout << "r "<<first_right -> get_val() << endl;
            first_right -> value += r;
        }
        tr -> set_val(0);
        tr -> left = nullptr;
        tr -> right = nullptr;
        w = 1;


        return ;
    }

    // podjela
    //cout << tr -> get_val() << endl;
    // if (w == 0 && tr -> get_val() >= 10){
    //     cout << "skaliro"<< endl;
    //     int val =tr -> get_val();
         
    //     tr -> set_int(val/2);
    //     tr -> set_bool_left();
    //     tr -> set_int((val + 1)/2);
    //     tr -> set_val(-100);
    //     w = 1;
    // }

    if (tr -> right) fix(tr -> right);
   
}

void fixx(TreeNode *tr){
    if (w == 1) return ;
    if (tr == nullptr) return ;
    if (w == 1) return ;
    if (tr -> left) fixx(tr -> left);
   

    // podjela
    //cout << tr -> get_val() << endl;
    if (w == 0 && tr -> get_val() >= 10){
        cout << "skaliro"<< endl;
        int val =tr -> get_val();
        tr -> right_ = 0;
        tr -> set_int(val/2);
        tr -> set_bool_left();
        tr -> set_int((val + 1)/2);
        tr -> set_val(-100);
        w = 1;
    }

    if (tr -> right) fixx(tr -> right);
   
}

int get_magnitude(TreeNode *tr){
    if (tr -> left == nullptr && tr -> right == nullptr) return tr -> value;
    int lft = get_magnitude(tr -> left);
    int rgh = get_magnitude(tr -> right);
    return 3*lft + 2*rgh;
}

TreeNode *get_copy(TreeNode *tr){
 
        
    TreeNode *novi = new TreeNode();
    novi -> is_left_child = tr -> is_left_child;
    novi -> is_right_child = tr -> is_right_child;
    novi -> value = tr -> value;
    novi -> right_ = tr -> right_;

    if (tr -> left){
        novi -> left = get_copy(tr -> left);
        novi -> left -> fad = novi;
    }
    if (tr -> right){
        novi -> right = get_copy(tr -> right);
        novi -> right -> fad = novi;
    }

    return novi;
}

int main(){
    fstream f = fstream("in_1.txt");
    string line;
    vector<TreeNode *> tresss;
    TreeNode *tree = nullptr;
    while(getline(f,line)){
        TreeNode *tr = string_to_tree(line);
        tresss.push_back(tr);
        //print_tree(tr);
        // if (tree){
        // tree = add(tree, tr);
        // } else {
        //     tree= tr;
        // }
       
    
        // do{
        //     w = 0;
        //     update_hight(tree, 0);    
        //     fix(tree);
        //     if (w == 0) fixx(tree);
        //     print_tree(tree);
        //     cout << endl;
        // }while(w);
        
        
        //  cout << endl;
    }

    int sol = 0;
    for (int i = 0; i < tresss.size(); i++){
        for (int j = 0 ; j < tresss.size(); j++){
            
            if (i == j) continue;
            TreeNode *t1 = get_copy(tresss[i]);
            TreeNode *t2 = get_copy(tresss[j]);
            TreeNode *tr = add(t1, t2);
            // print_tree(t1); cout << el;
            // print_tree(t2); cout << el;
            // print_tree(tresss[i]); cout << el;
            // print_tree(tresss[j]); cout << el;

            //TreeNode *tr = tresss[i];
            //cout << endl;
            do{
                w = 0;
                update_hight(tr, 0);    
                fix(tr);
                if (w == 0) fixx(tr);
            }while(w);

            print_tree(tr);
            sol = max(get_magnitude(tr), sol);
            cout << get_magnitude(tr) << endl;

        }
    }

    cout << sol << el;
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