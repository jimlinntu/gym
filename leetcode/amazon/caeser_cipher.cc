#include<bits/stdc++.h>
using namespace std;


string decipher(string enc, int k){
    string dec;
    int n = enc.size();
    k = k % 26;
    for(int i = 0; i < n; i++){
        int x = enc[i]-'A';
        int y = (x - k + 26) % 26;
        dec.push_back(y + 'A');
    }
    return dec;
}

int main(){
    cout << decipher("VTAOG", 2) << endl;
    return 0;
}
