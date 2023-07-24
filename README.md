# push_swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.
<h1 align="center">
	<p>
		push_swap
	</p>
</h1>
<h2 align="center">
	<p>
			A program to sort a stack using push_swap operations
	</p>
</h2>
<p align="center">
Coded in
	<a href="https://skillicons.dev">
		<img src="https://skillicons.dev/icons?i=c" />
	</a>
</p>

---
## The push_swap operations:
- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss: sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time

## The sorting:
<p>
	For this project I use a own version of the Mergesort alghorithm. I cut the stack into multiple smaller chunks which I then push to stack B after another. I then push the largest element back to A before pushing everything back to A. Before printing out my operations I clean redundant operations (p. e. "rra" and "ra" afterwards).
</p>

---
## Installation and Usage
1. Clone the repository:
```shell
git clone https://github.com/itseugen/push_swap
```
2. Enter the directory and build the library:
```shell
cd push_swap
make
```
Optional: Open the visualiser (not by me, CMake necessary):
```shell
make vis
```
---

<sub><sup>This project is part of my studies at 42 Heilbronn</sup></sub>