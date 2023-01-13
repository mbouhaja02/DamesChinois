# Project Mansuba

La page de spécification du projet :

<https://www.labri.fr/perso/renault/working/teaching/projets/2022-23-S5-Mansuba.php>

La page du projet sur la forge :

https://thor.enseirb-matmeca.fr/ruby/projects/projetss5

La page des projets en général :

<https://www.labri.fr/perso/renault/working/teaching/projets/projets.php>

# Compilation
make 

./project [-h help]
          [-s an optional parametre to initialize the RNG]
          [-m an optional parametre for MAX_TURNS] 
          [-t an optional parametre to set the victory type \n]{c pour la victoire complexe}

# pour tester project
make project 

# Pour tester board
make test_board 

# Pour tester victoire
make test_victoire 

# Pour tester set
make test_ensemble

# Pour tester movements
make test_moves

# Pour tester capture
make test_capture

# Pour tester distance
make test_distance