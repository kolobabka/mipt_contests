#include <iostream>
#include <vector>
#include <stack>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vals(n + 1);
    vals[1] = 0;
    for(int i = 2; i <= n; i++){
        int k1, k2, k3;
        k1 = vals[i-1] + 1;
        k2 = (i % 2 == 0) ? (vals[i / 2] + 1) : k1;
        k3 = (i % 3 == 0) ? (vals[i / 3] + 1) : k1;
        vals[i] = std::min(std::min(k1, k2), k3);
    }
    std::cout << vals[n] << std::endl;

    int i = n;
    std::stack<int> results;
    while(i != 1){
        int k1, k2, k3;
        k1 = vals[i-1];
        k2 = (i % 2 == 0) ? vals[i / 2] : k1;
        k3 = (i % 3 == 0) ? vals[i / 3] : k1;
        if(k3 <= k1 && k3 <= k2 && i % 3 == 0){
            i /= 3;
        }
        else if(k2 <= k1 && k2 <= k3 && i % 2 == 0){
            i /= 2;
        }
        else{
            i -= 1;
        }
        results.push(i);
    }
    while(!results.empty()){
        std::cout<<results.top()<<" ";
        results.pop();
    }
    std::cout<<n;

    return 0;
}
