# Push_Swap
Second Algo Project @42 Paris.

**Project score : [111 / 100]**

Push-Swap is an algorithmic sorting project which consists of sorting an unordered list of numbers using only two stacks, A and B, while only using the following limited actions:

 - sa : swap a - inverts the two first elements at the top of stack A.
 - sb : swap b - interts the two first elements at the top of stack B.
 - ss : sa & sb at the same time.
 - pa : push a - puts the first element of stack B on top of stack A.
 - pb : push a - puts the first element of stack A on top of stack B.
 - ra : rotate a - move up all elements of stack A. The first element becomes the last.
 - rb : rotate a - move up all elements of stack B. The first element becomes the last.
 - rr : ra & rb at the same time.
 - rra : reverse rotate a - move down all elements of stack A. The last element becomes the first.
 - rrb : reverse rotate a - move down all elements of stack B. The last element becomes the first.
 - rrr : rra & rrb at the same time.
 
There are two parts to this project:
- checker: a program that receives actions, separated by a newline, which will check if the list is ordered after executing the given actions.
- push_swap: a program that returns as little actions as possible, which will sort a given unordered list.

The goal of this project was to understand an algorithm's complexity, quantified by the numbers of actions required to sort a given list of intergers.

## Installation and usage

```
git clone https://github.com/andrewrzepecki/fillit && cd fillit && make
```

The program recieves a file containing valid tetriminos in this format:

![fillit](png/tetris_pieces.png)

Tetriminos pieces must be 4x4 format, using '#' and '.' to form the piece, and must be seperated by a newline.

**Example:**

```
./fillit [tetris_pieces]
```

![fillit](png/fillit_output.png)

The tetriminos pieces are distinguished with their own unique character: 'A' for the first tetriminos supplied, 'B' for the second, 'C' for the third ...

The concept of our algorithm is to recursively test each tetriminos, starting in an area the size of the sum of the given tetriminos areas.


