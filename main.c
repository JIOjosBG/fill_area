#include <stdio.h>
#include <stdlib.h>

#include "shared.h"

#include "take_input.h"
#include "work_file.h"
#include "fill_area.h"


void start() {
  //ime na fail
  char filename[1000];
  //koordinati za zapylvane
  int x,y;
  //vzimane na imeto ot konzolata
  get_filename(filename);
  //dannite na grida i razmera mu
  struct pixel *grid = get_file_data(filename);
  int rows,cols;
  //zapisvane na razmera v promenlivi
  get_dimentions(filename,&rows,&cols);
  //printirane na razmer i danni
  printf("%d %d", rows, cols);
  print_data(grid,rows,cols);
  //vzimane na koordinati ot konzolata
  get_coordinates(&x,&y);
  //cvqt ot izbranite koordinati
  int starter_color = (grid+x+y*cols)->R+(grid+x+y*cols)->G+(grid+x+y*cols)->B;
  //zapylvane na oblast
  //funkciqta vzima grid s razmera mu, nachalni koordinati i pyrvonachalniq cvqt, koito ne se promenq s rekursiqta na funkciqta
  fill_area(grid,rows,cols,x,y,starter_color);
  //printirane
  print_data(grid,rows,cols);
  //zapisvane v files/res.txt
  write_data(grid,rows,cols);
  //osvobojdavane na zadelenata pamet
  free(grid);
}

int main()
{
  start();
  return 0;
}