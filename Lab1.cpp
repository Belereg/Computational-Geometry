
#include "stdafx.h"
#if 0
struct dot
{
	float x, y, z;
}A, B, C;

int main()
{
	cout << "Punctul 1: ";
	//citim cele 3 puncte
	cin >> A.x >> A.y >> A.z;
	cout << "Punctul 2: ";

	cin >> B.x >> B.y >> B.z;
	cout << "Punctul 3: ";
	cin >> C.x >> C.y >> C.z;
	float a;
	int ok = 0;
	if (A.x == B.x && A.y == B.y && A.z == B.z)
	{
		cout << "Punctele A, B, C sunt coliniare\n" << endl;
		cout << "--> A = 1B + 0C";
		ok = 1;
	}
	if (B.x - A.x != 0)
	{
		a = (C.x - A.x) / (B.x - A.x);
		if (C.y - A.y == a * (B.y - A.y) && C.z - A.z == a * (B.z - A.z))
		{
			cout << "Punctele A, B, C sunt coliniare\n" << endl;
			cout << "--> C = " << 1 - a << "A + " << a << " B";
			ok = 1;
		}
	}
	if (B.y - A.y != 0)
	{
		a = (C.y - A.y) / (B.y - A.y);
		if (C.x - A.x == a * (B.x - A.x) && C.z - A.z == a * (B.z - A.z))
		{
			cout << "Punctele A, B, C sunt coliniare\n" << endl;
			cout << "--> C = " << 1 - a << "A + " << a << " B";
			ok = 1;
		}
	}
	if (B.z - A.z != 0)
	{
		a = (C.z - A.z) / (B.z - A.z);
		if (C.y - A.y == a * (B.y - A.y) && C.x - A.x == a * (B.x - A.x))
		{
			cout << "Punctele A, B, C sunt coliniare\n" << endl;
			cout << "--> C = " << 1 - a << "A + " << a << " B";
			ok = 1;
		}
	}
	if (ok == 0)
		cout << "Punctele A, B, C NU sunt coliniare\n";
	system("pause");
}

#endif