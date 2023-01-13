#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "geometry.h"
#include "world.h"
#include "neighbors.h"
#include "set.h"
#include "movements.h"
#include "distance.h"
#include "game.h"

int main(){
    
    struct game_t game = game_initializer();
    init_neighbors(game.seed);
    printf("%d\n",distance_with_simple_moves(7,game));
    return 0;
    
}