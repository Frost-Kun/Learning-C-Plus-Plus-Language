#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
char a[1005][1005];
string f[1005][1005];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for(int i = 1; i<= n; i++){
        for(int j =1 ; j <= n; i++){
            cin >> a[i][j];

        }
    }
    // Xet vong lap 1-2-3-4-5-6-n
    if(a[1][1] == '1') f[1][1]= "1";
    else f[1][1] = "0";
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 && j ==1) continue;
            if(i == 1) f[i][j] = f[i][j-1] + a[i][j];
            else if(j == 1) f[i][j] = f[i-1][j] + a[i][j];
            else f[i][j] = max(f[i-1][j], f[i][j-1]) + a[i][j];

        }
    }
    //Phan dinh gioi han toi cu the bao nhieu roi se su ly ct
    string b = f[n][n];
    while(b.size() > 1 && b[0] == '0') b.erase(0,1);
    while(b.size() %4 != 0) b= "0" + b;
    for(int i = 0; i <= b.size(); i++){
        int x = (b[i] - '0') * 8 + (b[i+1] - '0')* 4 + (b[i+2] - '0') * 2 + (b[i+3] - '0');
        if (x<10) cout << x;
        else cout << (char)(x + 55);

    }
}


