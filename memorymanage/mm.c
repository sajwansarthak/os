#include <stdio.h>

int main() {
 int b, p;
 printf("enter no of memory blocks ");
 scanf("%d", &b);

 int block[b];
 printf("enter size of blocks\n");
 for(int i = 0; i < b; i++)
 scanf("%d", &block[i]);

 printf("enter number of processes ");
 scanf("%d", &p);

 int process[p];
 printf("enter sizes of processes:\n");
 for(int i = 0; i < p; i++)
 scanf("%d", &process[i]);

 int allocat[p];
 for(int i = 0; i < p; i++)
 allocat[i] = -1;    
 for(int i = 0; i < p; i++) {
 for(int j = 0; j < b; j++) {
 if(block[j] >= process[i]) {
 allocat[i] = j;
 block[j] =- process[i]; 
 break;
 }
 }
 }
 printf("\nProcess\tSize\tBlock\n");
 for(int i = 0; i < p; i++) {
 printf("P%d\t%d\t", i+1, process[i]);
 if(allocat[i] != -1)
 printf("%d\n", allocat[i] + 1);
 else
 printf("Not Allocated\n");
 }

 return 0;
}
