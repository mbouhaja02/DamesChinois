#include<string.h>
#include<stdio.h>
#include "geometry.h"

const char* place_to_string(enum color_t c, enum sort_t s)
{ 
 
  char* str;
  int t = c + 10 * s;
  switch (t)
  {
    case 0:
      str = "no color no pawn";
      break;
    case 10:
      str = "attention pawn with no color";
      break;
    case 2:
      str = "no pawn to associate a color";
      break;
    case 1:
      str = "no pawn to associate a color";
      break;
    case 11:
      str = "pawn with black color";
      break;
    case 12:
      str = "pawn with white color";
      break;
    default:
      str = "Max colors or Max pawns";
  }
  
  return str;
  
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


