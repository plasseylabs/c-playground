#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	int result = 0;

	int tasks1[] = {1, 3};
	int workers1[] = {2};
	int pills1 = 1;
	int strength1 = 1;
	int tasks1_length = sizeof(tasks1) / sizeof(int);
	int workers1_length = sizeof(workers1) / sizeof(int);
	result = maxTaskAssign(tasks1, tasks1_length, workers1, workers1_length,
			       pills1, strength1);
	printf("%d\n", result);
	assert(1 == result);

	int tasks2[] = {10, 15, 30};
	int workers2[] = {0, 10, 10, 10, 10};
	int pills2 = 3;
	int strength2 = 10;
	int tasks2_length = sizeof(tasks2) / sizeof(int);
	int workers2_length = sizeof(workers2) / sizeof(int);
	result = maxTaskAssign(tasks2, tasks2_length, workers2, workers2_length,
			       pills2, strength2);
	printf("%d\n", result);
	assert(2 == result);

	int tasks3[] = {5, 9, 8, 5, 9};
	int workers3[] = {1, 6, 4, 2, 6};
	int pills3 = 1;
	int strength3 = 5;
	int tasks3_length = sizeof(tasks3) / sizeof(int);
	int workers3_length = sizeof(workers3) / sizeof(int);
	result = maxTaskAssign(tasks3, tasks3_length, workers3, workers3_length,
			       pills3, strength3);
	printf("%d\n", result);
	assert(3 == result);

	int tasks4[] = {35};
	int workers4[] = {83, 20, 4, 66};
	int pills4 = 3;
	int strength4 = 41;
	int tasks4_length = sizeof(tasks4) / sizeof(int);
	int workers4_length = sizeof(workers4) / sizeof(int);
	result = maxTaskAssign(tasks4, tasks4_length, workers4, workers4_length,
			       pills4, strength4);
	printf("%d\n", result);
	assert(1 == result);

	int tasks5[] = {
	    1943, 2068, 4077, 7832, 8061, 6939, 6263, 8917, 8008, 5348, 8837,
	    4753, 4607, 7638, 9000, 7222, 4552, 1123, 9225, 6896, 4154, 6303,
	    3186, 2325, 9994, 5855, 8851, 7377, 1930, 1187, 5094, 2689, 8852,
	    1507, 1567, 9575, 1193, 1557, 8840, 9075, 5032, 3642, 6917, 7968,
	    5310, 2315, 7516, 4776, 3091, 7027, 1788, 2007, 2651, 6112, 4264,
	    5644, 3585, 9408, 7410, 9605, 8151, 1538, 6905, 6759, 4518, 3444,
	    5036, 1589, 3902, 3037, 1468, 9179, 3000, 5339, 6805, 7394, 9418,
	    9262, 2888, 4708, 3402, 5554, 8714, 7393, 2848, 5946, 9808, 4301,
	    6675, 8564, 6300, 4359, 9506, 1946, 9673, 7412, 1164, 2986, 2198,
	    5144, 3763, 4782, 8835, 6994, 8035, 3332, 2342, 5243, 3150, 9084,
	    6519, 9798, 7682, 9919, 7473, 7686, 9978, 8092, 9897, 3985, 9874,
	    5842, 9740, 2145, 2426, 7069, 8963, 9250, 4142, 9434, 1895, 6559,
	    3233, 8431, 6278, 6748, 7305, 4359, 2144, 8009, 4890, 6486, 7464,
	    8645, 1704, 5915, 9586, 1394, 7504, 2124, 3150, 2051, 5026, 7612,
	    3715, 5757, 4355, 6394, 3202, 2777, 3949, 2349, 7398, 3029, 3081,
	    5116, 5078, 8048, 9934, 4348, 8518, 5201, 1203, 7935, 5006, 6388,
	    8680, 3427, 6048, 1957, 4026, 4618, 4080};
	int workers5[] = {
	    875,  2347, 939,  3664, 3926, 4555, 1947, 4406, 4601, 3502, 4964,
	    1307, 4232, 2968, 4572, 3139, 2788, 1847, 1208, 2019, 4184, 1664,
	    1747, 3690, 4333, 891,  686,  1959, 2218, 4972, 806,  741,	1490,
	    4529, 2909, 925,  2040, 1234, 1264, 1135, 3640, 1455, 2933, 3699,
	    2856, 3074, 4579, 2458, 2090, 833,	4140, 4534, 2336, 4363, 1948,
	    4546, 4155, 3735, 3577, 2780, 4874, 1747, 4844, 3482, 3053, 3534,
	    549,  4500, 2237, 2128, 1554, 3210, 4161, 2211, 950,  3732, 2182,
	    1148, 4368, 4050, 1452, 1015, 3192, 4318, 3908, 2590, 1103, 2811,
	    2821, 690,	2718, 3360, 2659, 3315, 579,  3108, 2979, 3903, 4367,
	    1906, 4964, 889,  4803, 825,  2270, 4794, 4825, 4485, 4461, 1639,
	    3857, 1330, 3169, 2425, 3694, 1980, 2268, 3002, 2177, 3225, 2499,
	    2517, 1916, 2844, 760,  2167, 1786, 3179, 3222, 1432, 3775, 4747,
	    1764, 690,	3223, 4684, 890,  2701, 1045, 3034, 1381, 1011, 2150,
	    4798, 2247, 1334, 3058, 934,  2895, 1484, 2784, 3341, 4412, 1748,
	    625,  2610, 3488, 4810, 669,  4275, 4929, 1014, 2104, 3111};
	int pills5 = 122;
	int strength5 = 3131;
	int tasks5_length = sizeof(tasks5) / sizeof(int);
	int workers5_length = sizeof(workers5) / sizeof(int);
	result = maxTaskAssign(tasks5, tasks5_length, workers5, workers5_length,
			       pills5, strength5);
	printf("%d\n", result);
	assert(143 == result);
}
