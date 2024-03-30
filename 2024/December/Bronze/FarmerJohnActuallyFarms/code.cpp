#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long T;
    cin >> T;
    for(long long a = 0; a < T; a++){
        long long N;
        cin >> N;
        long long height[N + 1];
        for(long long a = 1; a <= N; a++){
            cin >> height[a];
        }
        long long grow[N + 1];
        for(long long a = 1; a <= N; a++){
            cin >> grow[a];
        }
        long long order[N + 1];
        for(long long a = 1; a <= N; a++){
            cin >> order[0];
            order[order[0] + 1] = a;
        }
        long long start = 0;
        long long end = LONG_LONG_MAX;
        long long answer = 0;
        for(int a = 1; a < N; a++){
            if(height[order[a]] + start * grow[order[a]] <= height[order[a + 1]] + start * grow[order[a + 1]]){
                if(grow[order[a]] > grow[order[a + 1]]){
                    start = (height[order[a + 1]] - height[order[a]]) / (grow[order[a]] - grow[order[a + 1]]) + 1;
                }
                else{
                    answer = -1;
                    break;
                }
            }
            else{
                if(grow[order[a]] < grow[order[a + 1]]){
                    if((height[order[a]] - height[order[a + 1]]) % (grow[order[a + 1]] - grow[order[a]]) == 0){
                        end = (height[order[a]] - height[order[a + 1]]) / (grow[order[a + 1]] - grow[order[a]]) - 1;
                    }
                    else{
                        end = (height[order[a]] - height[order[a + 1]]) / (grow[order[a + 1]] - grow[order[a]]);
                    }
                }
            }
            if(start > end){
                answer = -1;
                break;
            }
        }
        if(answer == -1){
            cout << -1 << "\n";
        }
        else{
            cout << start << "\n";
        }
    }
}