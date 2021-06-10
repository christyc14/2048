#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

void print_grid(const std::vector<int>& v);
int twod_to_oned(int row, int col, int rowlen);

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
