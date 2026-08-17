#include <stdio.h>
void b(int*v, int n){
        for(int i =0 ; i <n ;i++){
        for(int j = i +1 ;j <n -1;j++){
            if(v[i] > v[j] && v[i] != 0 && v[j] != 0){
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}
int main(){
    int v[] = {0,0,1,0, 0,3,0, 0,15, 0, 0};
    int n = 9;
   while(1){
       int a;
        scanf("%d", &a);
        if(a == 0) break;
       for(int i = 0 ; i < n; i++){
         if(v[i] != 0 &&  v[i] > a){
            v[i -1]= a;
            b(v,i);
        }
       }
   }
    


     for(int i = 0 ; i <n ;i++){
     if(v[i] != 0)
       printf("%d ", v[i]);
     } 
     return 0;
}
// [0, 0, 1, 0, 0, 3, 0 , 0, ] A0467