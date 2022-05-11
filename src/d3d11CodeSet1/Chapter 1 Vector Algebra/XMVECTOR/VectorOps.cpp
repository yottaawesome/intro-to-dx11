#include <windows.h> // for FLOAT definition
#include <DirectXMath.h>
#include <iostream>

// Overload the  "<<" operators so that we can use cout to 
// output XMVECTOR objects.
std::ostream& operator<<(std::ostream& os, DirectX::FXMVECTOR v)
{
	DirectX::XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z <<  ", " << dest.w << ")";
	return os;
}
 
int main()
{
	std::cout.setf(std::ios_base::boolalpha);

	// Check support for SSE2 (Pentium4, AMD K8, and above).
	if( !DirectX::XMVerifyCPUSupport() )
	{
		std::cout << "xna math not supported" << std::endl;
		return 0;
	}
	
	DirectX::XMVECTOR p = DirectX::XMVectorSet(2.0f, 2.0f, 1.0f, 0.0f);
	DirectX::XMVECTOR q = DirectX::XMVectorSet(2.0f, -0.5f, 0.5f, 0.1f);
	DirectX::XMVECTOR u = DirectX::XMVectorSet(1.0f, 2.0f, 4.0f, 8.0f);
	DirectX::XMVECTOR v = DirectX::XMVectorSet(-2.0f, 1.0f, -3.0f, 2.5f);
	DirectX::XMVECTOR w = DirectX::XMVectorSet(0.0f, DirectX::XM_PIDIV4, DirectX::XM_PIDIV2, DirectX::XM_PI);

	std::cout << "XMVectorAbs(v)                 = " << DirectX::XMVectorAbs(v) << std::endl;
	std::cout << "XMVectorCos(w)                 = " << DirectX::XMVectorCos(w) << std::endl;
	std::cout << "XMVectorLog(u)                 = " << DirectX::XMVectorLog(u) << std::endl;
	std::cout << "XMVectorExp(p)                 = " << DirectX::XMVectorExp(p) << std::endl;
	
	std::cout << "XMVectorPow(u, p)              = " << DirectX::XMVectorPow(u, p) << std::endl;
	std::cout << "XMVectorSqrt(u)                = " << DirectX::XMVectorSqrt(u) << std::endl;
	
	std::cout << "XMVectorSwizzle(u, 2, 2, 1, 3) = "
		<< DirectX::XMVectorSwizzle(u, 2, 2, 1, 3) << std::endl;
	std::cout << "XMVectorSwizzle(u, 2, 1, 0, 3) = "
		<< DirectX::XMVectorSwizzle(u, 2, 1, 0, 3) << std::endl;

	std::cout << "XMVectorMultiply(u, v)         = " << DirectX::XMVectorMultiply(u, v) << std::endl;
	std::cout << "XMVectorSaturate(q)            = " << DirectX::XMVectorSaturate(q) << std::endl;
	std::cout << "XMVectorMin(p, v               = " << DirectX::XMVectorMin(p, v) << std::endl;
	std::cout << "XMVectorMax(p, v)              = " << DirectX::XMVectorMax(p, v) << std::endl;

	return 0;
}
