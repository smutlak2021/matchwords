#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <iomanip>

long fibonacci_recursive(int n){
    // std::cout << n << std::endl;
    if (n <= 1) return n;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

//old_version
std::unordered_map<int, long> results;
long fibonacci_dynamic_1(int n){
    // std::cout << "dynamic " << n ;

    if (n <= 1) {return n;}
    else {
        const auto& it = results.find(n);
        if(it != results.end()){
            // std::cout << n <<  "found" << std::endl;
            return results[n];
        }
    }


 long ret = fibonacci_dynamic_1(n-1) + fibonacci_dynamic_1(n-2);
//  std::cout << "result " << ret << std::endl;
 results.insert({n, ret});
 return ret;
}

//better version but works only for int (small numbers)
long fibonacci_dynamic_2(int n, std::vector<long>& res){
    // std::cout << "dynamic " << n ;

    if (n <= 1) {return n;}
    else {
        long v = res[n];
        if(v != -1) return v;
    }


 long ret = fibonacci_dynamic_2(n-1, res) + fibonacci_dynamic_2(n-2, res);
//  std::cout << "result " << ret << std::endl;
 res[n] = ret;
 return ret;
}

long fibonacci_dynamic_BU_DP(int n){
    std::vector<long> v(n+1, -1);

    v[0]=0;
    v[1]=1;

    for(int i=2; i<=n; i++){
        v[i] = v[i-1] + v[i-2];
    }

    return v[n];

}


int main(int argc, char* argv[]){

    
    int param = 0;
    int n =0;
    std::cout << "running====" << argc << std::endl;
    auto start = std::chrono::high_resolution_clock::now();

    if(argc> 2){
        param = std::atoi(argv[1]);
        std::cout << "running====" << param << std::endl;
        n = std::atoi(argv[2]);
    }
    switch (param){
        case 0:
        {
            std::cout << "final_rec=" << fibonacci_recursive(n) << std::endl;
            break;
        }
        case 1:
        {
            std::cout << "final_dyn=" << fibonacci_dynamic_1(n) << std::endl;
            break;
        }
        case 2:
        {
            std::vector<long> vec(n+1, -1);
            std::cout << "final_dyn=" << fibonacci_dynamic_2(n, vec) << std::endl;
            break;
        }
        case 3:
        {
            
            std::cout << "final_dyn=" << fibonacci_dynamic_BU_DP(n) << std::endl;
            break;
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;
    std::cout << "execuation time:" << std::fixed << std::setprecision(9) << duration.count() << std::endl;
    return 0;
}