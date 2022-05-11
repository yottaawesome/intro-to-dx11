// This define is required for support of the CXMMATRIX()(float, float) operator used in this sample.
// Without it, the operator is not defined, and there does not appear to be an efficient replacement
// for client code. See https://stackoverflow.com/questions/17475929/access-floats-of-xmmatrix-operator-not-working
#define _XM_NO_INTRINSICS_
#include <windows.h> // for FLOAT definition
#include <directxmath.h>
#include <iostream>
using namespace std;

// Overload the  "<<" operators so that we can use cout to 
// output XMVECTOR and XMMATRIX objects.
ostream& operator<<(ostream& os, DirectX::FXMVECTOR v)
{
	DirectX::XMFLOAT4 dest;
	DirectX::XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";
	return os;
}

ostream& operator<<(ostream& os, DirectX::CXMMATRIX m)
{
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
			os << m(i, j) << "\t";
		os << endl;
	}
	return os;
}

int main()
{
	// Check support for SSE2 (Pentium4, AMD K8, and above).
	if( !DirectX::XMVerifyCPUSupport() )
	{
		cout << "xna math not supported" << endl;
		return 0;
	}

	DirectX::XMMATRIX A(1.0f, 0.0f, 0.0f, 0.0f,
               0.0f, 2.0f, 0.0f, 0.0f,
			   0.0f, 0.0f, 4.0f, 0.0f,
			   1.0f, 2.0f, 3.0f, 1.0f);

	DirectX::XMMATRIX B = DirectX::XMMatrixIdentity();

	DirectX::XMMATRIX C = A * B;

	DirectX::XMMATRIX D = XMMatrixTranspose(A);

	DirectX::XMVECTOR det = XMMatrixDeterminant(A);
	DirectX::XMMATRIX E = XMMatrixInverse(&det, A);

	DirectX::XMMATRIX F = A * E;
 
	cout << "A = "                    << endl << A << endl;
	cout << "B = "                    << endl << B << endl;
	cout << "C = A*B = "              << endl << C << endl;
	cout << "D = transpose(A) = "     << endl << D << endl;
	cout << "det = determinant(A) = " << det << endl << endl;
	cout << "E = inverse(A) = "       << endl << E << endl;
	cout << "F = A*E = "              << endl << F << endl;
 
	return 0;
}