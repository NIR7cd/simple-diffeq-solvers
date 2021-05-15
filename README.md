#Basic ODE Solvers

This provides a few basic solvers for ordinary differential equations.  The
implementation is based on the algorithms described in Chapter 8 of the 7th
edition of _Elementary Differential Equations and Boundary Value Problems_
by William E. Boyce and Richard C. Diprima.  The purpose of this code is
educational - it is meant to provide a few simple solvers that give a basic
idea of how numerical solutions can be found.  It is not optimized or intended
for any production use case.

#Building

To produce an executable that compares some of the different fixed-step solvers
on an example problem:

```
make test_solvers
```

The resulting the executable optionally takes one argument to specify the step
size to use.

To produce an executable that shows the data produced by a variable-step solver
for an example problem:

```
make test_euler_var
```
