#include "fill_area.h"
#include <math.h>

int sum(struct pixel *data,int rows,int cols,int x, int y){
  return (data+x+y*cols)->R+(data+x+y*cols)->G+(data+x+y*cols)->B;
}

void fill_area(struct pixel *data, int rows, int cols, int x, int y)
{
  int next;
  int current = (data+x+y*cols)->R+(data+x+y*cols)->G+(data+x+y*cols)->B;
  int difference;
  (data+x+y*cols)->R=0;
  (data+x+y*cols)->G=0;
  (data+x+y*cols)->B=0;
  if(x+1<cols && x+1>=0 && y>=0 && y<rows){
    next=sum(data,rows,cols,x+1,y);
    difference = next-current;
    if(difference>=-3 && difference<=3 && next!=0){
      fill_area(data,rows,cols,x+1,y);
    }
  }
  if(x<cols && x>=0 && y+1>=0 && y+1<rows){
    next=sum(data,rows,cols,x,y+1);
    difference = next-current;
    if(difference>=-3 && difference<=3 && next!=0){
      fill_area(data,rows,cols,x,y+1);
    }
  }
  if(x-1<cols && x-1>=0 && y>=0 && y<rows){
    next=sum(data,rows,cols,x-1,y);
    difference = next-current;
    if(difference>=-3 && difference<=3 && next!=0){
      fill_area(data,rows,cols,x-1,y);
    }
  }
  if(x<cols && x>=0 && y-1>=0 && y-1<rows){
    next=sum(data,rows,cols,x,y-1);
    difference = next-current;
    if(difference>=-3 && difference<=3 && next!=0){
      fill_area(data,rows,cols,x,y-1);
    }
  }
  
}