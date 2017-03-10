#include <iostream>
using namespace std;

float average(int *arr, int size){
     int sum;
     printf("arr: %p\n",&arr);
     printf("size: %p\n",&size);
     printf("sum: %p\n",&sum);

     for(int i = 0;i < size;i ++){
         sum +=arr[i];
     }

     return (sum *1.0f) / size;
}

int main(){
    int a[10];
    average(a, 10);


    return 0;
}
