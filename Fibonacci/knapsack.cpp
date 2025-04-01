#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <chrono>


int Knapsack02(int w, std::vector<std::pair<int, int>>& v){
    std::vector<std::pair<int, int>> dp(v.size()+1);
    v

}
int Knapsack01(int w, std::vector<std::pair<int, int>>& v){
    std::vector<double> r;

    for( auto& item:v){
        double d = (double)item.second / (double)item.first;
        std::cout << std::fixed << std::setprecision(10) << d << std::endl;
        r.push_back(d);
    }
    std::sort(r.rbegin(), r.rend());

    for( auto& item:r){
        std::cout << std::fixed << std::setprecision(10) << item << std::endl;
    }
    return 0;
}

int main(int argc, char* argv[]){
    int param = 0;
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::pair<int, int>> v = {{12, 4}, {1, 2}, {1, 1}, {2, 2}, {4, 10}};
    if(argc> 1){
        param = std::atoi(argv[1]);
    }

    //Knapsack01(15, v);
    Knapsack02(15, v);



    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;
    std::cout << "execuation time:" << std::fixed << std::setprecision(9) << duration.count() << std::endl;
    return 0;
}