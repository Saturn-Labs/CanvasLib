#pragma once
#ifdef CANVAS_LIB
#define LIBRARY __declspec(dllexport)
#else
#define LIBRARY __declspec(dllimport)
#endif
