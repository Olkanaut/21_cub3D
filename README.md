# 21_cub3D

The goal was to make a dynamic view inside a maze, in which the player should find a way. The mandatory part of a subject required building up a 3d view of the maze based in a given 2d plan using raycasting algorythm. The walls should be texturized according their orientation.
As a bonus part I implemented multiple regimes and added some features to enhance the experience: wall and object collisions, a skybox, music, HUD, ability to pick up objects and a 'weapon' (a scoop net and a hand:). 

![alt text](rendered_scenes/neon1.png)
Regime: bonus neon

![alt text](rendered_scenes/fire1.png)
Regime: bonus cabaret


START playing:
- make bonus && ./cub3D data_neon.cub - bonus (neon)
- make cabaret && ./cub3D data_cabaret.cub - bonus (cabaret)
- make && ./cub3D data.cub (mandatory part)
- make bonus && ./cub3D data.cub - bonus (ghosts)

PLAY:
- use AWSD or ↑ and ↓ to navigate through the maze
- use QE or ← and → to rotate the view

Regimes:
- mandatory || to compile: make && ./cub3D data.cub
- bonus (neon) || to compile: make bonus && ./cub3D data_neon.cub or make bonus && ./cub3D data.cub
- bonus (cabaret) || to compile: make cabaret && ./cub3D data_cabaret.cub

Bonuses:
+
+
+




More pictures:

![alt text](rendered_scenes/fire2.png)
![alt text](rendered_scenes/ghost1.png)
![alt text](rendered_scenes/neon2.png)

