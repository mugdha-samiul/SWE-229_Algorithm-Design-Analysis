#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
#define inf        LONG_LONG_MAX
void heapify(vector <ll>& nums, int n, int i){
    ll l = i*2 + 1;
    ll r = i*2 + 2;
    ll maxIndex = i;
    if(nums[l] > nums[maxIndex] && l < n)
        maxIndex = l;
    if(nums[r] > nums[maxIndex] && r < n)
        maxIndex = r;
    if(maxIndex != i){
        swap(nums[i], nums[maxIndex]);
        heapify(nums, n, maxIndex);
    }
}
void heapSort(vector <ll>& nums, int n){
    for(int i = (n/2)-1;i >= 0;i--){
        heapify(nums, n, i);
    }
    for(int i = n-1;i >= 0;i--){
        swap(nums[i], nums[0]);
        heapify(nums, i, 0);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin >> n;
    vector <ll> nums(n);
    for(auto &a : nums)cin >> a;
    heapSort(nums, n);
    for(int i = 0;i < n;i++)
        cout << nums[i] << sp;
    return 0;
}
/*
6
45 56 41 78 32 14
*/
