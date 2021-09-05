You will use this exact Makefile for your Homework 1.
Failure to do so will result in deduction of points.

To compile on terminal type
  make clean
  make all

To delete executables and object file type
  make clean

To run:

./test_points2d

^^In that case you will provide input from standard input.

To run with a given file that is redirected to standard input:

./test_points2d < test_input_file.txt

FUNCTION IMPLEMENTATIONS

0 params constructor: sets size to 0 and sequence_ to nullptr, to easily recognize
unitialized instances

copy-constructor: copys the data from rhs to this by iterating through sequence_

copy-assignment: uses the copy-swap idiom

move-constructor: took some looking around to figure this one out, microsoft
documentation explained how the explicit initializers works

