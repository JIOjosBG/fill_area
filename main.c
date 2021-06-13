#include <stdio.h>
#include <stdlib.h>

#include "take_input.h"
#include "read_file.h"



int main()
{
  // int cols = 5, rows = 2;
  // int *nums = malloc(sizeof(int) * (10 * 10*3));

  // for(int i=0;i<rows;i++){
  //   for(int j=0;j<cols;j++){
  //     printf("%d:%d:%d ",*(nums+i*rows+j+0),*(nums+i*rows+j+1),*(nums+i*rows+j+2));
  //   }
  //     printf("\n");
  // }

  // FILE * fp;
  // fp = fopen (new, "r");
  // int c;
  // while(1) {
  //     c = fgetc(fp);
  //     if( feof(fp) ) { 
  //        break ;
  //     }
  //     printf("%c", c);
  //  }
  // fclose(fp);



  char filename[1000];
  int row,column;
  get_filename(filename);
  get_coordinates(&row,&column);
  struct pixel *grid = get_file_data(filename);


  printf("%d %d", row, column);
  printf("\n %d %d %d", grid->R, grid->G, grid->B);
  for (int i = 0; i < 3 * 3; i++)
  {
    if(i%3==0){
      printf("\n");
    }
    printf("%d:%d:%d ", (grid+i)->R, (grid+i)->G, (grid+i)->B);
  }
  free(grid);
  return 0;
}