#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define lli long long int

using namespace std;

int main() {
    int n;
    lli sum =0;

    cin >> n;
    vector<int> neg;
    for (int i = 0; i < n; i++) {
        int input;
        cin >>input;
        if (input > 0) {
            sum += input;
        } else {
            neg.push_back(input);
        }   
    }
    sort(neg.begin(), neg.end());
    int size = (int)neg.size();

    if(sum==0){
        sum=(lli)neg[size-1];
        neg.pop_back();
    }
    if(size%2==0){
        for(int i=0;i<size;i+=2){
            sum+=(lli)neg[size-1-i];
        }
    }
    else{
        for(int i=1;i<size;i+=2){
            sum+=(lli)neg[size-1-i];
        }
    }


    cout<<sum<<endl;
    return 0;
}