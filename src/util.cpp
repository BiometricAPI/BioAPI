#include "util.h"
#include <cstring>
#include <cstdlib>

void clone (const BioAPI_BIR &src, BioAPI_BIR &dest) 
{
    dest.Header = src.Header;
    clone(src.BiometricData, dest.BiometricData);
    clone(src.SecurityBlock, dest.SecurityBlock);
}



void clone (const BioAPI_DATA &src, BioAPI_DATA &dest)
{
    if (src.Length==0 || src.Data==NULL) {
        dest.Length=0;
        dest.Data=NULL;
    } else {
        dest.Length=src.Length;
        dest.Data = malloc(src.Length);
        memcpy(dest.Data, src.Data, src.Length);
    }
}



void free(BioAPI_BIR *bir) {
    free(bir->BiometricData.Data);
    free(bir->SecurityBlock.Data);
    free(bir);
}
