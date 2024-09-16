#!/usr/bin/python3
"""
In a text file, there is a single character H.
Only by using Ctrl+a and Ctrl+v,
what is the least amount of commands
necessary to make the text file have n H's?

Proof:

Executing COPY-ALL and PASTE M - 1 times is multiplying
the initial H in the file by M.

Every time we execute COPY-ALL, we increase
the amount of H's in the imaginary clipboard.

This means that after every command we execute,
the amount of H's in the clipboard can either
stay the same as before, or increase,
BUT NEVER DECREASE.

So, this question could be rephrased as:

clipboard = 0
file = 1

while file < N:

    option 0:
        clipboard = file
    option 1:
        file += clipboard

Every prime number N of H's can only be achieved
with 1 COPY-ALL and N - 1 PASTEs, since there's no way
to copy multiple H's and arrive at prime number N without
over/under-shooting, and there's no way to copy multiple H's
at a time without losing the ability to paste just one H.

As a base case, if N is prime, then the amount of
moves it would take to get 1 H to N H's in the file with just
those moves should be N.

If N isn't prime, then N MUST have prime factors.
We can multiply the current amount of H's in the file by these prime factors
one by one, from 1H to N H's.

I don't know if that's the fastest way,

but I assume that the least amount of commands it would
take to fultill the goal is THE SUM OF ALL OF N's PRIME FACTORS.
"""


def minOperations(n):
    """
    Returns the amount of commands (Ctrl+a or Ctrl+v)
    it takes to transform a text file with one H
    to have n H's.

    If the amount of H's 'n' is not possible
    to be achieved (negative or 0 H amounts),
    this function returns 0.

    (NOTE THAT FOR 1 H, THE RESUT IS ALSO 0!)
    """

    if n <= 1:
        return 0

    prime_factor = 1

    while True:
        prime_factor += 1

        if n / prime_factor % 1 == 0:
            return prime_factor + minOperations(n // prime_factor)