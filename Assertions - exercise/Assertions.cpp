#include <iostream>
#include <memory>
#include <utility>
#include <math.h>
#include <cassert>
#include <limits>

// Concatenates two strings. str1 and str2 must not be null.
char *concatenate(char *str1, char *str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(strlen(str1) + strlen(str2) + 1 <= UINT_MAX);


	size_t size = strlen(str1) + strlen(str2) + 1;
	char *result = new char[ size ];

	assert(result != NULL);//fail to allocate

	strcpy(result, str1);
	strcat(result, str2);

	return result;
}

typedef std::pair<double, double> Roots;

Roots getQuadraticEquationRoots(double a, double b, double c)
{
	assert((b * b - 4 * a * c) >= 0);
	assert(a != 0);

	double discriminant = b * b - 4 * a * c;

	double discriminantRoot = sqrt(discriminant);

	Roots roots;

	roots.first = (-b + discriminantRoot) / (2 * a);
	roots.second = (-b - discriminantRoot) / (2 * a);

	return roots;
}

int numberAt(int array[], size_t arraySize, unsigned int index)
{
	assert(array != NULL);
	assert(index >= 0);
	assert(index < arraySize);

	return array[ index ];
}

long getLifeTimeInSeconds()
{
	/*
	we whant to check if 60 * 60 <= LONG_MAX
	it means 60 <= LONG_MAX/60
	*/
	static_assert(60 <= LONG_MAX / 60, "houre limit");	
	/*
	we whant to check if 60 * 60 * 24 <= LONG_MAX
	it means 60 * 60 <= LONG_MAX/24
	*/
	static_assert(60 * 60 <= LONG_MAX / 24, "day limit");
	static_assert(60 * 60 * 24 <= LONG_MAX / 365, "year limit");
	static_assert(60 * 60 * 24 * 365 <= LONG_MAX / 120, "life limit");

	return 60 * 60 * 24 * 365 * 120;
}

void main()
{
	std::cout << getLifeTimeInSeconds();
}
