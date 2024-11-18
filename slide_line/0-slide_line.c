#include "slide_line.h"
#include <stddef.h>  /* For size_t */

/* Helper function to slide and merge the array to the left */
static int slide_left(int *line, size_t size)
{
    size_t i = 0, j = 0;

    /* Slide all non-zero elements to the left */
    while (i < size)
    {
        if (line[i] != 0)
        {
            if (i != j)
            {
                line[j] = line[i];  /* Move non-zero element to the left */
                line[i] = 0;        /* Set the previous position to zero */
            }
            j++;
        }
        i++;
    }

    /* Merge adjacent equal elements */
    i = 0;
    while (i < size - 1)
    {
        if (line[i] == line[i + 1] && line[i] != 0)
        {
            line[i] *= 2;        /* Double the value of the first element */
            line[i + 1] = 0;     /* Set the second element to zero */
            i += 2;              /* Skip the next element (merged) */
        }
        else
        {
            i++;
        }
    }

    /* Final slide to the left (fill any gaps created by merges) */
    j = 0;
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (i != j)
            {
                line[j] = line[i];  /* Move non-zero element forward */
                line[i] = 0;        /* Set the previous position to zero */
            }
            j++;
        }
    }

    return (1);
}

/* Helper function to slide and merge the array to the right */
static int slide_right(int *line, size_t size)
{
    size_t i = size - 1, j = size - 1;

    /* Slide all non-zero elements to the right */
    while (i > 0)
    {
        if (line[i] != 0)
        {
            if (i != j)
            {
                line[j] = line[i];  /* Move non-zero element to the right */
                line[i] = 0;        /* Set the previous position to zero */
            }
            j--;
        }
        i--;
    }

    /* Merge adjacent equal elements */
    i = size - 1;
    while (i > 0)
    {
        if (line[i] == line[i - 1] && line[i] != 0)
        {
            line[i] *= 2;        /* Double the value of the first element */
            line[i - 1] = 0;     /* Set the second element to zero */
            i -= 2;              /* Skip the next element (merged) */
        }
        else
        {
            i--;
        }
    }

    /* Final slide to the right (fill any gaps created by merges) */
    j = size - 1;
    for (i = size - 1; i != (size_t)-1; i--)
    {
        if (line[i] != 0)
        {
            if (i != j)
            {
                line[j] = line[i];  /* Move non-zero element backward */
                line[i] = 0;        /* Set the previous position to zero */
            }
            j--;
        }
    }

    return (1);
}

/* The main function to slide and merge the array based on the direction */
int slide_line(int *line, size_t size, int direction)
{
    if (line == NULL || size == 0)
        return (0);  /* Fail if the array is NULL or size is zero */

    /* Validate direction */
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);  /* Fail if direction is invalid */

    /* Perform sliding and merging based on direction */
    if (direction == SLIDE_LEFT)
        return (slide_left(line, size));  /* Slide and merge left */
    else if (direction == SLIDE_RIGHT)
        return (slide_right(line, size)); /* Slide and merge right */

    return (0);  /* Return failure if no valid direction is matched */
}
