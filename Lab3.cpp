#include "stdafx.h"
struct punct
{
	int x;
	int y;

	bool operator == (const punct& other)
	{
		if (x != other.x)
			return false;
		return y == other.y;
	}

	bool operator < (const punct & other)
	{
		if (x != other.x)
			return x < other.x;
		return y < other.y;
	}

	bool operator <= (const punct & other)
	{
		if (x != other.x)
			return x <= other.x;
		return y <= other.y;
	}
};

punct min(punct a, punct b)
{
	if (a.x != b.x)
	{
		if (a.x <= b.x)
			return a;
		return b;
	}
	if (a.y <= b.y)
		return a;
	return b;
}

punct max(punct a, punct b)
{
	if (a.x != b.x)
	{
		if (a.x >= b.x)
			return a;
		return b;
	}
	if (a.y >= b.y)
		return a;
	return b;
}

int main()
{
	punct A, B, C, D;
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	cin >> D.x >> D.y;

	int a1 = A.y - B.y;
	int a2 = C.y - D.y;
	int b1 = B.x - A.x;
	int b2 = D.x - C.x;
	int c1 = B.x * A.y - A.x * B.y;
	int c2 = D.x * C.y - C.x * D.y;
	int delta = a1 * b2 - b1 * a2;

	double x = 0, y = 0;

	if (delta != 0)
	{
		x = ((B.x * A.y - A.x * B.y) * b2 - (D.x * C.y - C.x * D.y) * b1) / delta;
		y = ((D.x * C.y - C.x * D.y) * a1 - (B.x * A.y - A.x * B.y) * a2) / delta;
		
		if (x < min(A.x, B.x) || x < min(C.x, D.x))
		{
			cout << "Intersectia este MULTIMEA VIDA \n";
			return 0;
		}
		
		if (x > max(A.x, B.x) || x > max(C.x, D.x))
		{
			cout << "Intersectia este MULTIMEA VIDA\n";
			return 0;
		}
		
		cout << "Segmentele se intersecteaza in punctul (" << x << "," << y << ")\n";
		return 0;
	}

	//2
	if (b1 * c2 - b2 * c1 != 0)
	{
		cout << "Intersectia este MULTIMEA VIDA\n";
		return 0;
	}
	if (a1 * c2 - a2 * c1 != 0)
	{
		cout << "Intersectia este MULTIMEA VIDA\n";
		return 0;
	}

	punct min1 = min(A, B);
	punct min2 = min(C, D);
	punct max1 = max(A, B);
	punct max2 = max(C, D);

	if (min1 == min2 && max1 == max2)
		cout << "Segmentele sunt identice\n";

	if (max2 < min1)
	{
		cout << "Intersectia este MULTIMEA VIDA\n";
		return 0;
	}
	if (max2 == min1)
	{
		cout << "Segmentele se intersecteaza in punctul (" << min1.x << "," << min1.y << ")\n";
		return 0;
	}
	if (min2 < min1)
	{
		cout << "Segmentele se intersectaza in segmentul: (" << min1.x << "," << min1.y << ") , (" << min(max1, max2).x << "," << min(max1, max2).y << ")\n";
		return 0;
	}
	if (min1 == min2 && min2 == min(max1, max2))
	{
		cout << "Segmentele se intersecteaza in punctul (" << min1.x << "," << min1.y << ")\n";
		return 0;
	}
	if (min2 < min(max1, max2))
	{
		cout << "Segmentele se intersectaza in segmentul: (" << min2.x << "," << min2.y << ") , (" << min(max1, max2).x << "," << min(max1, max2).y << ")\n";
		return 0;
	}
	if (min2 == min(max1, max2))
	{
		cout << "Segmentele se intersecteaza in punctul (" << min2.x << "," << min2.y << ")\n";
		return 0;
	}
	cout << "Intersectia este MULTIMEA VIDA\n";
	return 0;
}
