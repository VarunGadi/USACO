#include <bits/stdc++.h>

using namespace std;

long long int sickness(long long int a, long long int b, long long int c){
    if(b == a - (a / 2) - 1){
            if(a % 2 == 1){
                return 1;
            }
            return 2;
        }
    if(c == 1){
        if(b > a - (a / 2) - 1){
            return 1;
        }
    }
    return a - (2 * a * b) / (2 * b + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int N;
    cin >> N;
    if(N == 1){
        cout << 1 << "\n";
        exit(0);
    }
    string sick;
    cin >> sick;
    long long int block[N];
    long long int B = 0;
    long long int numBlock = 0;
    long long int begin = 0;
    long long int end = 0;
    if(sick[0] == '1'){
        begin = 1;
        B++;
        numBlock++;
    }
    for(long long int a = 1; a < N - 1; a++){
        if(sick[a] == '1'){
            if(numBlock == 0){
                B++;
            }
            numBlock++;
        }
        else{
            if(numBlock > 0){
                block[B] = numBlock;
                numBlock = 0;
            }
        }
    }
    if(sick[N - 1] == '1'){
        end = 1;
        if(sick[N - 2] == '1'){
            numBlock++;
            block[B] = numBlock;
        }
        else{
            B++;
            block[B] = 1;
        }
    }
    else{
        if(sick[N - 2] == '1'){
            block[B] = numBlock;
        }
    }
    long long int nights;
    if(begin == 1){
        nights = block[1] - 1;
    }
    else{
        nights = block[1] - (block[1] / 2) - 1;
    }
    if(end == 1){
        if(nights > block[B] - 1){
            nights = block[B] - 1;
        }
    }
    else{
        if(nights > block[B] - (block[B] / 2) - 1){
            nights = block[B] - (block[B] / 2) - 1;
        }
    }
    for(long long int a = 2; a < B; a++){
        if(nights > block[a] - (block[a] / 2) - 1){
            nights = block[a] - (block[a] / 2) - 1;
        }
    }
    for(long long int a = 1; a <= B; a++){
        if(a == 1 && begin == 1){
            block[a] = sickness(block[a], nights, 1);
        }
        else if(a == B && end == 1){
            block[a] = sickness(block[a], nights, 1);
        }
        else{
            block[a] = sickness(block[a], nights, 0);
        }
    }
    long long int answer = 0;
    for(long long int a = 1; a <= B; a++){
        answer += block[a];
    }
    cout << answer << "\n";
}