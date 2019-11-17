#include<stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int current, baseline;
    int num_participants = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &current);
        
        if(current == 0){
            break;
        }

        if(i == k){
            baseline = current;
        }else if(i > k){
            if(!(current >= baseline)){
                num_participants = i - 1;
                break;
            }
        }

        num_participants = i;
        
    }

    printf("%d", num_participants);
    return 0;
}
