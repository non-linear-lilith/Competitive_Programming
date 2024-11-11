#include <iostream>
#include <vector>
#include <algorithm>
#define vector std::vector
#define ull unsigned long long 
#define ll long long
#define cout std::cout
#define endl std::endl
#define cin std::cin

int main() {
    int N;
    cin >> N;
    vector<int> min;
    vector<int> max;

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        min.push_back(input);
        cin >> input;
        max.push_back(input);
    }
        vector<int> total[2*N];
    std::nth_element(total, total+N, total+2*N);
    int cost = 0;
    cout<<cost<<endl;
    return 0;
    
}