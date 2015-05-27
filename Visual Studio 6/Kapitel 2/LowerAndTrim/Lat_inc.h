// Lat_inc.h

#ifndef __lat_inc__
#define __lat_inc__

#ifdef __cplusplus
extern "C" {
#endif

#if _USRDLL
void __declspec(dllexport) LowerAndTrim (char *str);
#else
void __declspec(dllimport) LowerAndTrim (char *str);
#endif

#ifdef __cplusplus
}
#endif

#endif
