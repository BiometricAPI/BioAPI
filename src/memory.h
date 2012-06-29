#pragma once

#include "common.h"

BioAPI_EXPORT void*         BioAPI BioSPI_Malloc  (
    int Lenght, 
    const char* PtrName);

BioAPI_EXPORT BioAPI_RETURN BioAPI BioSPI_Free (
    void* Ptr);

BioAPI_EXPORT BioAPI_RETURN BioAPI BioSPI_DebugMemory ();

BioAPI_EXPORT BioAPI_RETURN BioAPI BioSPI_FreeBIR (BioAPI_BIR *bir);
