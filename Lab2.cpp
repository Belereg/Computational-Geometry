#include "stdafx.h"
#if 0
struct dot
{
	float x, y;
}A, B, C, D;

float biggest(float a, float b, float c, float d)
{
	float maxi1, maxi2, maxi;
	if (a > b)
		maxi1 = a;
	else
		maxi1 = b;

	if (c > d)
		maxi2 = c;
	else
		maxi2 = d;

	if (maxi1 > maxi2)
		maxi = maxi1;
	else
		maxi = maxi2;

	return maxi;
}
float lowest(float a, float b, float c, float d)
{
	cout << "----" << a << b << c << d << "----\n";
	float mini1, mini2, mini;
	if (a < b)
		mini1 = a;
	else
		mini1 = b;

	if (c < d)
		mini2 = c;
	else
		mini2 = d;

	if (mini1 < mini2)
		mini = mini1;
	else
		mini = mini2;
	return mini;
}
int main()
{
	cout << "Punctul 1: ";
	cin >> A.x >> A.y;
	cout << "Punctul 2: ";
	cin >> B.x >> B.y;
	cout << "Punctul 3: ";
	cin >> C.x >> C.y;
	cout << "Punctul 4: ";
	cin >> D.x >> D.y;

	float tABC = (A.y - B.y) * C.x + (B.x - A.x) * C.y + (A.x * B.y - B.x * A.y);

	float tABD = (A.y - B.y) * D.x + (B.x - A.x) * D.y + (A.x * B.y - B.x * A.y);
	float tBCD = (B.y - C.y) * D.x + (C.x - B.x) * D.y + (B.x * C.y - C.x * B.y);
	float tCAD = (C.y - A.y) * D.x + (A.x - C.x) * D.y + (C.x * A.y - A.x * C.y);
	//cout << "ABC = " << tABC << "\n" << tABD << ' ' << tBCD << ' ' << tCAD << endl;
	//cout << biggest(A.x, B.x, C.x, D.x) << ' ' << lowest(A.x, B.x, C.x, D.x);
	if (tABC > 0)
	{
		if (tABD > 0 && tBCD > 0 && tCAD > 0)
			cout << "Acoperirea convexa este definita de triunghiul ABC. Multimile sunt {A, B, C} si {D };\n";
		if (tABD > 0 && tBCD > 0 && tCAD < 0)
			cout << "Acoperirea convexa este definita de patrulaterul ABCD.Multimile sunt {A, C} si {B, D};\n";
		if (tABD > 0 && tBCD < 0 && tCAD > 0)
			cout << "Acoperirea convexa este definita de patrulaterul ABDC.Multimile sunt {A, D} si {B, C};\n";
		if (tABD > 0 && tBCD < 0 && tCAD < 0)
			cout << "Acoperirea convexa este definita de triunghiul ABD.Multimile sunt {A, B, D} si {C };\n";
		if (tABD < 0 && tBCD > 0 && tCAD > 0)
			cout << "Acoperirea convexa este definita de patrulaterul ADBC.Multimile sunt {A, B} si {D, C};\n";
		if (tABD < 0 && tBCD > 0 && tCAD < 0)
			cout << "Acoperirea convexa este definita de triunghiul BCD\n.Multimile sunt {B, C, D} si {A };";
		if (tABD < 0 && tBCD < 0 && tCAD > 0)
			cout << "Acoperirea convexa este definita de triunghiul CAD.Multimile sunt {C, A, D} si {B };\n";
		if (tABD < 0 && tBCD < 0 && tCAD < 0)
			cout << "Caz imposibil";
	}
	else
	{
		cout << "Punctele sunt coliniare, pe diagonala.\n";
		char Pb, Pl;
		float x = biggest(A.y, B.y, C.y, D.y);
		float y = lowest(A.y, B.y, C.y, D.y);
		if (x == A.y) Pb = 'A';
		if (x == B.y) Pb = 'B';
		if (x == C.y) Pb = 'C';
		if (x == D.y) Pb = 'D';

		if (y == A.y) Pl = 'A';
		if (y == B.y) Pl = 'B';
		if (y == C.y) Pl = 'C';
		if (y == D.y) Pl = 'D';
		cout << "PPunctele sunt coliniare.Capetele segmentului sunt " << Pl << " si " << Pb << "\n";

	}
	if (tABC == 0 && tABD == 0 && tBCD == 0 && tCAD == 0)
	{
		if (A.x == B.x == C.x == D.x)
		{
			char Pb, Pl;
			float x = biggest(A.y, B.y, C.y, D.y);
			float y = lowest(A.y, B.y, C.y, D.y);
			if (x == A.y) Pb = 'A';
			if (x == B.y) Pb = 'B';
			if (x == C.y) Pb = 'C';
			if (x == D.y) Pb = 'D';

			if (y == A.y) Pl = 'A';
			if (y == B.y) Pl = 'B';
			if (y == C.y) Pl = 'C';
			if (y == D.y) Pl = 'D';
			cout << "PPunctele sunt coliniare.Capetele segmentului sunt " << Pl << " si " << Pb << "\n";
		}
		else if (A.y == B.y == C.y == D.y)
		{
			char Pb, Pl;
			float x = biggest(A.x, B.x, C.x, D.x);
			float y = lowest(A.x, B.x, C.x, D.x);
			if (x == A.x) Pb = 'A';
			if (x == B.x) Pb = 'B';
			if (x == C.x) Pb = 'C';
			if (x == D.x) Pb = 'D';

			if (y == A.x) Pl = 'A';
			if (y == B.x) Pl = 'B';
			if (y == C.x) Pl = 'C';
			if (y == D.x) Pl = 'D';
			cout << "Punctele sunt coliniare.Capetele segmentului sunt " << Pl << " si " << Pb << "\n";
			cout << "I = {" << Pl << "," << Pb << "}";
			cout << "J = { celelalte 2 }";
		}
		
	}
	system("pause");
}
#endif