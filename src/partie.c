#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "partie.h"


int choose_random_piece_belonging_to(struct world_t w,enum color_t current_player){
    struct ensemble* pw;
    unsigned int a ; 
    white_list(pw , &w);
    a = rand() % (pw.taille + 1)
    return pw.postions[a];
}

unsigned int choose_random_move_for_piece(struct world_t w, unsigned int p){
    struct ensemble* nb ; 
    unsigned int b;
    mvts_disponibles( w , p , nb );
    b = rand() % (nb.taille + 1)
    return nb.positions[b];

}
struct world_t move_piece(struct world_t w,unsigned int m, unsigned int p , enum color_t joueur)
    struct world_t* wt = world_init();
    world_set_sort( w, p, 0 );
    world_set(w, p , 0 );
    world_set_sort( w, m , 1);
    world_set(w, m, joueur);
}

