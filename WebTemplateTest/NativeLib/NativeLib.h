#ifndef _NATIVELIB_H_
#define _NATIVELIB_H_

#ifndef MYAPI
  #define MYAPI 
#endif

#ifdef __cplusplus
extern "C" {
#endif

MYAPI char* HuffmanEncode(const char* text);
MYAPI char* HuffmanDecode(const char* text, const char* plainText);
MYAPI char* HuffmanShowTable(const char* text);
MYAPI char* ShannonFanoEncode(const char* text);
MYAPI char* ShannonFanoDecode(const char* text, const char* plainText);
MYAPI char* ShannonFanoShowTable(const char* text);

#ifdef __cplusplus
}
#endif

#endif // _NATIVELIB_H_
