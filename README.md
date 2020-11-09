# 21_cub3D

The goal was to make a dynamic view inside a maze, in which the player should find a way. The mandatory part of a subject required building up a 3d view of the maze based in a given 2d plan using raycasting algorythm. The walls should be texturized according their orientation.
As a bonus part I implemented multiple regimes and added some features to enhance a player's experience: wall and object collisions, a skybox, music, HUD, ability to pick up objects and to display the count of picked ones and a 'weapon' (a scoop net and a hand:). 

START playing:
make bonus && ./cub3D data_neon.cub     OR     make cabaret && ./cub3D data_cabaret.cub

KEYS:
- use AWSD or ↑ and ↓ to navigate through the maze
- use QE or ← and → to rotate the view



![alt text](rendered_scenes/neon1.png)
Mode: bonus neon

![alt text](rendered_scenes/fire1.png)
Mode: bonus cabaret

More pictures:

![alt text](rendered_scenes/fire2.png)
![alt text](rendered_scenes/ghost1.png)
![alt text](rendered_scenes/neon2.png)


Compile other available MODES:
- Bonus Neon mode:            make bonus && ./cub3D data_neon.cub
- Bonus Cabaret mode:         make cabaret && ./cub3D data_cabaret.cub
- Bonus Ghostbusters mode:    make bonus && ./cub3D data.cub
- Neon mode(mandatory part):  make && ./cub3D data.cub

P.S. tributes to @Kwillum = Enedys 🙌 
