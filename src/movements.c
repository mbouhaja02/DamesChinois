#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "geometry.h"
#include "neighbors.h"
#include "world.h"
#include "ensemble.h"
#include "movements.h"
#include "game.h"





/* Fonction qui ajoute à un ensemble les déplacements simple possible pour un pawn */
void deplacements_simple( struct game_t game, struct ensemble* ds ){
    if(world_get_sort(game.w, game.position) == 1){
        unsigned int neighbor;
        enum sort_t b;
        init_neighbors(game.seed);
        for (enum dir_t j = SEAST; j < NWEST +1  ;j++){
            neighbor = get_neighbor(game.position,j);
            if (existence_of_neighbor(game.position, neighbor)==1){
                b = world_get_sort(game.w, neighbor);
                if ( b == NO_SORT){
                    ajout_position( ds , neighbor) ;
                }
            }
        }
    }
      
}
/*Fonction qui ajoute à un ensemble les differents capture simple disponibles pour un pawn*/
void capture_deplacements_simple( struct game_t game, struct ensemble* cds ){
    unsigned int neighbor;
    enum sort_t b;
    enum color_t c;
    init_neighbors(game.seed);
    if(world_get_sort(game.w, game.position) == 1){
        for (enum dir_t j = SEAST; j < NWEST +1  ;j++){
            neighbor = get_neighbor(game.position,j);
            if (existence_of_neighbor(game.position, neighbor)==1 && neighbor % WIDTH != 0 && neighbor % WIDTH != 9){
                b = world_get_sort(game.w, neighbor);
                c = world_get(game.w, neighbor);
                if ( b != NO_SORT && c != game.current_player){
                    ajout_position( cds , neighbor) ;
                }
            }
        }
    }
      
}


/* Fonction qui ajoute à un ensemble les sauts simples possibles pour un pawn*/
void saut_simple(struct game_t game , struct ensemble* css){
    unsigned int neighbor;
    unsigned int neighbor_of_neighbor; 
    init_neighbors(game.seed);
    if(world_get_sort(game.w, game.position) == 1){
        for (enum dir_t j = SEAST; j < NWEST +1 ;j++){
            neighbor = get_neighbor(game.position,j);
            neighbor_of_neighbor = get_neighbor(neighbor,j);
            if (existence_of_neighbor(game.position, neighbor)==1 && existence_of_neighbor(neighbor, neighbor_of_neighbor)==1){
                if ((world_get_sort(game.w , neighbor_of_neighbor ) == NO_SORT) && (world_get_sort(game.w , neighbor ) != NO_SORT)){
                    ajout_position( css , neighbor_of_neighbor);
                }
            }
        }
    }
}
/*Fonction qui ajoute à un ensemble les differents capture saut simple disponibles pour un pawn*/
void capture_saut_simple(struct game_t game , struct ensemble* css){
    unsigned int neighbor;
    unsigned int neighbor_of_neighbor; 
    init_neighbors(game.seed);
    if(world_get_sort(game.w, game.position) == 1){
        for (enum dir_t j = SEAST; j < NWEST +1 ;j++){
            neighbor = get_neighbor(game.position,j);
            neighbor_of_neighbor = get_neighbor(neighbor,j);
            enum color_t c = world_get(game.w, neighbor_of_neighbor);
            if (existence_of_neighbor(game.position, neighbor)==1 && existence_of_neighbor(neighbor, neighbor_of_neighbor)==1 && neighbor_of_neighbor % WIDTH != 0 && neighbor_of_neighbor % WIDTH != 9){
                if ((world_get_sort(game.w , neighbor_of_neighbor ) != NO_SORT) && (c != game.current_player) && (world_get_sort(game.w , neighbor ) != NO_SORT)){
                    ajout_position( css , neighbor_of_neighbor);
                }
            }
        }
    }
}

/* Fonction qui ajoute à un ensemble des sauts multiples sans répétition (sinon la boucle sera infinie) pour un pawn*/
void saut_multiple(struct game_t game , struct ensemble* sm  ){
    saut_simple( game, sm);
    if(world_get_sort(game.w, game.position) == 1){
        for (unsigned int i = 0 ; i < sm->taille ; i++){
            game.position = sm->positions[i];
            if(place_visited ( sm, game.position ) == 0){
                saut_multiple(game , sm);
            }
        }
    }
}

/*Fonction qui ajoute les differents capture saut simple disponibles pour un pawn*/
void capture_saut_multiple(struct game_t game , struct ensemble* csm  ){
    capture_saut_simple( game, csm);
    if(world_get_sort(game.w, game.position) == 1){
        for (unsigned int i = 0 ; i < csm->taille ; i++){
            game.position = csm->positions[i];
            if(place_visited ( csm, game.position ) == 0){
                capture_saut_multiple(game , csm);
            }
        }
    }
}

/* Fonction qui retourne l'ensemble des mouvements disponibles en concatenons tous les ensemble précédents */
void mvts_disponibles (struct game_t game, struct ensemble* md) 
{  
    positions_init(md);
    deplacements_simple( game , md );
    saut_multiple( game , md );
    translation_cardinal( game, md);
    saut_semi_diagonal(game, md);
    //capture_deplacements_simple(game, md);
    //capture_saut_simple(game, md);
    //capture_saut_multiple(game, md);
    //capture_saut_semi_diagonal(game, md);
    //capture_translation_cardinal(game, md);
}

/*Tout mouvement de la pièce qui se termine sur une case 
  contenant une pièce d'une couleur différente capture 
          la pièce en question.*/
void capture_dispo(struct game_t game, struct ensemble* cd){
    positions_init(cd);
    capture_deplacements_simple(game, cd);
    capture_saut_simple(game, cd);
    capture_saut_multiple(game, cd);
    capture_saut_semi_diagonal(game, cd);
    capture_translation_cardinal(game, cd);
}
/* Fonction qui retourne l'ensemble des mouvements possibles pour la tour*/
void translation_cardinal(struct game_t game, struct ensemble* tc){
    if (world_get_sort(game.w, game.position) == 2){
        enum dir_t tab_dir[4] = {EAST, WEST, NORTH, SOUTH};
        unsigned int idx ;
        int m;
        for(int i =0; i < 4; i++){
            m = 0;
            idx = get_neighbor(game.position, tab_dir[i]);
            enum color_t c = world_get(game.w, idx);
            if (existence_of_neighbor(game.position , idx)==1 && c != game.current_player){
                while(world_get_sort(game.w, idx) == NO_SORT && m == 0){
                    ajout_position(tc, idx);
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

/* Fonction qui retourne l'ensemble des mouvements possibles pour l'éléphant*/
void saut_semi_diagonal(struct game_t game , struct ensemble* ssd){
    if(world_get_sort(game.w, game.position) == 3){
        enum dir_t tab_dir[4] = {NORTH, SOUTH, EAST, WEST};
        for(int i =0; i < 2; i++){
            for(int j = 2; j < 4; j++){
                unsigned int idx = game.position;
                unsigned int idx1 = get_neighbor(idx, tab_dir[i]);
                unsigned int idx2  =get_neighbor(idx1, tab_dir[j]);

                while(existence_of_neighbor(idx, idx1) == 1 && existence_of_neighbor(idx1, idx2) == 1 ){
                    if(world_get_sort(game.w, idx2) == NO_SORT){
                        ajout_position(ssd, idx2);
                    }
                    idx = idx2;
                    idx1 = get_neighbor(idx, tab_dir[i]);
                    idx2 = get_neighbor(idx1, tab_dir[j]);

                }

            }
        }
    }
    
}
/*Fonction qui ajoute à un ensemble les differents captures disponibles pour une tour*/
void capture_translation_cardinal(struct game_t game, struct ensemble* tc){
    if (world_get_sort(game.w, game.position) == 2){
        enum dir_t tab_dir[4] = {EAST, WEST, NORTH, SOUTH};
        unsigned int idx ;
        int m;
        for(int i =0; i < 4; i++){
            m = 0;
            idx = get_neighbor(game.position, tab_dir[i]);
            enum color_t c = world_get(game.w, idx);
            if (existence_of_neighbor(game.position , idx)==1){
                while(world_get_sort(game.w, idx) != NO_SORT && m == 0 && c!= game.current_player){
                    ajout_position(tc, idx);
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

/* Fonction qui rajoute à un ensemble les differents captures disponibles pour un éléphant*/
void capture_saut_semi_diagonal(struct game_t game , struct ensemble* ssd){
    if(world_get_sort(game.w, game.position) == 3){
        enum dir_t tab_dir[4] = {NORTH, SOUTH, EAST, WEST};
        for(int i =0; i < 2; i++){
            for(int j = 2; j < 4; j++){
                unsigned int idx = game.position;
                unsigned int idx1 = get_neighbor(idx, tab_dir[i]);
                unsigned int idx2  =get_neighbor(idx1, tab_dir[j]);
                enum color_t c = world_get(game.w, idx2);
                while(existence_of_neighbor(idx, idx1) == 1 && existence_of_neighbor(idx1, idx2) == 1 && c != game.current_player){
                    if(world_get_sort(game.w, idx2) != NO_SORT){
                        ajout_position(ssd, idx2);
                    }
                    idx = idx2;
                    idx1 = get_neighbor(idx, tab_dir[i]);
                    idx2 = get_neighbor(idx1, tab_dir[j]);
                    c = world_get(game.w, idx2);

                }

            }
        }
    }
    
}

