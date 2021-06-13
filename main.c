#include <stdio.h>
#include <stdlib.h>

#include "shared.h"

#include "take_input.h"
#include "read_file.h"
#include "fill_area.h"


int main()
{

  char filename[1000];
  int x,y;
  get_filename(filename);
  get_coordinates(&x,&y);
  struct pixel *grid = get_file_data(filename);
  int rows,cols;
  get_dimentions(&rows,&cols);

  printf("%d %d", rows, cols);
  print_data(grid,rows,cols);
  fill_area(grid,rows,cols,x,y);
  print_data(grid,rows,cols);


  free(grid);
  return 0;
}