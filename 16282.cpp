#include <stdio.h>

int main(void){
    long long n;
    scanf("%lld",&n);
    long long min = 0;
    for(long long i = 1; ;i++){
        long long max = 0;
        long long mul = 1;
        for(long long l = 0;l<i+1;l++){ //i+1번 돔
            max = max + mul*(i+1);
            mul = mul*2;
        }
        max = max + i;
        if(n>min && n<=max){
            printf("%lld",i);
            break;
        }
        min = max;
    }
    return 0;
}
