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

void main(){
    struct game_t game = game_initializer();
    start(game);
    draw_world(game);
}




