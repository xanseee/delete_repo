#pragma once

#ifdef _EXPORTING
#define MATH_API __declspec(dllexport)
#elif _IMPORTING
#define MATH_API __declspec(dllimport)
#else
#define MATH_API
#endif

MATH_API int max(int x, int y);
MATH_API int factorial(int n);
MATH_API int sum(int x, int y);
MATH_API int randInt(int min, int max);
