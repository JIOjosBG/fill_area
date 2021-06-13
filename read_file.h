#include <stdio.h>
#include <stdlib.h>
struct pixel{
  char R;
  char G;
  char B;
};

//Прочитане на файла и записването му в масив
struct pixel *get_file_data(char*);