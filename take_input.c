#include "take_input.h"

void get_filename(char* var){
  char filename[1000];
  printf("filename?");
  scanf("%s",filename);
  //return filename;
  //*(var) = filename;
  strcpy(var, filename);
}

void get_coordinates(int* one, int* two){
  printf("coordinates? ");
  scanf("%d %d", one, two);

}