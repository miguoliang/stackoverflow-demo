# stackoverflow-demo
Demo code for questions on StackOverflow

##Build

```
    make
```

##Usage

```
    bin/main <left_matrix_filename> <right_matrix_filename>
```

##Test Data

You could construct your own matrix definination file in the same format with `res/matrix`
The following conditions should be followed in the matrix definition file:
1. Comma-separated
1. Only digit is accepted
1. No blank lines appears
1. No comma trails at the end of line

More about [Multiplication of two matrices](https://en.wikipedia.org/wiki/Matrix_(mathematics)#Matrix_multiplication) here!

##Demo

```
    bin/main res/matrix res/matrix
```

Result

```
Reading file: res/matrix
=====
1,2,3,4
5,6,7,8
9,0,1,2
3,4,5,6

Reading file: res/matrix
=====
1,2,3,4
5,6,7,8
9,0,1,2
3,4,5,6

Left matrix:
=====
1,2,3,4
5,6,7,8
9,0,1,2
3,4,5,6

Right matrix:
=====
1,2,3,4
5,6,7,8
9,0,1,2
3,4,5,6

Calculate steps
=====
M(0,0) = L(0,0) + R(0,0) + L(0,1) + R(1,0) + L(0,2) + R(2,0) + L(0,3) + R(3,0)
M(0,1) = L(0,0) + R(0,1) + L(0,1) + R(1,1) + L(0,2) + R(2,1) + L(0,3) + R(3,1)
M(0,2) = L(0,0) + R(0,2) + L(0,1) + R(1,2) + L(0,2) + R(2,2) + L(0,3) + R(3,2)
M(0,3) = L(0,0) + R(0,3) + L(0,1) + R(1,3) + L(0,2) + R(2,3) + L(0,3) + R(3,3)
M(1,0) = L(1,0) + R(0,0) + L(1,1) + R(1,0) + L(1,2) + R(2,0) + L(1,3) + R(3,0)
M(1,1) = L(1,0) + R(0,1) + L(1,1) + R(1,1) + L(1,2) + R(2,1) + L(1,3) + R(3,1)
M(1,2) = L(1,0) + R(0,2) + L(1,1) + R(1,2) + L(1,2) + R(2,2) + L(1,3) + R(3,2)
M(1,3) = L(1,0) + R(0,3) + L(1,1) + R(1,3) + L(1,2) + R(2,3) + L(1,3) + R(3,3)
M(2,0) = L(2,0) + R(0,0) + L(2,1) + R(1,0) + L(2,2) + R(2,0) + L(2,3) + R(3,0)
M(2,1) = L(2,0) + R(0,1) + L(2,1) + R(1,1) + L(2,2) + R(2,1) + L(2,3) + R(3,1)
M(2,2) = L(2,0) + R(0,2) + L(2,1) + R(1,2) + L(2,2) + R(2,2) + L(2,3) + R(3,2)
M(2,3) = L(2,0) + R(0,3) + L(2,1) + R(1,3) + L(2,2) + R(2,3) + L(2,3) + R(3,3)
M(3,0) = L(3,0) + R(0,0) + L(3,1) + R(1,0) + L(3,2) + R(2,0) + L(3,3) + R(3,0)
M(3,1) = L(3,0) + R(0,1) + L(3,1) + R(1,1) + L(3,2) + R(2,1) + L(3,3) + R(3,1)
M(3,2) = L(3,0) + R(0,2) + L(3,1) + R(1,2) + L(3,2) + R(2,2) + L(3,3) + R(3,2)
M(3,3) = L(3,0) + R(0,3) + L(3,1) + R(1,3) + L(3,2) + R(2,3) + L(3,3) + R(3,3)

Result matrix:
=====
50,30,40,50
122,78,104,130
24,26,38,50
86,54,72,90
```