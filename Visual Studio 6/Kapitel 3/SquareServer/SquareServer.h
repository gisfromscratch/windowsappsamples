/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Fri May 22 13:45:59 1998
 */
/* Compiler settings for SquareServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __SquareServer_h__
#define __SquareServer_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISquare_FWD_DEFINED__
#define __ISquare_FWD_DEFINED__
typedef interface ISquare ISquare;
#endif 	/* __ISquare_FWD_DEFINED__ */


#ifndef __Square_FWD_DEFINED__
#define __Square_FWD_DEFINED__

#ifdef __cplusplus
typedef class Square Square;
#else
typedef struct Square Square;
#endif /* __cplusplus */

#endif 	/* __Square_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ISquare_INTERFACE_DEFINED__
#define __ISquare_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISquare
 * at Fri May 22 13:45:59 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][uuid][object] */ 



EXTERN_C const IID IID_ISquare;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("547E8380-F175-11D1-90A2-D0DD2F7ACA49")
    ISquare : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSquare( 
            /* [in] */ long value,
            /* [retval][out] */ long __RPC_FAR *pnResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISquareVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISquare __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISquare __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISquare __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSquare )( 
            ISquare __RPC_FAR * This,
            /* [in] */ long value,
            /* [retval][out] */ long __RPC_FAR *pnResult);
        
        END_INTERFACE
    } ISquareVtbl;

    interface ISquare
    {
        CONST_VTBL struct ISquareVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISquare_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISquare_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISquare_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISquare_GetSquare(This,value,pnResult)	\
    (This)->lpVtbl -> GetSquare(This,value,pnResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ISquare_GetSquare_Proxy( 
    ISquare __RPC_FAR * This,
    /* [in] */ long value,
    /* [retval][out] */ long __RPC_FAR *pnResult);


void __RPC_STUB ISquare_GetSquare_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISquare_INTERFACE_DEFINED__ */



#ifndef __SQUARESERVERLib_LIBRARY_DEFINED__
#define __SQUARESERVERLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: SQUARESERVERLib
 * at Fri May 22 13:45:59 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_SQUARESERVERLib;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_Square;

class DECLSPEC_UUID("547E8381-F175-11D1-90A2-D0DD2F7ACA49")
Square;
#endif
#endif /* __SQUARESERVERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
