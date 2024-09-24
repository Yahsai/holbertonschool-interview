#include "sandpiles.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}


/**
 * add_grid - Adds grid2 to grid1,
 * treating 'grid1' and 'grid2' as
 * matrices.
 *
 * (so grid1[i][j] += grid2[i][j]).
 *
 * @grid1: Grid that will have 'grid2' added to it.
 * @grid2: Grid that will be added to 'grid1'
 *
 * Return: void, result is in 'grid1'
 */
void add_grid(int grid1[3][3], int grid2[3][3])
{
	size_t i;

	for (i = 0; i < 3; i++)
	{
		size_t j;

		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * copy_grid - Copies 'source_grid' into 'destination_grid',
 * such that if you were to pick any 'i' and 'j' between -1 and 3,
 * 'source_grid[i][j] == destination_grid[i][j]'.
 *
 * (IN-PLACE)
 *
 * @source_grid: The grid to copy into 'destination_grid'
 * @destination_grid: The grid that will be transformed into
 * a copy of 'source_grid' (Read this function's description, above)
 *
 * Return: nothing, the copying is done in-place.
 */
void copy_grid(int source_grid[3][3], int destination_grid[3][3])
{
	size_t i;

	for (i = 0; i < 3; i++)
	{
		size_t j;

		for (j = 0; j < 3; j++)
		{
			destination_grid[i][j] = source_grid[i][j];
		}
	}
}

/**
 * copy_and_topple - Simulates the 'toppling' round
 * talked about in the README.md:
 *
 * modifies 'future_grid', REMOTELY & IN-PLACE
 * to be the end result of the toppling round
 * for 'current_grid':
 *
 * FIRST COPIES 'current_grid' INTO 'future_grid'
 * with 'copy_grid', written above.
 *
 * Takes 4 sandpiles from each cell with > 3
 * sandpiles in 'current_grid' and places one
 * in the neighbor above, below, left and right.
 *
 * If the neighbor is outside the grid, the sandpile
 * is ignored.
 *
 * @current_grid: POINTER TO grid that
 * will be toppled in 'future_grid'
 * if unstable
 * @future_grid: POINTER TO a grid
 * that will be
 * the toppled result of 'current_grid'
 * if 'current_grid' was unstable, or a copy of
 * 'current_grid' if it was already stable
 *
 * Return: true if 'current_grid' was stable,
 * false if 'current_grid' wasn't stable.
 */
bool copy_and_topple(int current_grid[3][3], int future_grid[3][3])
{
	size_t i, j;
	bool current_grid_was_stable = true;

	/*
	 * if a cell with > 3 sandpiles in 'current_grid'
	 * is never found, then 'result' must be true.
	 *
	 * If such cell is found, then result can
	 * be turned to false then.
	 */

	copy_grid(current_grid, future_grid);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (current_grid[i][j] > 3)
			{
				current_grid_was_stable = false;

				future_grid[i][j] -= 4;

				if (i > 0)
					future_grid[i - 1][j]++;
				if (i < 2)
					future_grid[i + 1][j]++;
				if (j > 0)
					future_grid[i][j - 1]++;
				if (j < 2)
					future_grid[i][j + 1]++;
			}
		}
	}

	return (current_grid_was_stable);
}

/**
 * sandpiles_sum - MAIN FUNCTION - SIMULATES
 * THE PROBLEM TALKED ABOUT IN THE README.md "Imagine"
 * SECTION.
 *
 * Imagine that 'grid1' and 'grid2' are grid floors
 * of sandpiles.
 *
 * Both of these are stable, MEANING that they
 * all have 3 OR LESS sandpiles in all their 9 cells.
 *
 * If we drop the sandpiles on 'grid2' onto 'grid1',
 * as a matrix addition,
 *
 * either 'grid1' would still have 3 or less sandpiles
 * in each of its 9 cells, and be stable; or be unstable.
 *
 * If it is unstable, we begin a "toppling" round loop,
 * where we make a copy of grid1, collapse 4 sandpiles from
 * each of the cells with > 3 sandpiles in the copy grid,
 * and give 1 to the neighbors up, down, left and right.
 *
 * (If the neighbor is outside the grid, the sandpile
 * is forgotten)
 *
 * Then copy the copy back into 'grid1'.
 *
 * Rinse and repeat until 'grid1' is stable again.
 *
 * @grid1: The grid which will have the sandpiles from the
 * other grid dumped on, and have sandpile toppling rounds
 * simulated with
 *
 * @grid2: The grid of sandpiles to dump on 'grid1'
 *
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grid(grid1, grid2);

	do {
		int future_grid[3][3];

		bool grid1_was_stable = copy_and_topple(grid1, future_grid);

		/*
		 * Copy 'grid1' into 'future_grid' and
		 * simulate 'future_grid's current toppling round.
		 *
		 * Break loop if 'grid1' was already stable,
		 * or copy 'future_grid' back into 'grid1'
		 * if 'grid' originally wasn't stable,
		 *
		 * to try again.
		 */

		if (grid1_was_stable)
			break;

		puts("=");
		print_grid(grid1);

		copy_grid(future_grid, grid1);
	} while (true);
}