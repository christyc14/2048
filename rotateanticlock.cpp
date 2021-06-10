#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

void print_grid(const std::vector<int>& v);
int twod_to_oned(int row, int col, int rowlen);
void rotate_anti_clock(std::vector<int>& v);

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
        for(int i = 0; i < s.size(); i++){
        std::cout << s[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    rotate_anti_clock(s);
    for(int i = 0; i < s.size(); i++){
        std::cout << s[i] << " ";
    }
    std::cout << std::endl;

    print_grid(s);
    return 0;
}

int twod_to_oned(int row, int col, int rowlen){
    return row*rowlen + col;
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

void rotate_anti_clock(std::vector<int>& v){
    std::vector<int> temp;
    int side = std::sqrt(v.size());
    for(int i = side - 1; i >= 0; i--){
        for(int j = 0; j< std::sqrt(v.size()); j++){
            temp.push_back(v[twod_to_oned(j,i,side)]); // swap columns and rows, and print the new columns in reverse order
        }
    }
    for(int i = 0; i<v.size(); i++){
        v[i] = temp[i];
    }
}
