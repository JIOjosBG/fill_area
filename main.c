#include <stdio.h>
#include <stdlib.h>

#include "shared.h"

#include "take_input.h"
#include "work_file.h"
#include "fill_area.h"


int main()
{

  char filename[1000];
  int x,y;
  get_filename(filename);
  get_coordinates(&x,&y);
  struct pixel *grid = get_file_data(filename);
  int rows,cols;
  get_dimentions(filename,&rows,&cols);

  printf("%d %d", rows, cols);
  print_data(grid,rows,cols);
  int starter = (grid+x+y*cols)->R+(grid+x+y*cols)->G+(grid+x+y*cols)->B;
  fill_area(grid,rows,cols,x,y,starter);
  print_data(grid,rows,cols);
  write_data(grid,rows,cols);

  free(grid);
  return 0;
}