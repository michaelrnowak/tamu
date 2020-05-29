/*

    This file contains the declarations for the
    functions we've written to implement the
    quadratic formula solver.

*/

/* ifndef, define, and endif are used to ensure that
this header file is included exactly once in any file
in which #include "03_Functions.h" occurs.  I didn't
explain this in lecture, but will follow up on this
later in the semester.  Anytime you write a
headerfile, place #ifndef NAME_OF_FILE_H before any
code, followed by #define NAME_OF_FILE_H.  Your declarations/code will follow.  At the end of the file
you will write #endif. This is illustrated below. */

// Header file's header
#ifndef FUNCTIONS_H // these names can't begin with numbers, so I omitted 03_
#define FUNCTIONS_H

// Header file's body; your declarations
double solveLinearEquation(double, double);
double calcDiscriminate(double, double, double);
bool areNearlyEqual(double, double, double);
double calculateRealRoot(double, double, double, bool);
double firstPartOfRoot(double, double);
double SecondPartOfRoot(double, double);

// Header file's footer
#endif