#pragma once
#ifndef _DLLMYMATH_H
#define _DLLMYMATH_H



#ifdef DLLMYMATH_EXPORTS 
#define EXT_CLASS _declspec(dllexport) 
#else
#define EXT_CLASS _declspec(dllimport) 
#endif 








class EXT_CLASS MyMath
{
public:
	int Add(int a,int b);
	int Mul(int a, int b);
	int Sub(int a, int b);

};
#endif _MYMATH_H
