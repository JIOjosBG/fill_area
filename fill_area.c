#include "fill_area.h"
#include <math.h>

int sum(struct pixel *data,int rows,int cols,int x, int y){
  return (data+x+y*cols)->R+(data+x+y*cols)->G+(data+x+y*cols)->B;
}

void fill_area(struct pixel *data, int rows, int cols, int x, int y, int starter)
{
  int next;
  //nqma nujda ot current, zashtoto ne sravnqvame sys segashnata kletka, a s nachalnata (starter)
  //int current = (data+x+y*cols)->R+(data+x+y*cols)->G+(data+x+y*cols)->B;
  int difference;
  //ocvetqvame segashnata kletka
  (data+x+y*cols)->R=0;
  (data+x+y*cols)->G=0;
  (data+x+y*cols)->B=0;
  //s pyrvite ifove proverqva dali sme stignali do kraq na masiva i dali 
  if(x+1<cols && x+1>=0 && y>=0 && y<rows){
    //cveta na sledvashtata kletka
    next=sum(data,rows,cols,x+1,y);
    //razlikata (ako e poveche ot 3, znachi sredno aritmetichnoto e poveche ot 1)
    difference = next-starter;
    if(difference>=-3 && difference<=3 && next!=0){
      //rekursiq, kato podava masiv s razmeri i syshtiq nachalen cvqt
      fill_area(data,rows,cols,x+1,y,starter);
    }
  }
  if(x<cols && x>=0 && y+1>=0 && y+1<rows){
    next=sum(data,rows,cols,x,y+1);
    difference = next-starter;
    if(difference>=-3 && difference<=3 && next!=0){
      fill_area(data,rows,cols,x,y+1,starter);
    }
  }
  if(x-1<cols && x-1>=0 && y>=0 && y<rows){
    next=sum(data,rows,cols,x-1,y);
    difference = next-starter;
    if(difference>=-3 && difference<=3 && next!=0){
      fill_area(data,rows,cols,x-1,y,starter);
    }
  }
  if(x<cols && x>=0 && y-1>=0 && y-1<rows){
    next=sum(data,rows,cols,x,y-1);
    difference = next-starter;
    if(difference>=-3 && difference<=3 && next!=0){
      fill_area(data,rows,cols,x,y-1,starter);
    }
  }
  
}