//
// MATLAB Compiler: 4.14 (R2010b)
// Date: Mon Mar 21 11:44:25 2016
// Arguments: "-B" "macro_default" "-W" "cpplib:libAdd" "-T" "link:lib" "Add.m"
// "Sub.m" 
//

#ifndef __libAdd_h
#define __libAdd_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_libAdd
#define PUBLIC_libAdd_C_API __global
#else
#define PUBLIC_libAdd_C_API /* No import statement needed. */
#endif

#define LIB_libAdd_C_API PUBLIC_libAdd_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libAdd
#define PUBLIC_libAdd_C_API __declspec(dllexport)
#else
#define PUBLIC_libAdd_C_API __declspec(dllimport)
#endif

#define LIB_libAdd_C_API PUBLIC_libAdd_C_API


#else

#define LIB_libAdd_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libAdd_C_API 
#define LIB_libAdd_C_API /* No special import/export declaration */
#endif

extern LIB_libAdd_C_API 
bool MW_CALL_CONV libAddInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libAdd_C_API 
bool MW_CALL_CONV libAddInitialize(void);

extern LIB_libAdd_C_API 
void MW_CALL_CONV libAddTerminate(void);



extern LIB_libAdd_C_API 
void MW_CALL_CONV libAddPrintStackTrace(void);

extern LIB_libAdd_C_API 
bool MW_CALL_CONV mlxAdd(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libAdd_C_API 
bool MW_CALL_CONV mlxSub(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libAdd_C_API 
long MW_CALL_CONV libAddGetMcrID();


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_libAdd
#define PUBLIC_libAdd_CPP_API __declspec(dllexport)
#else
#define PUBLIC_libAdd_CPP_API __declspec(dllimport)
#endif

#define LIB_libAdd_CPP_API PUBLIC_libAdd_CPP_API

#else

#if !defined(LIB_libAdd_CPP_API)
#if defined(LIB_libAdd_C_API)
#define LIB_libAdd_CPP_API LIB_libAdd_C_API
#else
#define LIB_libAdd_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_libAdd_CPP_API void MW_CALL_CONV Add(int nargout, mwArray& C, const mwArray& A, const mwArray& B);

extern LIB_libAdd_CPP_API void MW_CALL_CONV Sub(int nargout, mwArray& C, const mwArray& A, const mwArray& B);

#endif
#endif
