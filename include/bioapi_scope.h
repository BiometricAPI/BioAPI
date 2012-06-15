/**
 * \file 
 * This file contains the documentation page \ref bioapi_scope, 
 * corresponding to \ref iso19784-1, section 1, <i>Scope</i>.
 * 
 * No functions or data structures are declared here.
 * 
 * 
 * 
 * 
 * 
 * \page bioapi_scope Scope
 * 
 * This part of ISO/IEC 19784 defines the Application Programming Interface (API) and Service Provider
 * Interface (SPI) for standard interfaces within a biometric system that support the provision of that biometric
 * system using components from multiple vendors It provides interworking between such components through
 * adherence to this part of ISO/IEC 19784 and to other International Standards
 * 
 * The BioAPI specification is applicable to a broad range of biometric technology types It is also applicable to a
 * wide variety of biometrically enabled applications, from personal devices, through network security
 * applications, to large complex identification systems
 * 
 * This part of ISO/IEC 19784 supports an architecture in which a BioAPI Framework supports multiple
 * simultaneous biometric applications (provided by different vendors), using multiple dynamically installed and
 * loaded (or unloaded) biometric service provider (BSP) components and BioAPI Units (provided by other
 * different vendors), possibly using one of an alternative set of BioAPI Function Provider (BFP) components
 * (provided by other vendors) or by direct management of BioAPI Units
 * 
 * \note Where BioAPI Units are provided by a different vendor fom a BSP, a standardised BioAPI Function Provider
 * Interface (FPI) may be needed This is outside the scope of this part of ISO/IEC 19784, but is specified by later parts
 * for the different categories of FPI
 * 
 * This part of ISO/IEC 19784 is not required (and should normally not be referenced) when a complete
 * biometric system is being procured from a single vendor, particularly if the addition or interchange of biometric
 * hardware, services, or applications is not a feature of that biometric system (Such systems are sometimes
 * referred to as "embedded systems") Standardisation of such systems is not in the scope of this part of
 * ISO/IEC 19784
 * 
 * It is not in the scope of this part of ISO/IEC 19784 to define security requirements for biometric applications
 * and biometric service providers
 * 
 * \note ISO 19092 provides guidelines on security aspects of biometric systems [3]
 * 
 * The performance of biometric systems (particularly in relation to searches of a large population to provide the
 * biometric identification capability) is not in the scope of this part of ISO/IEC 19784. Trade-offs between
 * interoperability and performance are not in the scope of this part of ISO/IEC 19784.
 * 
 * This part of ISO/IEC 19784 specifies a version of the BioAPI specification that is defined to have a version
 * number described as Major 2, Minor 0, or version 2.0.
 * 
 * \note Earlier versions of the BioAPI specification were not International Standards.
 */
