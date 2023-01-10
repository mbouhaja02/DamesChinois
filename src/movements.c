#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "set.h"
#include "movements.h"
#include "game.h"
#include "prison.h"

#include <assert.h>




//Stocks a set of available simple moves for the current position
void simple_moves( struct game_t game, struct set* sm ){
    if(world_get_sort(game.w, game.position) == PAWN){
        unsigned int neighbor;
        enum sort_t b;
        init_neighbors(game.seed);
        for (enum dir_t j = SEAST; j < NWEST +1  ;j++){
            neighbor = get_neighbor(game.position,j);
            if (existence_of_neighbor(game.position, neighbor)==1){
                b = world_get_sort(game.w, neighbor);
                if ( b == NO_SORT){
                    add_position(sm, neighbor) ;
                }
            }
        }
    }      
}
//Stocks a set of available simple moves captured for the current position
void simple_moves_capture( struct game_t game, struct set* smc){
    unsigned int neighbor;
    enum sort_t b;
    enum color_t c;
    init_neighbors(game.seed);
    if(world_get_sort(game.w, game.position) == PAWN){
        for (enum dir_t j = SEAST; j < NWEST +1  ;j++){
            neighbor = get_neighbor(game.position,j);
            if (existence_of_neighbor(game.position, neighbor)==1 && neighbor % WIDTH != 0 && neighbor % WIDTH != 9){
                b = world_get_sort(game.w, neighbor);
                c = world_get(game.w, neighbor);
                if ( b == PAWN && c != game.current_player){
                    add_position(smc, neighbor) ;
                }
            }
        }
    }
      
}


//Stocks a set of available simple jumps for the current position
void simple_jumps(struct game_t game , struct set* sj){
    unsigned int neighbor;
    unsigned int neighbor_of_neighbor; 
    init_neighbors(game.seed);
    if(world_get_sort(game.w, game.position) == PAWN){
        for (enum dir_t j = SEAST; j < NWEST +1 ;j++){
            neighbor = get_neighbor(game.position,j);
            neighbor_of_neighbor = get_neighbor(neighbor,j);
            if (existence_of_neighbor(game.position, neighbor)==1 && existence_of_neighbor(neighbor, neighbor_of_neighbor)==1){
                if ((world_get_sort(game.w , neighbor_of_neighbor ) == NO_SORT) && (world_get_sort(game.w , neighbor ) == PAWN) ){
                    add_position(sj, neighbor_of_neighbor);
                }
            }
        }
    }
}
//Stocks a set of available simple jumps captured for the current position
void simple_jumps_capture(struct game_t game , struct set* sjc){
    unsigned int neighbor;
    unsigned int neighbor_of_neighbor; 
    init_neighbors(game.seed);
    if(world_get_sort(game.w, game.position) == 1){
        for (enum dir_t j = SEAST; j < NWEST +1 ;j++){
            neighbor = get_neighbor(game.position,j);
            neighbor_of_neighbor = get_neighbor(neighbor,j);
            if (existence_of_neighbor(game.position, neighbor)==1 && existence_of_neighbor(neighbor, neighbor_of_neighbor)==1 && neighbor_of_neighbor % WIDTH != 0 && neighbor_of_neighbor % WIDTH != 9){
                if ((world_get_sort(game.w , neighbor_of_neighbor ) == PAWN) && (world_get(game.w, neighbor_of_neighbor) != game.current_player) && (world_get(game.w, neighbor_of_neighbor) != MAX_COLOR) && (world_get_sort(game.w , neighbor ) == PAWN)){
                    add_position(sjc, neighbor_of_neighbor);
                }
            }
        }
    }
}

//Stocks a set of available multiple jumps for the current position
void multiple_jumps(struct game_t game , struct set* mj  ){
    simple_jumps( game, mj);
    if(world_get_sort(game.w, game.position) == PAWN){
        for (unsigned int i = 0 ; i < mj->taille ; i++){
            game.position = mj->positions[i];
            if(place_visited ( mj, game.position ) == 0){
                multiple_jumps(game , mj);
            }
        }
    }
}

//Stocks a set of available multiple jumps captured for the current position
void multiple_jumps_capture(struct game_t game , struct set* mjc  ){
    simple_jumps_capture(game, mjc);
    if(world_get_sort(game.w, game.position) == PAWN){
        for (unsigned int i = 0 ; i < mjc->taille ; i++){
            game.position = mjc->positions[i];
            if(place_visited ( mjc, game.position ) == 0){
                multiple_jumps_capture(game , mjc);
            }
        }
    }
}

//Stocks a set of available moves for the current position assembling all the past sets
void available_movements(struct game_t game, struct set* am) 
{  
    positions_init(am);
    simple_moves(game, am);
    multiple_jumps(game, am);
    cardinal_translations(game, am);
    semi_diagonal_jumps(game, am);
    simple_moves_capture(game, am);
    multiple_jumps_capture(game, am);
    semi_diagonal_jumps_capture(game, am);
    cardinal_translations_capture(game, am);
}

//If a destination of a player pawn meets the other player's pawn it will be captured 
void available_captures(struct game_t game, struct set* ac){
    positions_init(ac);
    simple_moves_capture(game, ac);
    multiple_jumps_capture(game, ac);
    semi_diagonal_jumps_capture(game, ac);
    cardinal_translations_capture(game, ac);
}

//Stocks a set of available moves for the current position if its a tower
void cardinal_translations(struct game_t game, struct set* ct){
    if (world_get_sort(game.w, game.position) == TOUR){
        enum dir_t tab_dir[4] = {EAST, WEST, NORTH, SOUTH};
        unsigned int idx ;
        int m;
        for(int i =0; i < 4; i++){
            m = 0;
            idx = get_neighbor(game.position, tab_dir[i]);
            if (existence_of_neighbor(game.position , idx)==1 && world_get(game.w, idx) != game.current_player){
                while(world_get_sort(game.w, idx) == NO_SORT && m == 0){
                    add_position(ct, idx);
                    if (existence_of_neighbor(idx, get_neighbor(idx, tab_dir[i]))==1){
                        idx = get_neighbor(idx , tab_dir[i]);
                    }
                    else{
                        m = 1;
                    }
                }
            }
        }
    }
}

//Stocks a set of available moves for the current position if its an elephant
void semi_diagonal_jumps(struct game_t game , struct set* sdj){
    if(world_get_sort(game.w, game.position) == ELEPHANT){
        enum dir_t tab_dir[4] = {NORTH, SOUTH, EAST, WEST};
        for(int i =0; i < 2; i++){
            for(int j = 2; j < 4; j++){
                unsigned int idx = game.position;
                unsigned int idx1 = get_neighbor(idx, tab_dir[i]);
                unsigned int idx2  =get_neighbor(idx1, tab_dir[j]);

                while(existence_of_neighbor(idx, idx1) == 1 && existence_of_neighbor(idx1, idx2) == 1 ){
                    if(world_get_sort(game.w, idx2) == NO_SORT){
                        add_position(sdj, idx2);
                    }
                    idx = idx2;
                    idx1 = get_neighbor(idx, tab_dir[i]);
                    idx2 = get_neighbor(idx1, tab_dir[j]);

                }

            }
        }
    }
    
}
//Stocks a set of available capture jumps for the current position if its a tower
void cardinal_translations_capture(struct game_t game, struct set* ctc){
    if (world_get_sort(game.w, game.position) == TOUR){
        enum dir_t tab_dir[4] = {EAST, WEST, NORTH, SOUTH};
        unsigned int idx ;
        int m;
        for(int i =0; i < 4; i++){
            m = 0;
            idx = get_neighbor(game.position, tab_dir[i]);
            if (existence_of_neighbor(game.position , idx)==1){
                while(world_get_sort(game.w, idx) != NO_SORT && m == 0 && world_get(game.w, idx) != game.current_player){
                    add_position(ctc, idx);
                    if (existence_of_neighbor(idx, get_neighbor(idx, tab_dir[i]))==1){
                        idx = get_neighbor(idx , tab_dir[i]);
                    }
                    else{
                        m = 1;
                    }
                }
            }
        }
    }
}

//Stocks a set of available capture jumps for the current position if its an elephant
void semi_diagonal_jumps_capture(struct game_t game , struct set* sdjc){
    if(world_get_sort(game.w, game.position) == ELEPHANT){
        enum dir_t tab_dir[4] = {NORTH, SOUTH, EAST, WEST};
        for(int i =0; i < 2; i++){
            for(int j = 2; j < 4; j++){
                unsigned int idx = game.position;
                unsigned int idx1 = get_neighbor(idx, tab_dir[i]);
                unsigned int idx2  =get_neighbor(idx1, tab_dir[j]);
                while(existence_of_neighbor(idx, idx1) == 1 && existence_of_neighbor(idx1, idx2) == 1 && world_get(game.w, idx2) != game.current_player){
                    if(world_get_sort(game.w, idx2) != NO_SORT){
                        add_position(sdjc, idx2);
                    }
                    idx = idx2;
                    idx1 = get_neighbor(idx, tab_dir[i]);
                    idx2 = get_neighbor(idx1, tab_dir[j]);

                }

            }
        }
    }
    
}

