#include< stdlib.h>
#include<string.h>
#include<stdio.h>
#include "geometry.h"

const char* place_to_string(enum color_t c, enum sort_t s)
{
  char* str;
  switch (c)
  {
    case 0:
      str = "no color";
      break;
    case 1:
      str = "black";
      break;
    case 2:
      str = "white";
      break;
    default:
      str = "ERROR 404";
  }
  char* str2;
  switch (s)
  {
    case 0:
      str2 = "nothing";
      break;
    case 1:
      str2 = "pawn";
      break;
    
    default:
      str2 = "ERROR 404";
      
  }

  
  
  return  printf("the color is %s and sort is %s \n", str, str2 );
}

const char* dir_to_string(enum dir_t d)
{
  char* str;
  switch (d)
  {
    case 0:
      str = "no direction";
      break;
    case 1:
      str = "EAST";
      break;
    case 2:
      str = "NEAST";
      break;
    case 3:
      str = "NORTH";
      break;
    case 4:
      str = "NWEST";
      break;
    case -1:
      str = "WEST";
      break;
    case -2:
      str = "SWEST";
      break;
    case -3:
      str = "SOUTH";
      break;
    case -4:
      str = "SEAST";
      break;
    default:
      str = "ERROR 404 ";
      break;
  }

  return printf("the directions of the pawn is %s \n", str);
}

<<<<<<< HEAD
=======
int main()
{
  char* str = place_to_string(2, 1);
  char* str2 = dir_to_string(3);
  
  return 0;
}
>>>>>>> 740335a39d35f2bab07e010dc9bb9e02a1e8ef1d
