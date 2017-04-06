#ifndef SortCompare_h
#define SortCompare_h

#include <iostream>

using namespace std;

public static double time(String alg, Comparable[] a)
{
	Stopwatch timer = new Stopwatch();
	if (alg=="Insertion") Insertion.sort(a);
	if (alg=="Selection") Selection.sort(a);
	if (alg=="Shell") Shell.sort(a);
	if (alg=="Merge") Merge.sort(a);
	if (alg=="Quick") Quick.sort(a);
	if (alg=="Heap") Heap.sort(a);
	return timer.elapsedTime();
}

#endif
