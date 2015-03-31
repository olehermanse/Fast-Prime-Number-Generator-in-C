**File:** README.md<br>
**Project name:** Fast Prime Number Generator in C<br>
**Date:** 2015-04-01<br>
**Author:** olehermanse ( http://www.github.com/olehermanse )<br>
**License:** The MIT License<br>

**The MIT License (MIT)**

Copyright (c) 2015 olehermanse<br>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:<br>

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.<br>

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.<br>
<br>


**Fast Prime Number Generator in C**<br>
( http://github.com/olehermanse/Fast-Prime-Number-Generator-in-C )

- An easy to understand and efficient prime number generator in C.<br>
- Uses the Sieve of Eratosthenes algorithm. <br>
- Uses single bit manipulation and a bitmap with 8 boolean values per byte to save memory. <br>
- Writes output to terminal or file. <br>
( Relatively fast for generating all primes up to an integer n, 
not for generating a single prime or the nth prime )<br>
( There are faster, more complicated algorithms than this one,
see http://en.wikipedia.org/wiki/Sieve_of_Atkin )<br>
