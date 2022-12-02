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


/*
int choose_random_piece_belonging_to(struct world_t* w , enum color_t current_player){
    struct ensemble* pw;
    unsigned int a ; 
    white_list(pw , w);
    a = rand() % (pw->taille + 1);
    return pw->positions[a];
}

unsigned int choose_random_move_for_piece(struct world_t* w, unsigned int p){
    struct ensemble* nb ; 
    unsigned int b;
    mvts_disponibles( w , p , nb );
    b = rand() % (nb->taille + 1);
    return nb->positions[b];

}
*/

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
    int tab_black[10];
    int j = 0;
    int tab_white[10];
    int l = 0;
    for(int i  = 0; i < WORLD_SIZE; i++){
        if (world_get(w, i)==1 && world_get_sort(w, i) == 1){
            tab_black[j] = i;
            j = j + 1;
        }
        
    }
    for(int i  = 0; i < WORLD_SIZE; i++){
        if (world_get(w, i)==1 && world_get_sort(w, i) == 1){
            tab_white[l] = i;
            l = l + 1;
        }
        
    }

    int a = rand();
    a = a % 10;
    if (current_player == 1)
        return tab_black[a];
        
    if (current_player == 2)
        return tab_white[a];
    return 0;
}

unsigned int choose_random_move_for_piece(struct world_t* w, unsigned int p){
    struct ensemble sm;
    positions_init(&sm);
    struct ensemble *ens = mvts_disponibles(w, p, &sm);
    unsigned int r = rand();
    unsigned int module = ens->taille;
    r = r % module;
    unsigned int m = ens->positions[r];
    
    return m;
}

/*Déja tester*/
/*la fonction fait des modifications au niveau du monde et il retourne le nouveau monde*/
struct world_t* move_piece(struct world_t* w,unsigned int m, unsigned int p , enum color_t joueur){
    
    int idx = get_neighbor(p, m);
    world_set_sort(w, idx, 1);
    world_set(w, idx, joueur);
    world_set_sort(w, p, 0);
    world_set(w, p, 0);

    return w; 
}

