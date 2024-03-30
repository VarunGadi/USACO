#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int N, M;
    cin >> N >> M;
    long long int cow[N + 1];
    long long int cane[M + 1];
    for(long long int a = 1; a <= N; a++){
        cin >> cow[a];
    }
    for(long long int a = 1; a <= M; a++){
        cin >> cane[a];
    }
    long long int height;
    for(long long int a = 1; a <= M; a++){
        height = 0;
        for(long long int b = 1; b <= N; b++){
            if(cow[b] >= cane[a]){
                cow[b] = cow[b] + cane[a] - height;
                break;
            }
            else if(cow[b] > height){
                cow[b] = 2 * cow[b] - height;
                height = (height + cow[b])/2;
            }
        }
    }
    for(long long int a = 1; a <= N; a++){
        cout << cow[a] << "\n";
    }
}