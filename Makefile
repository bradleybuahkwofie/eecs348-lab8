# EECS 348 - Lab 8 Makefile
# Builds both Task 1 and Task 2 programs

CC = gcc
CFLAGS = -Wall -Wextra -O2

all: score temp

# --- Task 1: Football Score Combinations ---
score: score_combinations.c
	$(CC) $(CFLAGS) score_combinations.c -o score_combinations

# --- Task 2: Temperature Conversion ---
temp: Temperature_Conversion.c
	$(CC) $(CFLAGS) temperature_conversion.c -o temperature_conversion

# --- Clean up compiled binaries ---
clean:
	rm -f score_combinations temperature_conversion
