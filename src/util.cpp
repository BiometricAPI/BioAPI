#include "common.h"

#include <cstdio>
#include <cstdarg>
#include <cstring>





BioAPI_RETURN BioUtil_Log ( 
    const char* where, const char* format, ... ) 
{
    va_list args;
    va_start( args, format );
    fprintf(stderr, "%s: ", where);
    int ret = vfprintf( stderr, format, args );
    va_end( args );
    
    if (ret < 0)
        return BioAPIERR_FUNCTION_FAILED;
    return BioAPI_OK;
}





uint64_t BioUtil_Timestamp() {
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  
  return now.tv_sec*(uint64_t)1000 + now.tv_nsec/(uint64_t)1000000;
}





BioAPI_RETURN BioUtil_CloneBIR (
    BioAPI_BIR &dest, 
    const BioAPI_BIR &src)
{
    dest.Header = src.Header;
    BioUtil_CloneData(src.BiometricData, dest.BiometricData);
    BioUtil_CloneData(src.SecurityBlock, dest.SecurityBlock);
    return BioAPI_OK;
}





BioAPI_RETURN BioUtil_CloneData (
    BioAPI_DATA &dest, 
    const BioAPI_DATA &src)
{
    if (src.Length==0 || src.Data==NULL) {
        dest.Length=0;
        dest.Data=NULL;
    } else {
        dest.Length=src.Length;
        dest.Data = BioSPI_Malloc(src.Length, "BioAPI_DATA");
        memcpy(dest.Data, src.Data, src.Length);
    }
    return BioAPI_OK;
}
