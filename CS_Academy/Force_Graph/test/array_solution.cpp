#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define lli long long int 
using namespace std;
// This is the solution for the problem that uses a map of points and a vector of points that has an edge to the point using arrays instead of maps
// The solution is the same as the one in main.cpp but it has a different time complexity
// The time complexity of this solution is O(N^2) while the time complexity of the solution in main.cpp is O(N)
// The time complexity of this solution is O(N^2) because of the nested loop that calculates the forces acting on each point
// The time complexity of the solution in main.cpp is O(N) because it calculates the forces acting on each point in a single loop
// This solution uses a space complexity of O(N^2) because it uses a 2D array of size N^2
// The solution in main.cpp uses a space complexity of O(N) because it uses 1D arrays of size N
// The solution in main.cpp is better than this solution because it has a better time complexity and space complexity
// This solution cannot solve the problem for large inputs because of its time complexity and space complexity restrictions
int main(){
    map <int, vector<int>> G;
    int N, M, F1, F2;
    cin >> N >> M >> F1 >> F2;

    int arr[N][N];
    pair<lli, lli> pos[N];
    pair<lli, lli> F[N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arr[i][j] = 0;
        }
    }
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        arr[a-1][b-1] = 1;
        arr[b-1][a-1] = 1;
    }
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        pos[i].first = x;
        pos[i].second = y;
        
    }

    for(int i = 0; i < N; i++){
        F[i] = {0, 0};
        for(int j = 0; j < N; j++){
            if(arr[i][j] == 1){
                F[i].first += (lli)(F1) * (lli)(pos[i].first - pos[j].first);
                F[i].second += (lli)(F1) * (lli)(pos[i].second - pos[j].second);
            }else{
                F[i].first += (lli)(F2) * (lli)(pos[i].first - pos[j].first);
                F[i].second += (lli)(F2) * (lli)(pos[i].second - pos[j].second);
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << F[i].first << " " << F[i].second << endl;
    }
    return 0;
}