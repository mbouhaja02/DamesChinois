#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "geometry.h"
#include "world.h"
#include "game.h"
#include "neighbors.h"
#include "set.h"
#include "board.h"
#include "victory.h"

int main(){
    struct set ens1, ens2;
    positions_init(&ens1);
    positions_init(&ens2);
    ens1.taille = 4;
    for(unsigned int i= 0; i < ens1.taille; i++){
        ens1.positions[i] = 1;
    }
    ens2.taille = 4;
    for(unsigned int i= 0; i < ens1.taille; i++){
        ens2.positions[i] = 1;
    }
    ens2.positions[2] = 2;

    printf("%d #\n", equality_of_two_sets(ens1, ens2));


    return 0;
}