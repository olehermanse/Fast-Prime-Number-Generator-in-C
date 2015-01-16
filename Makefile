# See primes.c

default:
	gcc primes.c -Wall -O2 -o primes
	./primes

file:
	gcc primes.c -Wall -O2 -o primes
	# Generate all primes up to 10 Million and save to file
	./primes 10000000 primes.txt
