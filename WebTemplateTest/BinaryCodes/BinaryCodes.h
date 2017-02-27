#ifndef _BINARY_CODES_
#define _BINARY_CODES_

#ifndef MYCODEAPI
	#define MYCODEAPI 
#endif

#ifdef __cplusplus
extern "C" {
#endif

	__declspec(dllexport) char* LinearCode(int m, int n, int * matrix);
	__declspec(dllexport) char* SystemFormCheckMatrix(int m, int n, int * matrix);
	__declspec(dllexport) char* SyndromeDecode(long int n, long int k, long int d, long int y, int * h);
	__declspec(dllexport) char* HammingDecode(long int r, int y);
	__declspec(dllexport) char* MeggetDecode(int n, int data, int y);
	__declspec(dllexport) char* ReedMullerCoding(int r, int m, int y, int yLength);
	__declspec(dllexport) char* ReedMullerDecode(int r, int m, int y, int yLength);

#ifdef __cplusplus
}
#endif

#endif // _BINARY_CODES_