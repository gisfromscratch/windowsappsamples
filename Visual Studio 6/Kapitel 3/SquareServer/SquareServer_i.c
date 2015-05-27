/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.01.75 */
/* at Fri May 22 13:45:59 1998
 */
/* Compiler settings for SquareServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_ISquare = {0x547E8380,0xF175,0x11D1,{0x90,0xA2,0xD0,0xDD,0x2F,0x7A,0xCA,0x49}};


const IID LIBID_SQUARESERVERLib = {0x547E8371,0xF175,0x11D1,{0x90,0xA2,0xD0,0xDD,0x2F,0x7A,0xCA,0x49}};


const CLSID CLSID_Square = {0x547E8381,0xF175,0x11D1,{0x90,0xA2,0xD0,0xDD,0x2F,0x7A,0xCA,0x49}};


#ifdef __cplusplus
}
#endif

