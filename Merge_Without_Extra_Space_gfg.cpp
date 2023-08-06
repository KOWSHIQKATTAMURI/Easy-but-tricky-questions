#include<bits/stdc++.h>
using namespace std;

//approach 1
void merge(long long arr1[], long long arr2[], int n, int m){
    int left = n - 1, right = 0;
    while(left >= 0 and right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }else{
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
} 

//approach 2 -> using shell sort
void swapper(long long arr1[], long long arr2[], int i, int j){
    if(arr1[i] > arr2[j]){
        swap(arr1[i], arr2[j]);
    }
}
void merge_shell_sort(long long arr1[], long long arr2[], int n, int m){
    int total = n + m;
    int gap = (n + m)/2 + (n + m)%2;
    while(gap > 0){
        int left = 0, right = left + gap;
        while(right < total){
            if(left < n and right >= n){
                swapper(arr1, arr2, left, right - n);
            }else if(left >= n){
                swapper(arr2, arr2, left - n, right - n);
            }else{
                swapper(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if(gap == 1){
            break;
        }
        gap = gap/2 + gap%2;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    long long arr1[n], arr2[m];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    merge(arr1, arr2, n, m); //approach 1
    merge_shell_sort(arr1, arr2, n, m); //approach 2
    for(int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }
}