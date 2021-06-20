#include "take_input.h"

void get_filename(char* var){
  char filename[100];
  printf("filename: ");
  scanf("%s",filename);
  strcpy(var, filename);
}

void get_coordinates(int* one, int* two){
  printf("coordinates: ");
  scanf("%d %d", one, two);

}