//
// MATLAB Compiler: 4.14 (R2010b)
// Date: Mon Mar 21 11:44:25 2016
// Arguments: "-B" "macro_default" "-W" "cpplib:libAdd" "-T" "link:lib" "Add.m"
// "Sub.m" 
//

#include <stdio.h>
#define EXPORTING_libAdd 1
#include "libAdd.h"

static HMCRINSTANCE _mcr_inst = NULL;


#if defined( _MSC_VER) || defined(__BORLANDC__) || defined(__WATCOMC__) || defined(__LCC__)
#ifdef __LCC__
#undef EXTERN_C
#endif
#include <windows.h>

static char path_to_dll[_MAX_PATH];

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, void *pv)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        if (GetModuleFileName(hInstance, path_to_dll, _MAX_PATH) == 0)
            return FALSE;
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }
    return TRUE;
}
#endif
#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libAdd_C_API
#define LIB_libAdd_C_API /* No special import/export declaration */
#endif

LIB_libAdd_C_API 
bool MW_CALL_CONV libAddInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
  if (!GetModuleFileName(GetModuleHandle("libAdd"), path_to_dll, _MAX_PATH))
    return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream(path_to_dll, 
                                    85229);
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(   &_mcr_inst,
                                                                error_handler, 
                                                                print_handler,
                                                                ctfStream, 
                                                                85229);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
  return true;
}

LIB_libAdd_C_API 
bool MW_CALL_CONV libAddInitialize(void)
{
  return libAddInitializeWithHandlers(mclDefaultErrorHandler, mclDefaultPrintHandler);
}

LIB_libAdd_C_API 
void MW_CALL_CONV libAddTerminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

LIB_libAdd_C_API 
long MW_CALL_CONV libAddGetMcrID() 
{
  return mclGetID(_mcr_inst);
}

LIB_libAdd_C_API 
void MW_CALL_CONV libAddPrintStackTrace(void) 
{
  char** stackTrace;
  int stackDepth = mclGetStackTrace(&stackTrace);
  int i;
  for(i=0; i<stackDepth; i++)
  {
    mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
    mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
  }
  mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_libAdd_C_API 
bool MW_CALL_CONV mlxAdd(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "Add", nlhs, plhs, nrhs, prhs);
}

LIB_libAdd_C_API 
bool MW_CALL_CONV mlxSub(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "Sub", nlhs, plhs, nrhs, prhs);
}

LIB_libAdd_CPP_API 
void MW_CALL_CONV Add(int nargout, mwArray& C, const mwArray& A, const mwArray& B)
{
  mclcppMlfFeval(_mcr_inst, "Add", nargout, 1, 2, &C, &A, &B);
}

LIB_libAdd_CPP_API 
void MW_CALL_CONV Sub(int nargout, mwArray& C, const mwArray& A, const mwArray& B)
{
  mclcppMlfFeval(_mcr_inst, "Sub", nargout, 1, 2, &C, &A, &B);
}
