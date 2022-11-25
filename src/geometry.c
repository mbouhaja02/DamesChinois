#include<string.h>
#include<stdio.h>
#include "geometry.h"

const char* place_to_string(enum color_t c, enum sort_t s)
{ 
  char* description[100];
  int i = 0, j = 0;
  char* color;
  switch (c)
  {
    case 0:
      color = "no color ";
      break;
    case 1:
      color = "black ";
      break;
    case 2:
      color = "white ";
      break;
    default:
      color = "ERROR 404 ";
  }
  char* sort;
  switch (s)
  {
    case 0:
      sort = "nothing";
      break;
    case 1:
      sort = "pawn";
      break;
    
    default:
      sort = "ERROR 404";
      
  }

  
  while (color[i] != '\0') {
    description[j] = color[i];
      i++;
      j++;
  description[j] = ",";
  i = 0;
  while (sort[i] != '\0') {
    description[j+1] = sort[i];
    i++;
    j++;
    }
    description[j] = '\0';
  return description ; 
}
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
  }
  return str ;
}


