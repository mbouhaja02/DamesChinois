#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "game.h"
#include "victoire.h"
#include "prison.h"




/*cette fonction est deja tester*/
/*Il retourne la couleur d'un joueur aléatoire*/
enum color_t get_random_player(){
    time_t t;
    srand(time(&t));
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
void choose_random_piece_belonging_to(struct game_t* game){
    time_t t;
    struct ensemble pw, pb;
    srand(time(&t));
    positions_init(&pw);
    positions_init(&pb);
    black_list(&pb, game->w);
    white_list(&pw, game->w);
    int a = rand();
    a = a % pb.taille ;
    int b = rand();
    b = b % pw.taille;
    if (game->current_player == 1){
        game->position =pb.positions[a];}
    if (game->current_player == 2){
        game->position = pw.positions[b];}
}
    
unsigned int choose_random_move_for_piece(struct game_t game){
    time_t t;
    srand(time(&t));
    struct ensemble sm, cd; 
    positions_init(&cd);
    unsigned int m ;
    mvts_disponibles(game, &sm);
    unsigned int r = rand();
    while(sm.taille == 0){
        choose_random_piece_belonging_to(&game);
        mvts_disponibles(game, &sm);
    }
    unsigned int module = sm.taille;
    r = r % module ;
    m = sm.positions[r];

    return m;
}


void move_piece(struct game_t game, unsigned int dst){
    struct ensemble jail;
    capture_dispo(game, &jail);
    if(place_visited(&jail, dst) == 1){
        add_prisoner(game.prison, game, dst);
    }
    world_set_sort(game.w, dst, NO_SORT);
    world_set(game.w, dst, NO_COLOR);
    world_set_sort(game.w, dst, world_get_sort(game.w, game.position));
    world_set(game.w, dst, world_get(game.w, game.position));
    world_set_sort(game.w, game.position, NO_SORT);
    world_set(game.w, game.position, NO_COLOR);
    escape_attempts(game);
}

struct game_t game_initializer(){
    struct game_t game;
    game.current_player = 0 ; 
    game.tour = 0;
    game.w = world_init();
    game.prison = init_prison();
    game.seed = 0;
    game.position = 0;
    game.victoire = 0 ; 
    return game ; 
}