#include "shared.h"

void print_data(struct pixel *data,int rows,int cols){
  printf("\n");
  for (int i = 0; i < rows * cols; i++)
  {
    if(i%3==0){
      printf("\n");
    }
    printf("%d:%d:%d ", (data+i)->R, (data+i)->G, (data+i)->B);
  }
  printf("\n");
}