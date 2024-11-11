#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

#define lli long long int 
using namespace std;
// This is the solution for the problem that uses a map of points and a vector of points that has an edge to the point
// The solution has a time complexity of O(N) because it calculates the forces acting on each point in a single loop
// The solution uses a space complexity of O(N) because it uses arrays of size N
// The solution is better than the solution in map_solution.cpp because it has a better time complexity
// The solution is better than the solution in array_solution.cpp because it has a better time complexity and space complexity
// The solution in main.cpp is the best solution for the problem because it has the best time complexity and space complexity
// The solution in main.cpp is the most efficient solution for the problem using the given constraints

int main(){
    map <int, vector<int>> G; // Map of points, each point i in the map has a vector of points that has an edge to point i
    int N; // Number of points
    int M; // Number of edges
    lli F1; // Force F1
    lli F2; // Force F2
    cin >> N >> M >> F1 >> F2;

    pair<int, int> arr[N]; // Array of points, each point i in the array has a pair of coordinates p_i = (x_i, y_i)
    pair<lli, lli> F[N]; // Array of forces, each force i in the array has a pair of forces F_i = (F_x_i, F_y_i)

    for(int i = 0; i < M; i++){
        int a, b; // a and b are the points that are connected by an edge
        cin >> a >> b; 
        G[a-1].push_back(b-1); 
        G[b-1].push_back(a-1);
    }
    lli total_sum_x = 0; // Total sum of x coordinates of all points
    lli total_sum_y = 0; // Total sum of y coordinates of all points
    for(int i = 0; i < N; i++){
        lli x, y; // coordinates of point i p_i = (x_i, y_i) to be inserted as a pair in the array
        cin >> x >> y;
        arr[i] = {x, y};
        total_sum_x += x;
        total_sum_y += y;
    }

    for(int i=0;i<N;i++){
        lli E_size = G[i].size(); // Number of edges connected to a point i p_i=(x_i, y_i)
        lli E_sum_x = 0; // Total sum of x coordinates of points that has a edge to p_i
        lli E_sum_y = 0; // Total sum of y coordinates of points that has a edge to p_i
        E_sum_x = accumulate(G[i].begin(), G[i].end(), 0, [&](int sum, int j){return sum+arr[j].first;});// Sum of x coordinates of points that has a edge to p_i
        E_sum_y = accumulate(G[i].begin(), G[i].end(), 0, [&](int sum, int j){return sum+arr[j].second;});// Sum of y coordinates of points that has a edge to p_i
        for(int j = 0; j < E_size; j++){
            E_sum_x += (lli)arr[G[i][j]].first;
            E_sum_y += (lli)arr[G[i][j]].second;
        }
        // Calculate the force acting on point i p_i = (x_i, y_i)
        // F_i = (F_x_i, F_y_i) = (F1*(E_size*B+A)-C+E_sum_x*D, F1*(E_size*B+A)-C+E_sum_y*D)
        F[i] = {
            F2*(((lli)N-E_size)*(lli)arr[i].first - total_sum_x+E_sum_x)+F1*(E_size*(lli)arr[i].first-E_sum_x),
            F2*(((lli)N-E_size)*(lli)arr[i].second - total_sum_y+E_sum_y)+F1*(E_size*(lli)arr[i].second-E_sum_y)
        }; 
    }

    for(int i = 0; i < N; i++){
        cout << F[i].first << " " << F[i].second << endl;
    }
    return 0;
}