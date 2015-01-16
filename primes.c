/*
Fast prime number generator
primes.c
2015-01-16
- olehermanse ( http://www.github.com/olehermanse )

World's most lazy license:
This piece of software is completely free and open source.
It is meant for educational purposes and provided "as is"
with no expressed or implied warranty of reliability or 
accuracy. You are free to use, alter, edit, share, perform
or distribute the source code in any way desired for any
purpose, including but not limited to commercial, personal,
entertainment and educational purposes.

Credit is always appreciated.
- olehermanse ( http://www.github.com/olehermanse )
*/


// Includes from standard library:
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Bit manipulation on single variable ( 1-byte char ):
#define bitTest(x,ind) ( (x) & (1<<(ind)) )      // Returns value of bit at ind
#define bitSet(x,ind) x=( (x) | (1<<(ind)) )     // Sets value of bit at ind to 1

// Get value of single bit in bitmap at specific bit index:
char getBit(signed long index, char* bitmap){
	signed long charIndex = index/8;
	int bitIndex = index%8;
	return bitTest(bitmap[charIndex], bitIndex);
}

// Set value of single bit to 1 in bitmap at specific bit index:
void setBit(signed long index, char* bitmap){
	signed long charIndex = index/8;
	int bitIndex = index%8;
	bitSet(bitmap[charIndex], bitIndex);
}

// Generate all prime numbers up to max 
void generatePrimes(signed long max){
	printf("Generating primes in range [0,%li]:\n", max);
	
	// Allocate bitmap of appropriate size
	// The first 2 bits are not used, since 0 and 1 are not prime
	// Up to 7 bits may be extra at the end( have to allocate 8-bit bytes ).
	char* bitmap = 0;
	signed long bitmapSize = max/8 + 1;
	bitmap = (char*)malloc(bitmapSize);
	assert(bitmap);
	memset((void*)bitmap, 0, bitmapSize);
	
	// Loop from 2 to max ( since 0 and 1 are not prime by def. )
	signed long i=0,j=0;
	for(i = 2; i <= max; ++i){
		//Optional, print newline at every 100 for readability
		if(i%100 == 0 && i<max)
			printf("\n");
		// Print all numbers we haven't found factors of already ( Look at bitmap )
		if(getBit(i, bitmap) == 0){
			printf("%li ", i);
			// Set all multiples of a prime to 1 in bitmap ( not prime )
			for(j = 2*i; j<= max; j += i){
				setBit(j, bitmap);
			}
		}
	}
	printf("\n");
	free(bitmap);
	bitmap = 0;
}

// Main function handles command line arguments and user input:
int main(int argc, char** argv){
	signed long max = 0;
	
	// Check if max was provided by command line arguments:
	if(argc >= 2){
		max = strtol(argv[1], (char **)NULL, 10);
	}
	
	// Check if file path was provided by command line arguments:
	if(argc >= 3){
		stdout = fopen(argv[2], "w"); // Standard out becomes file
	}else{
		// Disable buffered output so terminal doesn't freeze while calculating
		setbuf(stdout, NULL);
	}
	
	// User-specified upper limit:
	while(max <= 1){
		printf("Provide upper limit n(>1):");
		scanf("%li", &max);
	}
	
	generatePrimes(max);
	
	
	if(argc >= 3){
		fclose(stdout);
	}
	return 0;
}
