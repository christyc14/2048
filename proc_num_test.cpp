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
    std::cout << proc_num(s,2,4) << std::endl;
    print_grid(s);
    return 0;
}

int twod_to_oned(int row, int col, int rowlen){
    return row*rowlen + col;
}

bool proc_num(std::vector<int>& v, int bi, int ei){
    std::vector<int> temp;
    bool change = false;

    for(int i = bi; i < ei; i++){
        if(v[i] != 0){
            temp.push_back(v[i]);
        }
    }
    if(temp.size() != 0){
        for(int i = 0; i < temp.size()-1; i++){
            if(temp[i] == temp [i+1]){
                temp[i] = 2*temp[i];
                temp.erase(temp.begin()+i+1);
            }
        }

        while(temp.size() != ei-bi){
            temp.push_back(0);
        }

        for(int test = 0; test < temp.size(); test++){
            if(temp[test] != v[bi+test]){
                change = true;
                }
        }
        for(int u = 0; u < temp.size(); u++){
            v[u + bi] = temp[u];
            }
    }
    return change;
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
