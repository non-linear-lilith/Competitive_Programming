#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define lli long long int 
using namespace std;
// This is the solution for the problem that uses a map of points and a vector of points that has an edge to the point
// The solution is the same as the one in main.cpp but it has a different time complexity
// The time complexity of this solution is O(N^2) while the time complexity of the solution in main.cpp is O(N)
// The time complexity of this solution is O(N^2) because of the nested loop that calculates the forces acting on each point
// The time complexity of the solution in main.cpp is O(N) because it calculates the forces acting on each point in a single loop
// both solutions have the same space complexity of O(N) because they both use arrays of size N
int main(){
    map <int, vector<int>> G;
    int N, M, F1, F2;
    cin >> N >> M >> F1 >> F2;

    pair<int, int> arr[N];
    pair<lli, lli> F[N];

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }
    int cases_ = 0;
    if(F1&&F2){
        cases_ = 1;
    }
    else if (F1){
        cases_ = 2;
    }
    else if (F2){
        cases_ = 3;
    }
    switch(cases_){
        case 1:
        for(int i = 0; i < N; i++){
            F[i] = {0, 0};
            for(int j = 0; j < N; j++){
                if(find(G[i].begin(), G[i].end(), j) != G[i].end()){
                    F[i].first += (lli)(F1) * (lli)(arr[i].first - arr[j].first);
                    F[i].second += (lli)(F1) * (lli)(arr[i].second - arr[j].second);
                }else{
                    F[i].first += (lli)(F2) * (lli)(arr[i].first - arr[j].first);
                    F[i].second += (lli)(F2) * (lli)(arr[i].second - arr[j].second);
                }
            }
        }
        break;
        case 2:
            for(int i = 0; i < N; i++){
            F[i] = {0, 0};
            for(int j = 0; j < N; j++){
                if(find(G[i].begin(), G[i].end(), j) != G[i].end()){
                    F[i].first += (lli)(F1) * (lli)(arr[i].first - arr[j].first);
                    F[i].second += (lli)(F1) * (lli)(arr[i].second - arr[j].second);
                }
            }
        }
            break;
        case 3:
            for(int i = 0; i < N; i++){
                F[i] = {0, 0};
                for(int j = 0; j < N; j++){
                    if(!(find(G[i].begin(), G[i].end(), j) != G[i].end())){
                        F[i].first += (lli)(F2) * (lli)(arr[i].first - arr[j].first);
                        F[i].second += (lli)(F2) * (lli)(arr[i].second - arr[j].second);
                    }
                }
            }
            break;
    }

    for(int i = 0; i < N; i++){
        cout << F[i].first << " " << F[i].second << endl;
    }
    return 0;
}