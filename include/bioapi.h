/**
 * \file 
 * This file merges all declarations by \ref iso19784-1.
 * 
 * \mainpage BioAPI 2.0 
 * 
 * -# \ref bioapi_scope
 * -# \ref bioapi_conformance
 * -# \ref bioapi_references
 * -# \ref bioapi_definitions
 * -# \ref bioapi_symbols
 * -# \ref bioapi_architecture
 * -# \ref bioapi_constants.h "BioAPI Constants and Macros"
 * -# \ref bioapi_types.h "BioAPI Data Types"
 * -# BioAPI Service Provider Interface
 * -# Component Registry Interface
 * -# \ref bioapi_errors.h "Error Codes and Error Values"
 */
#ifndef BIOAPI_H
#define BIOAPI_H

 #ifdef __cplusplus
 extern "C" {
 #endif 

#include "bioapi_scope.h"              ///Section  1: "Scope"
#include "bioapi_conformance.h"        ///Section  2: "Conformance"
#include "bioapi_references.h"         ///Section  3: "Normative references"
#include "bioapi_definitions.h"        ///Section  4: "Terms and definitions"
#include "bioapi_symbols.h"            ///Section  5: "Symbols and abbreviated terms"
#include "bioapi_architecture.h"       ///Section  6: "The BioAPI architecture"
#include "bioapi_types.h"              ///Section  7: "BioAPI Types and Macros"
#include "bioapi_functions.h"          ///Section  8: "BioAPI Functions"
#include "bioapi_spi.h"                ///Section  9: "BioAPI Service Provider Interface"
#include "bioapi_componentregistry.h"  ///Section 10: "Component registry interface"
#include "bioapi_errors.h"             ///Section 11: "BioAPI error handling"

#ifdef __cplusplus
 } //extern "C"
 #endif 

#endif //VR_BIOAPI_H
