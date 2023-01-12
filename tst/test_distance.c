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

/*int main(){
    
    struct game_t game = game_initializer();
    int joueur = get_random_player();
    init_neighbors(game.seed);
    int distance[WORLD_SIZE*WORLD_SIZE];
    distances(distance,0);
    for (int i=0; i<WORLD_SIZE; i++){
        printf("%d\t",distance[i]);
    }
    return 0;
    
}**/