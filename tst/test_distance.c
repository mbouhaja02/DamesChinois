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
    printf("%d\n",is_neighbor(7,9));
    printf("%d\n",distance(7,9));
    return 0;
    
}