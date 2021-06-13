#include "read_file.h"

struct pixel *get_file_data(char *filename)
{

  FILE *fp;
  int rows, columns;
  struct pixel *arr;
  int s = sizeof(struct pixel);
  arr = malloc(sizeof(s));

  fp = fopen("files/data.txt", "r");
  fscanf(fp, "%d:%d", &rows, &columns);
  for (int i = 0; i < columns * rows; i++)
  {
    fscanf(fp, "%d:%d:%d ", (int *)&((arr + i)->R), (int *)&((arr +i)->G), (int *)&((arr + i)->B));
  }
  //fclose(fp);
  return arr;

}
void get_dimentions(int* rows,int *cols){
    FILE *fp;

    fp = fopen("files/data.txt", "r");
    fscanf(fp, "%d:%d", rows, cols);
    fclose(fp);
}