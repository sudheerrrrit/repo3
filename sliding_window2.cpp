#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr;
    int n ; 
    cout << "Enter the number of elements in the array: ";
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int x; 
        cin >> x;
        arr.push_back(x);
    }
    cout << "Enter the size of the sliding window: ";
    int k ;
    cin >> k;
    int i = 0, sum = 0, maxsum = 0;
    int x;
    for( x = 0 ;  x < k ; x++){
        sum += arr[x];
    }
    cout << "Initial sum of first " << k << " elements: " << sum << endl;
    maxsum = max(maxsum , sum);
    for(int j = x ; j < n ; j++){
        sum += arr[j];
        sum = sum - arr[i];
        maxsum = max(maxsum , sum);
        //sum = sum - arr[i];
        i++;
    }
    cout << maxsum << endl;
    
}