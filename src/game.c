#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "world.h"
#include "set.h"
#include "movements.h"
#include "game.h"
#include "prison.h"




//chooses a random color designed to a player
enum color_t get_random_player(){
    srand(time(NULL));
    enum color_t r = rand() % (MAX_COLOR - 1) + 1;
    return r;
}

//helps switch players in the game
enum color_t next_player(enum color_t current_player){
    if (current_player == BLACK)
        return WHITE;
    if (current_player == WHITE)
        return BLACK;
    return MAX_COLOR;
}

//Choose out of the positions of the current player
void choose_random_piece_belonging_to(struct game_t* game){
    struct set pw, pb;
    srand(time(NULL));
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

//Choose out of the list of available moves
unsigned int choose_random_move_for_piece(struct game_t game){
    srand(time(NULL));
    struct set sm;
    unsigned int m ;
    available_movements(game, &sm);
    unsigned int r = rand();
    while(sm.taille == 0){
        choose_random_piece_belonging_to(&game);
        available_movements(game, &sm);
    }
    unsigned int module = sm.taille;
    r = r % module ;
    m = sm.positions[r];

    return m;
}

//make the move in the world by changing the initial position in the game to the
//destination and empties the initial square
void move_piece(struct game_t game, unsigned int dst){
    struct set jail;
    available_captures(game, &jail);
    if(place_visited(&jail, dst) == 1){
        add_prisoner(game.jail, game, dst);
    }
    world_set_sort(game.w, dst, NO_SORT);
    world_set(game.w, dst, NO_COLOR);
    world_set_sort(game.w, dst, world_get_sort(game.w, game.position));
    world_set(game.w, dst, world_get(game.w, game.position));
    world_set_sort(game.w, game.position, NO_SORT);
    world_set(game.w, game.position, NO_COLOR);
    escape_attempts(game);
}

//Initializes game
struct game_t game_initializer(){
    struct game_t game;
    game.current_player = NO_COLOR ; 
    game.turn = 0;
    game.w = world_init();
    game.jail = init_prison();
    game.seed = 0;
    game.position = 0;
    game.victory = choose_random_victory_type() ; 
    return game ; 
}

//chooses the relation mode randomly
void choose_random_relation(struct game_t *game){
    srand(time(NULL));
    int random_int = rand();
    game->seed = random_int % MAX_RELATIONS;
}

//Chooses the next relation randomly
void choose_next_random_relation(struct game_t* game){
    srand(time(NULL));
    unsigned int relation = game->seed;
    while (game->seed == relation){
        unsigned int random_uint = rand();
        game->seed = random_uint % MAX_RELATIONS;
    }
}


