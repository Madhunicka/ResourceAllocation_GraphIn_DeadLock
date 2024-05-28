#include <iostream>

int main() {
   int n=3;
   int r=3;

   int initialavailability[3] = {0,0,0};

   int allocation[3][3]={
    {0,0,1},
    {1,0,1},
    {0,1,0}
   };
   int req[3][3]={
    {1,0,0},
    {0,1,0},
    {0,0,1}
   };
   int count=0;

   //check availability[] matrix is in the req matrix[] row
    for(int i=0;i<n;i++){
     for(int j=0;j<r;j++){
          if(req[i][j]==initialavailability[j]){
            count++;

          }
     }
    }
    if(count==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<r;j++){
                initialavailability[j]=initialavailability[j]-req[i][j];
                allocation[i][j]=allocation[i][j]+req[i][j];
            }
        }
    }
    else{
        std::cout<<"Detection of Deadlock";
    }

  
   



   return 0;
}