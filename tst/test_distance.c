#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#include "geometry.h"
#include "world.h"
#include "neighbors.h"
#include "ensemble.h"
#include "movements.h"
#include "game.h"

int main(){
    
    struct game_t game = game_initializer();
    int joueur = get_random_player();
    init_neighbors(game.seed);
}