#include <stdio.h>
#include <stdlib.h>
#include "shared.h"



//Прочитане на файла и записването му в масив
struct pixel *get_file_data(char*);

void get_dimentions(char*,int* rows,int *cols);

void write_data(struct pixel *,int ,int );