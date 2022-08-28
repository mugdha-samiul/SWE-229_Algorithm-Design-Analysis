#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX        200000                   //total numbers to check 
#define araMAX     200000/32                //size of flag array; 32 because flag is stored in int type array
int flag[araMAX];

void bitSieve(){
    for(int i = 2;i*i <= MAX;i++){
        if((flag[i/32] & (1<<(i%32))) == 0){           /*i/32 decides which number of the array,
                                                        i%32 decides which bit of the number,
                                                        1<<(i%32) shifts 1 to (i%32) times to the left,
                                                            for example: 1<<5
                                                            1    -> 000...0000001
                                                            1<<5 -> 000...0100000
                                                        flag[i/32] holds the Primality flag of 32 numbers: 0-31, 32-63...
                                                        ((flag[i/32] & (1<<(i%32))) ->
                                                        for 141, ((flag[4] & (1<<13)) will check 
                                                            if bit 13(from right) of flag[4] is 1(composite) or not
                                                        if(i=141) is prime then next lines will execute.
                                                        */
                
            for(int j = i*i;j <= MAX;j+=i){             
                flag[j/32] |= (1<<(j%32));              /*this line will set the given bit of the given number to 1 
                                                        suppose, flag[4] = 000...001010101
                                                        for 132, i/32 = 4, i%32 = 4,
                                                        so, 4th bit of flag[4] will be 1. How?
                                                        Firstly, 1<<4 will return 000...0001000
                                                        flag[4] | (1<<4) will set 4 th bit to 1
                                                        000...001010101 
                                                        000...000001000
                                                        ----------------
                                                        000...001011101
                                                        this is how 132 will be flagged to composite.
                                                        */
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    bitSieve();
    int tc;
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n;
        if((flag[n/32] & (1<<(n%32))) == 0)cout << "prime\n";
        else cout << "composite\n";
    }
    return 0;
}
