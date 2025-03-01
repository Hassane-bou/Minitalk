#include<stdio.h>
#include<limits.h>

int main(){
    long x = INT_MAX;

    x = x + x + 2 + 12804;
    printf("%ld", x);
}