#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "geometry.h"
#include "world.h"
#include "game.h"
#include "neighbors.h"
#include "ensemble.h"
#include "board.h"
#include "victoire.h"

void main(){
    struct game_t game = game_initializer();
    draw_grille(game);
}



