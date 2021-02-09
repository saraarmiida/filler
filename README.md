# filler
An algorithms project from the 42 curriculum. In filler you create a player, whose goal is to put more pieces to a board than your enemy does.

## Algorithm
To solve where my player puts the piece given by the filler_vm virtual machine, I create a heatmap. In the heatmap the free spots closest to the enemys
pieces get the highest value. The value of a free spot is decreased the further it is from an enemy piece. In the end, I choose the spot that gets the
highest heat value to be the final spot, where i place the piece.

## Visualiser
I made a simple visualiser with minilibx. The visualiset is not perfect, as it's not very reliable and has some memory leaks, but it made noticing how 
the players work and optimizing my algoritm a lot easier. I'm planning on improving the visualiser in the future, but since it wasn't mandatory for the
project, I decided to leave it for now.

## Usage
```
git clone https://github.com/saraarmiida/filler.git
cd filler
./filler_vm -f maps/map01 -p1 ./spentti.filler -p2 players/superjeannot.filler
```
## Demo

![](filler_map1_demo.gif)
