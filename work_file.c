#include "work_file.h"

struct pixel *get_file_data(char *filename)
{

  FILE *fp;
  int rows, columns;
  struct pixel *arr;
  int s = sizeof(struct pixel*);

  fp = fopen(filename, "r");
  fscanf(fp, "%d %d", &columns, &rows);
  arr = malloc(sizeof(s)*rows*columns);
  for (int i = 0; i < columns * rows; i++)
  {
    fscanf(fp, "%d:%d:%d ", (int *)&((arr + i)->R), (int *)&((arr +i)->G), (int *)&((arr + i)->B));
    //printf("%d",i);
  }
  fclose(fp);
  return arr;

}
void get_dimentions(char* filename,int* rows,int *cols){
    FILE *fp;

    fp = fopen(filename, "r");
    fscanf(fp, "%d %d", cols, rows);
    fclose(fp);
}

void write_data(struct pixel *data,int rows, int cols){
  FILE* output;
  output = fopen("files/res.txt", "w");
  fprintf(output, "%d %d\n", cols,rows);
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      fprintf(output, "%d:%d:%d ", (data+j+i*cols)->R,(data+j+i*cols)->G,(data+j+i*cols)->B);
    }
      fprintf(output, "\n");
    
  }
  fclose(output);
}