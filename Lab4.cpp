#include "stdafx.h"
const double eps = 1e-6;
const int N = 4;

struct dot
{
	float x, y;
}A, B, C, D;
dot p[N + 1];
float get_dist(dot p1, dot p2) {
	return (p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x);
}

float get_cos(dot o, dot p1, dot p2) {
	float dop1 = get_dist(o, p1);
	float dop2 = get_dist(o, p2);
	float dp1p2 = get_dist(p1, p2);

	return (dop1 + dop2 - dp1p2) / (2.0 * sqrt(dop1 * dop2));
}
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
	
	if (tABC > 0)
	{/*
		if (tABD > 0 && tBCD > 0 && tCAD > 0)
			cout << "Acoperirea convexa este definita de triunghiul ABC. Multimile sunt {A, B, C} si {D };\n";*/
		if (tABD > 0 && tBCD > 0 && tCAD < 0)
			cout << "Patrulaterul ABCD este convex, cu multimea punctelor in aceasta ordine: A,B,C,D. ;\n";
		if (tABD > 0 && tBCD < 0 && tCAD > 0)
			cout << "Patrulaterul ABCD NU este convex, dar este cu multimea punctelor in aceasta ordine: A,B,D,C. ;\n";
		/*if (tABD > 0 && tBCD < 0 && tCAD < 0)
			cout << "Acoperirea convexa este definita de triunghiul ABD.Multimile sunt {A, B, D} si {C };\n";*/
		if (tABD < 0 && tBCD > 0 && tCAD > 0)
			cout << "Patrulaterul ABCD NU este convex, dar este cu multimea punctelor in aceasta ordine: A,D,B,C. ;\n";
		/*if (tABD < 0 && tBCD > 0 && tCAD < 0)
			cout << "Acoperirea convexa este definita de triunghiul BCD\n.Multimile sunt {B, C, D} si {A };";*/
		/*if (tABD < 0 && tBCD < 0 && tCAD > 0)
			cout << "Acoperirea convexa este definita de triunghiul CAD.Multimile sunt {C, A, D} si {B };\n";
		if (tABD < 0 && tBCD < 0 && tCAD < 0)
			cout << "Caz imposibil";*/
	}
	double cos2 = get_cos(B, A, C);
	double cos4 = get_cos(D, A, C);
	
	if (abs(cos2 + cos4) < eps) {
		cout << "Punctul A4(" << D.x << ", " << D.y << ") este pe cerc!\n";
	}
	else if (cos2 + cos4 < -eps) {
		cout << "Punctul A4(" << D.x << ", " << D.y << ") este in interiorul cercului!\n";
	}
	else {
		cout << "Punctul A4(" << D.x << ", " << D.y << ") este in exteriorul cercului!\n";
	}
	return 0;
}
