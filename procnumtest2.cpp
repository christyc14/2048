#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

int twod_to_oned(int row, int col, int rowlen);
bool proc_num(std::vector<int>& v, int bi, int ei);
void print_grid(const std::vector<int>& v);

int main() {
   std::vector<int> s;
   std::string filename;
    
    std::cout << "please enter name of file:" << std::endl;
    std::cin >> filename;
    
    std::ifstream infile;
    infile.open(filename.c_str());
    
    if(!infile.is_open()){
        std::cout << "error, can't open input file" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    int tmp;
    
    while(infile >> tmp){
        s.push_back(tmp);
    }
    int side = std::sqrt(s.size());
    
    print_grid(s);
    std::cout << std::endl;
    if(proc_num(s,12,18) == true){
        std::cout << "true" << std::endl;
        print_grid(s);
    }
    else {
        std::cout << "false" << std::endl;
        print_grid(s);
    }
    return 0;
}

int twod_to_oned(int row, int col, int rowlen){
    return row*rowlen + col;
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

void print_grid(const std::vector<int>& v){
    int side = std::sqrt(v.size());
    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            std::cout << v[twod_to_oned(i,j,side)] << '\t';
        }
        std::cout << std::endl;
    }
}
