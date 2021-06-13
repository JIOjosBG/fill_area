#include "read_file.h"

struct pixel *get_file_data(char *filename)
{

  FILE *fp;
  //int c;
  int rows, columns;
  struct pixel *arr;
  int s = sizeof(struct pixel);
  arr = malloc(sizeof(s));

  fp = fopen("files/data.txt", "r");
  fscanf(fp, "%d:%d", &rows, &columns);
  printf("%d %d", rows, columns);
  //kak da cheta kletkite
  for (int i = 0; i < columns * rows; i++)
  {
    fscanf(fp, "%d:%d:%d ", (int *)&((arr + i)->R), (int *)&((arr +i)->G), (int *)&((arr + i)->B));

    //printf("%d:%d:%d ", ((arr + i)->R), ((arr + i)->G), ((arr + i)->B));
  }
  return arr;

}