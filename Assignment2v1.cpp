#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

int twod_to_oned(int row, int col, int rowlen);
void print_grid(const std::vector<int>& v);
bool proc_num(std::vector<int>&v, int bi, int ei);
void rotate_anti_clock(std::vector<int>& v);
bool game_over(const std::vector<int>& v);
void ins2(std::vector<int>& v);

int main() {
    std::vector<int> s;
    std::string filename;
    
    std::cout << "please enter name of file:" << std::endl;
    std::cin >> filename;
    
    std::ifstream infile;
    infile.open(filename.c_str());
    
    if(!infile.is_open()){
        std::cout << "file not found, using default start configuration" << std::endl;
        for(int i = 0; i < 15; i ++){
            s.push_back(0);
        }
        s.push_back(2);
    }
    else{
        int tmp;
        while(infile >> tmp){
            s.push_back(tmp);
        }
        infile.close();
    }
    print_grid(s);
    
    int side = std::sqrt(s.size());
    char move; 
    while(!game_over(s)){
        bool change = false;
       std::cin >> move;
       if(move == 'a'){
           for(int i = 0; i < side; i++){
               if(proc_num(s,twod_to_oned(i,0,side),twod_to_oned(i,side-1,side)+1)){
                   change = true;
               }
           }
           if(change){
           ins2(s);
           print_grid(s);
           }
       }
       else if(move == 'w'){
           rotate_anti_clock(s);
           for(int i = 0; i < side; i++){
               if(proc_num(s,twod_to_oned(i,0,side),twod_to_oned(i,side-1,side)+1)){
                   change = true;
               }
           }
           rotate_anti_clock(s);
           rotate_anti_clock(s);
           rotate_anti_clock(s);
           if(change){
               ins2(s);
               print_grid(s);
           }
       }
       else if(move == 's'){
           rotate_anti_clock(s);
           rotate_anti_clock(s);
           rotate_anti_clock(s);
           for(int i = 0; i < side; i++){
               if(proc_num(s,twod_to_oned(i,0,side),twod_to_oned(i,side-1,side)+1)){
                   change = true;
               }
           }
           rotate_anti_clock(s);
           if(change){
               ins2(s);
               print_grid(s);
           }
       }
       else if(move == 'd'){
           rotate_anti_clock(s);
           rotate_anti_clock(s);
           for(int i = 0; i < side; i++){
               if(proc_num(s,twod_to_oned(i,0,side),twod_to_oned(i,side-1,side)+1)){
                   change = true;
               }
           }
           rotate_anti_clock(s);
           rotate_anti_clock(s);
           if(change){
               ins2(s);
               print_grid(s);
           }
       }
    }
    std::cout << "game over" << std::endl;
    return 0;
}

int twod_to_oned(int row, int col, int rowlen){
    return row*rowlen + col;
}

void print_grid(const std::vector<int>& v){
    std::cout << std::endl;
    int side = std::sqrt(v.size());
    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            std::cout << v[twod_to_oned(i,j,side)] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool proc_num(std::vector<int>& v, int bi, int ei){
    std::vector<int> hold;
    bool tf = false;
    
    for(int i = bi; i < ei; i++){
        if(v[i] != 0){
            hold.push_back(v[i]);
        }
    }
    if(hold.size() != 0){
        for (int i = 0; i < hold.size()-1; i++){
            if(hold[i] == hold [i+1]) {
                hold[i] = 2*hold[i];
                hold.erase(hold.begin()+i+1);
            }
        }
        while(hold.size() != ei-bi){
            hold.push_back(0);
        }
    
        for(int test = 0; test < hold.size(); test++){
            if(hold[test] != v[bi+test]){
                tf = true;
                }
        }
    
        int u = 0;
        for(int k = bi; k < ei; k++){
            v[k] = hold[u];
            u++;
            }
    }
    return tf;
}

void rotate_anti_clock(std::vector<int>& v){
    std::vector<int> temp;
    int rl = std::sqrt(v.size());
    for(int i = std::sqrt(v.size()) - 1; i >= 0; i--){
        for(int j = 0; j< std::sqrt(v.size()); j++){
            temp.push_back(v[twod_to_oned(j,i,rl)]);
        }
    }
    for(int i = 0; i<v.size(); i++){
        v[i] = temp[i];
    }
}

bool game_over(const std::vector<int>& v){
    std::vector<int> temp = v;
    int side = std::sqrt(v.size());
    bool moves = false;
    for(int i = 0; i < side; i++){
        if(proc_num(temp,twod_to_oned(i,0,side),twod_to_oned(i,side-1,side)+1)){
            moves = true;
            i = side;
        }
    }
    if(!moves){
        rotate_anti_clock(temp);
        for(int i = 0; i < side; i++){
            if(proc_num(temp,twod_to_oned(i,0,side),twod_to_oned(i,side-1,side)+1)){
                moves = true;
                i = side;
            }
        }
    }
    if(!moves){
        rotate_anti_clock(temp);
        for(int i = 0; i < side; i++){
            if(proc_num(temp,twod_to_oned(i,0,side),twod_to_oned(i,side-1,side)+1)){
                moves = true;
                i = side;
            }
        }
    }
    return !moves;
}

void ins2(std::vector<int>& v){
    std::vector<int> zeroes;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 0){
            zeroes.push_back(i);
        }
    }
    int randomIndex = std::rand() % zeroes.size();
    int vindex = zeroes[randomIndex];
    v[vindex] = 2;
}
