#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "wolrd.h"
struct ensemble;
void positions_init(struct ensemble* pi);
void ajout_position(struct ensemble* p , int place );
#endif 
