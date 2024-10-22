#include "palindrome.h"
#include <stddef.h>
#include <stdio.h>

/**
 * is_palindrome - Converts
 * 'n' into its string form
 * to tell if 'n' is a palindrome or not.
 *
 * Uses 0 manual allocations.
 *
 * @n: number to evaluate
 * Return: 1 if 'n' is a palindrome in base 10,
 * 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	char digits[21] = {0};
	/* the ULONG limit has 20 digits. */
	size_t right_digit_index = 0;
	size_t left_digit_index;

	/*
	 * Convert 'n' into its string form, in 'digits'.
	 * 'digits' first starts as an array of 21 null bytes,
	 * but when 'n' runs out of digits, the remaining null bytes
	 * indicate 'digits's end.
	 *
	 * The digits are being written backwards, but it shouldn't
	 * matter!
	 */
	do {
		digits[right_digit_index] = '0' + n % 10;
		n /= 10;

		right_digit_index++;
	} while (n);

	/*
	 * Compare the digits in 'digits'
	 * from the left and right
	 */
	right_digit_index--; /* move back to last digit */
	left_digit_index = 0;

	while (left_digit_index < right_digit_index)
	{
		if (digits[left_digit_index] != digits[right_digit_index])
			return (0);

		left_digit_index++;
		right_digit_index--;
	}

	return (1);
}
