/**
 * \file 
 * This file contains the documentation page \ref bioapi_conformance, corresponding to 
 * \ref iso19784-1, section 2, <i>Conformance</i> and to \ref iso19784-1, Annex A, <i>Conformance</i> .
 * 
 * No functions or data structures are declared here.
 * 
 * 
 * 
 * 
 * 
 * \page bioapi_conformance Conformance
 * 
 * \note \ref iso19784-1 uses the C programming language (see \ref iso9899-1999) to specify the
 * interfaces that it defines. A \ref bioapi_definition_biopi_component can conform to \ref iso19784-1 
 * by the provision or use of that interface with languages other than the C programming language, 
 * provided that the component on the other side of such an interface can use the interface through 
 * the detailed C programming language specification given on \ref bioapi.h.
 * 
 * 
 * 
 * 
 * 
 * Conformance to \ref iso19784-1 falls into the following 3 classes:
 * - \ref bioapi_conformant_application
 * - \ref bioapi_conformant_framework
 * - \ref bioapi_conformant_bsp, comprising one of the following sub-classes:
 *   - \ref bioapi_conformant_verification_bsp
 *   - \ref bioapi_conformant_identification_bsp
 *   - \ref bioapi_conformant_capture_bsp
 *   - \ref bioapi_conformant_verification_engine
 *   - \ref bioapi_conformant_identification_engine
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_conformant_application BioAPI Conformant Biometric Application
 * To claim compliance to the BioAPI specification, a biometric application shall, for each BioAPI
 * function call utilized, invoke that operation consistently with this specification. That is, all 
 * input parameters shall be present and valid. The application shall accept all valid output
 * parameters and return values.
 * 
 * There is no minimum set of functions that are required to be called. However, the biometric
 * application shall conform to the call dependencies identified for the functions.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_conformant_framework BioAPI Conformant Framework
 * The BioAPI Framework component is the middleware infrastructure between 
 * \ref bioapi_conformant_application%s and \ref bioapi_definition_bsp "BSP"s. 
 * It serves the following general purposes:
 * - \ref bioapi_definition_bsp loading/attaching
 * - \ref bioapi_definition_bsp and \ref bioapi_definition_bfp management
 * - Component registry maintenance and management
 * - Function call pass-through (\ref bioapi_symbol_api "API"-\ref bioapi_symbol_spi "SPI" translation)
 * - Handling of event notifications from \ref bioapi_definition_bsp "BSP"s, 
 *   and sending those event notifications to (possibly multiple) event handlers 
 *   in applications that have loaded that \ref bioapi_definition_bsp "BSP".
 * - Supporting \ref bioapi_symbol_api calls related to the installation or de-installation of 
 *   \ref bioapi_definition_biopi_component%s, with appropriate update of the \ref bioapi_definition_component_registry.
 * - Supporting queries from a \ref bioapi_definition_bsp "BSP" about installed \ref bioapi_definition_bfp "BFP"s
 * 
 * To claim conformance to the BioAPI specification, a BioAPI Framework shall:
 * - Provide component management functions as specified in clause 8.1.
 * - Provide component registry services in accordance with clause 10.
 * - Perform translation of API functions specified in clause 8 into the corresponding SPI functions
specified in clause 9.
 * - Conform to the data structures as defined in \ref bioapi.h and the error codes as defined in clause 11.
 * - Handle event notifications and callbacks as defined in clauses 7.28, 8.3, and 9.2.
 * 
 * A \ref bioapi_conformant_framework is required to support ALL options identified in this standard, since
 * it will provide services to applications and \ref bioapi_definition_bsp "BSP"s that may implement any 
 * of those options. No subsets of conformant Framework functions are defined.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_conformant_bsp BioAPI Conformant BSPs
 * To claim conformance to the BioAPI specification, BSPs shall implement mandatory functions for their 
 * conformance sub-class, as defined below, in accordance with the SPI defined in clause 9. BSPs claim
 * conformance to one of the conformance sub-classes specified in clause A.1.1.
 * 
 * BSPs shall accept all valid input parameters and return valid outputs. Optional capabilities and returns are not
 * required to claim conformance; but any optional functions or parameters that are implemented shall be
 * implemented in accordance with the specification requirements. Additional parameters shall not be required.
 * 
 * The BSP installation process shall perform the population of all required component registry entries.
 * 
 * BSPs shall possess a valid and unique UUID that is associated with a specific BSP product and version.
 * 
 * \note The UUID may be self-generated (see \ref iso9834-8) and should (but need not) be the same on 
 * multiple systems where the same BSP product/version is installed.
 * 
 * BIRs generated by the BSP shall conform to the data structures defined in clause 7 (they shall be BioAPI
 * BIRs). BSPs shall only return BioAPI_BIR data containing a registered FormatOwner with an associated valid
 * FormatType (see clause 7.6 and Annex B).
 * 
 * BSPs shall perform error handling as defined in clause 11.
 * 
 * All BSPs shall support basic Component Management (clause 9.3.1), Handle (clause 9.3.2), Event (9.3.3.1)
 * and Utility (clause 9.3.7) operations. Callback (clause 9.3.3.2), Database (clause 9.3.5), and BioAPI Unit
 * (clause 9.3.6) operations are optional.
 * 
 * The following table is a summary of BSP conformance requirements by subclass of BSP. Details are provided
 * in the following sub-clauses. Clause A.4.6 addressed conformance with respect to optional capabilities.
 * 
 * <table>
 *   <tr><th>Function</th>
 *     <th width="15%">\ref bioapi_conformant_verification_bsp "Verification BSP"</th>
 *     <th width="15%">\ref bioapi_conformant_identification_bsp "Identification BSP"</th>
 *     <th width="15%">\ref bioapi_conformant_capture_bsp "Capture BSP"</th>
 *     <th width="15%">\ref bioapi_conformant_verification_engine "Verification Engine"</th>
 *     <th width="15%">\ref bioapi_conformant_identification_engine "Identification Engine"</th>
 *   </tr>
 *   <tr><th colspan="6">Component Management Functions</th></tr>
 *   <tr><th>\ref BioSPI_BSPLoad</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_BSPUnload</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_BSPAttach</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_BSPDetach</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_QueryUnits</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_QueryBFPs</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_ControlUnit</th><td></td><td></td><td></td><td></td><td></td></tr>
 * 
 *   <tr><th colspan="6">Handle Functions</th></tr>
 *   <tr><th>\ref BioSPI_FreeBIRHandle</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_GetBIRFromHandle</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_GetHeaderFromHandle</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 * 
 *   <tr><th colspan="6">Callback and Event Functions</th></tr>
 *   <tr><th>\ref BioSPI_EnableEvents</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_SetGUICallbacks</th><td></td><td></td><td></td><td></td><td></td></tr>
 * 
 *   <tr><th colspan="6">Biometric Functions</th></tr>
 *   <tr><th>\ref BioSPI_Capture</th><td></td><td></td><td><b>✓</b></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_CreateTemplate</th><td></td><td></td><td></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_Process</th><td></td><td></td><td></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_ProcessWithAuxBIR</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_VerifyMatch</th><td></td><td></td><td></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_IdentifyMatch</th><td></td><td></td><td></td><td></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_Enroll</th><td><b>✓</b></td><td><b>✓</b></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_Verify</th><td><b>✓</b></td><td><b>✓</b></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_Identify</th><td></td><td><b>✓</b></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_Import</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_PresetIdentifyPopulation</th><td></td><td></td><td></td><td></td><td></td></tr>
 * 
 *   <tr><th colspan="6">Database Functions</th></tr>
 *   <tr><th>\ref BioSPI_DbOpen</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_DbClose</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_DbCreate</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_DbDelete</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_DbSetMarker</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_DbFreeMarker</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_DbStoreBIR</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_DbGetBIR</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_DbGetNextBIR</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_DbDeleteBIR</th><td></td><td></td><td></td><td></td><td></td></tr>
 * 
 *   <tr><th colspan="6">BioAPI Unit Functions</th></tr>
 *   <tr><th>\ref BioSPI_SetPowerMode</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_SetIndicatorStatus</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_GetIndicatorStatus</th><td></td><td></td><td></td><td></td><td></td></tr>
 *   <tr><th>\ref BioSPI_CalibrateSensor</th><td></td><td></td><td></td><td></td><td></td></tr>
 * 
 *   <tr><th colspan="6">Utility Functions</th></tr>
 *   <tr><th>\ref BioSPI_Cancel</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 *   <tr><th>\ref BioSPI_Free</th><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td><td><b>✓</b></td></tr>
 * </table>
 * 
 * 
 * \subsection bioapi_conformant_verification_bsp BioAPI Conformant Verification BSPs
 * \subsection bioapi_conformant_identification_bsp BioAPI Conformant Identification BSPs
 * \subsection bioapi_conformant_capture_bsp BioAPI Conformant Capture BSPs
 * \subsection bioapi_conformant_verification_engine BioAPI Conformant Verification Engines
 * \subsection bioapi_conformant_identification_engine BioAPI Conformant Identification Engines
 * \section bioapi_conformant_optional Optional Capabilities
 * \subsection bioapi_conformant_optional_functions Optional Functions
 * \subsection bioapi_conformant_optional_subfunctions Optional Subfunctions
 */
