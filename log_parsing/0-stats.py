#!/usr/bin/python3
import sys
import signal

# Initialize variables
total_file_size = 0
status_codes_count = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}
line_count = 0

def print_stats():
    """Prints the accumulated statistics"""
    print(f"File size: {total_file_size}")
    for code in sorted(status_codes_count.keys()):
        if status_codes_count[code] > 0:
            print(f"{code}: {status_codes_count[code]}")

def signal_handler(sig, frame):
    """Handle keyboard interruption (CTRL + C)"""
    print_stats()
    sys.exit(0)

# Register the signal handler for CTRL + C
signal.signal(signal.SIGINT, signal_handler)

# Read input line by line
for line in sys.stdin:
    line = line.strip()

    # Split the line to match the expected format
    parts = line.split(" ")
    
    if len(parts) >= 7:
        ip, dash, date, request, status_code, file_size = parts[0], parts[1], parts[2], parts[3], parts[-2], parts[-1]

        try:
            # Convert status code and file size to integers
            status_code = int(status_code)
            file_size = int(file_size)

            # Update total file size
            total_file_size += file_size

            # Update the count for valid status codes
            if status_code in status_codes_count:
                status_codes_count[status_code] += 1

        except ValueError:
            # Skip lines with invalid integers
            continue

        # Increment line counter and print stats every 10 lines
        line_count += 1
        if line_count % 10 == 0:
            print_stats()

# If there's a termination not caused by CTRL + C, print the stats at the end
print_stats()
