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




/*cette fonction est deja tester*/
/*Il retourne la couleur d'un joueur aléatoire*/
enum color_t get_random_player(){
    enum color_t r = rand()%2+1;
    return r;
}

/*cette fonction est deja tester*/
/*Apres le choix d'un joueur aléatoire cette fonction retourne la couleur du joueur suivant*/
enum color_t next_player(enum color_t current_player){
    if (current_player == 1)
        return 2;
    if (current_player == 2)
        return 1;
    return 0;
}

/*cette fonction est deja tester*/
/*Retourne un unsigned int qui désigne l'index d'une peice white ou black dependant du current_player*/
unsigned int choose_random_piece_belonging_to(struct world_t* w , enum color_t current_player){
    struct ensemble pw, pb;

    positions_init(&pw);
    positions_init(&pb);

    black_list(&pb, w);
    white_list(&pw, w);

    int a = rand();
    a = a % HEIGHT;
    if (current_player == 1){
        printf("pb = %d\n " , pb.positions[a]);
        return pb.positions[a];}
        
    if (current_player == 2){
        printf("pw = %d\n " , pw.positions[a]);
        return pw.positions[a];}
    return 0;
}

unsigned int choose_random_move_for_piece(struct world_t* w, unsigned int p, enum color_t current_player){
    struct ensemble sm ; 
    unsigned int m ;
    positions_init(&sm);
    if (current_player == 1)
        black_list(&sm, w);
    if (current_player == 2)
        white_list(&sm, w);

    struct ensemble* ens = mvts_disponibles(w, p, &sm);
    printf("#\n");

    unsigned int r = rand();
    unsigned int module = ens->taille;
    r = r % module + 1 ;
    printf("r = %d \n",r);
    m = ens->positions[r];
    printf("m = %d\n", m );
    return m;
}


void move_piece(struct world_t* w, unsigned int dst, unsigned int src){
    world_set_sort(w, dst, world_get_sort(w, src));
    world_set(w, dst, world_get(w, src));
    world_set_sort(w, src, NO_SORT);
    world_set(w, src, NO_COLOR);
}

