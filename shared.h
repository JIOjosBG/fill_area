
#include <stdio.h>
#include <stdlib.h>

#ifndef SHARED_H
#define SHARED_H

struct pixel{
  char R;
  char G;
  char B;
};

#endif



void print_data(struct pixel *data,int,int);