/**
 * \file 
 * This file contains the documentation page \ref bioapi_definitions, 
 * corresponding to \ref iso19784-1, section 4, <i>Terms and definitions</i>.
 * 
 * No functions or data structures are declared here.
 * 
 * 
 * 
 * 
 * 
 * \page bioapi_definitions Terms and definitions
 * For the purposes of this document, the following terms and definitions apply.
 * \note Function names and data element names are not included here, but are defined within this document.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_template_adaptation Template Adaptation
 * Use of a \ref bioapi_definition_bir produced from a newly captured and verified \ref bioapi_definition_biometric_sample 
 * to automatically update or refresh a \ref bioapi_definition_reference_template.
 * \note This procedure is used to minimize the effects of template aging.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_attach_session Attach Session
 * Temporary association between an application, a single \ref bioapi_definition_bsp, and a set of \ref bioapi_definition_unit%s that are managed 
 * either directly or indirectly by that \ref bioapi_definition_bsp.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_biopi_component BioAPI Component
 * Component of the BioAPI architecture with a defined interface that can be supplied by a separate vendor and 
 * which is subject to conformance testing.
 * \note BioAPI components include BioAPI applications, BioAPI Frameworks, \ref bioapi_definition_bsp%s, and \ref bioapi_definition_bfp%s.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_bfp BioAPI Function Provider (BFP)
 * Component that manages one or more \ref bioapi_definition_unit%s of a specific category.
 * \note Interfaces to \ref bioapi_definition_bfp%s are standardized in subsequent parts of ISO/IEC 19784.
 * \note \ref bioapi_definition_bfp%s are categorized according to the categories of \ref bioapi_definition_unit%s that they manage (see clause 6.2.4).
 *
 * 
 * 
 * 
 * 
 * \section bioapi_definition_unit BioAPI Unit
 * Abstraction of a hardware or software resource that is directly managed by a \ref bioapi_definition_bsp or \ref bioapi_definition_bfp.
 * \note \ref bioapi_definition_unit%s are categorized (see clause 6.2.2) and include sensor units, archive units, matching algorithm 
 * units and processing algorithm units.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_biometric Biometric
 * (adj.) Pertaining to the field of \ref bioapi_definition_biometrics.
 *
 * 
 * 
 * 
 * 
 * \section bioapi_definition_bdb Biometric Data Block (BDB)
 * Block of data with a defined format that contains one or more biometric samples or biometric templates.
 * \note ISO/IEC 19784 does not support BDB formats that are not an integral multiple of eight bits.
 * \note There is no requirement that a BDB format be self-delimiting.
 * \note Each part of ISO/IEC 19794 standardises one or more BDB formats. Vendor specific formats can also be
 * specified and identified.
 * \note Within BioAPI, the BDB is “opaque” to the application and is therefore sometimes referred to as an Opaque
 * Biometric Data Block.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_bir Biometric Information Record (BIR)
 * Data structure containing one or more BDBs, together with information identifying the BDB formats, and
 * possibly further information such as whether a BDB is signed or encrypted (see ISO/IEC 19785-1).
 * \note This part of ISO/IEC 19784 defines a BIR format (see clause 7.4) that supports only a single BDB.
 * ISO/IEC 19785-1 defines a more general BIR format that supports multiple BDBs within the BIR, and the above
 * definition is used in common by the two International Standards. When the term BIR is used in this part of
 * ISO/IEC 19784, it normally refers to the specific BIR format defined by BioAPI (see Annex B), not to an arbitrary BIR.
 * The term BioAPI BIR is used where clarity is needed.
 * 
 * \subsection bioapi_definition_reference_bir Reference BIR
 * \ref bioapi_definition_bir whose \ref bioapi_definition_bdb "Biometric Data Block"(s) contain one or more \ref bioapi_definition_biometric_template%s.
 * 
 * \subsection bioapi_definition_sample_bir Sample BIR
 * \ref bioapi_definition_bir whose \ref bioapi_definition_bdb "Biometric Data Block"(s) contain only \ref bioapi_definition_biometric_sample%s 
 * that are not \ref bioapi_definition_biometric_template%s.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_biometric_sample Biometric Sample
 * Information obtained from a \ref bioapi_definition_biometric_sensor, either directly or after further processing.
 * \note: See also \ref bioapi_definition_raw_biometric_sample, \ref bioapi_definition_intermediate_biometric_sample, and \ref bioapi_definition_processed_biometric_sample.
 * 
 * \subsection bioapi_definition_raw_biometric_sample Raw Biometric Sample
 * \ref bioapi_definition_biometric_sample obtained directly from a \ref bioapi_definition_biometric_sensor.
 * \note The formats for \ref bioapi_definition_raw_biometric_sample%s are not currently standardised, and depend on the 
 * nature of the \ref bioapi_definition_biometric_sensor and the vendor of that device. They may in the future be standardised 
 * as part of the standardisation of specific \ref bioapi_definition_biometric_sensor%s.
 *
 * \subsection bioapi_definition_intermediate_biometric_sample Intermediate Biometric Sample
 * \ref bioapi_definition_biometric_sample obtained by processing a \ref bioapi_definition_raw_biometric_sample, intended for further processing.
 * 
 * \subsection bioapi_definition_processed_biometric_sample Processed Biometric Sample
 * \ref bioapi_definition_biometric_sample suitable for comparison.
 * 
 * \subsection bioapi_definition_biometric_template Biometric Template
 * \ref bioapi_definition_biometric_sample or combination of \ref bioapi_definition_biometric_sample%s that is suitable for storage
 * as a reference for future comparison.
 * 
 * \subsection bioapi_definition_reference_template Reference Template
 * \ref bioapi_definition_biometric_template that has been stored.
 * 
 * 
 * 
 *
 * 
 * \section bioapi_definition_biometric_sensor Biometric Sensor
 * \ref bioapi_definition_biometric Hardware used to capture \ref bioapi_definition_raw_biometric_sample%s from a subject.
 * \note The term <i>biometric device</i> is used interchangeably with this term.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_bsp Biometric Service Provider (BSP)
 * Component that provides Biometric Services to an application through a defined interface by
 * managing one or more \ref bioapi_definition_unit%s directly, or through interfaces to \ref bioapi_definition_bfp "BFPs".
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_biometrics Biometrics
 * (noum) Automated recognition of individuals based on their behavioural and biological characteristics.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_callback Callback
 * Mechanism by which a component that exposes an API invokes a function within a component that uses that 
 * API, where the address of that function has been previously passed as an input parameter of an
 * API function call
 * \note This mechanism enables a \ref bioapi_definition_biopi_component to communicate with another 
 * \ref bioapi_definition_biopi_component other than by invoking an API function, usually in response 
 * to an event or interrupt.
 * \see <a href="http://en.wikipedia.org/wiki/Callback_%28computer_programming%29">Wikipedia: Callback</a>
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_component_registry Component Registry
 * Information maintained by the BioAPI Framework concerning the \ref bioapi_definition_biopi_component%s 
 * that are available on a biometric system.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_encryption Encryption
 * (Reversible) Transformation of data by a cryptographic algorithm to produce ciphertext;
 * that is, to hide the information content (protect the confidentiality) of the data.
 * \note Encryption algorithms consist of two processes: encryption (or encipherment) 
 * which transforms plaintext into ciphertext, and decryption (or decipherment) which transforms ciphertext to plaintext.
 * \note Encryption may be used for either security or privacy reasons.
 * \see <a href="http://en.wikipedia.org/wiki/Encryption">Wikipedia: Encryption</a>
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_enrollment Enrollment
 * Process of collecting one or more \ref bioapi_definition_biometric_sample%s from an individual, 
 * and the subsequent construction of a biometric \ref bioapi_definition_reference_template which can then be 
 * used to verify or determine the individual’s identity
 * \note The \ref bioapi_definition_reference_template would normally be stored by a biometric application, a \ref bioapi_definition_bsp supporting an archive \ref bioapi_definition_unit, or both.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_fmr False Match Rate (FMR)
 * Measure of the probability that a biometric matching process will incorrectly identify an individual
 * or will fail to reject an impostor.
 * \note Within BioAPI, \ref bioapi_definition_fmr is used as a means of specifying scores and \ref bioapi_definition_threshold%s (see clause C.4).
 * \note Historically, <i>False Acceptance Rate (FAR)</i> has also been used with a similar definition, but 
 * \ref bioapi_definition_fmr is the preferred term in International Standards.
 * \see <a href="http://en.wikipedia.org/wiki/Biometrics#Performance">Wikipedia: Biometrics Performance</a>
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_fnmr False Match Rate (FNMR)
 * Measure of the probability that a biometric matching process will incorrectly reject an individual
 * or will fail to detect a match.
 * \note Historically, <i>False Rejection Rate (FRR)</i>,  has also been used with a similar definition, but 
 * \ref bioapi_definition_fnmr is the preferred term in International Standards.
 * \see <a href="http://en.wikipedia.org/wiki/Biometrics#Performance">Wikipedia: Biometrics Performance</a>
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_handle Handle
 * Parameter returned by a BioAPI function (A say) that can be used by the BioAPI application 
 * in a subsequent function call to identify a BioAPI component or data element within the component A.
 * \note Types of handles include:
 *   - BioAPI_HANDLE, generated by a \ref bioapi_definition_bsp to access an 
 *     \ref bioapi_definition_attach_session within that \ref bioapi_definition_bsp.
 *   - BioAPI_BIR_HANDLE, generated by a \ref bioapi_definition_bsp to select or access a \ref bioapi_definition_bir within that \ref bioapi_definition_bsp.
 *   - BioAPI_DB_HANDLE, generated by a \ref bioapi_definition_bsp to select or access a \ref bioapi_definition_bir database 
 *     controlled by that \ref bioapi_definition_bsp.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_identification Identification
 * One-to-many process of comparing a submitted \ref bioapi_definition_biometric_sample against a reference population to determine
 * whether the submitted \ref bioapi_definition_biometric_sample matches any of the \ref bioapi_definition_reference_template%s in that reference population
 * in order to determine the identity of the enrollee whose template was matched.
 * \note This is often called an <i>identification match</i> or <i>identifymatch</i>.
 * \see <a href="http://en.wikipedia.org/wiki/Biometrics">Wikipedia: Biometrics</a>
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_matching Matching
 * One-to-one process of comparing a submitted \ref bioapi_definition_biometric_sample against a single biometric 
 * \ref bioapi_definition_reference_template and scoring the level of similarity.
 * \note An accept or reject decision would then normally be based upon whether this score exceeds  a given \ref bioapi_definition_threshold.
 * \note Matching algorithms and their effect on \ref bioapi_definition_fmr and \ref bioapi_definition_fnmr scores are currently
not standardised.
 * \see \ref bioapi_definition_identification
 * \see \ref bioapi_definition_verification
 * \see <a href="http://en.wikipedia.org/wiki/Biometrics">Wikipedia: Biometrics</a>
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_payload Payload
 * Data, provided at the time of \ref bioapi_definition_enrollment and associated with a 
 * \ref bioapi_definition_reference_template, which can be released upon a successful 
 * biometric \ref bioapi_definition_verification.
 * \note Examples of \ref bioapi_definition_payload%s include user names, accounts, 
 * passwords, cryptographic keys, or digital certificates (see clause C.5).
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_score Score
 * Value indicating the degree of similarity or correlation between a \ref bioapi_definition_biometric_sample 
 * and a biometric \ref bioapi_definition_reference_template.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_sb Security Block (SB)
 * Block of data with a defined format that contains security information 
 * (for example, related to encryption or integrity) related to a \ref bioapi_definition_bir 
 * \see \ref iso19785-1
 * \see \ref iso19785-4
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_self_contained_device Self-Contained Device
 * Combination device which includes a \ref bioapi_definition_biometric_sensor and all or part of the 
 * \ref bioapi_definition_bsp functionality.
 * \note A \ref bioapi_definition_self_contained_device may include the ability to not only capture a \ref bioapi_definition_biometric_sample, 
 * but also to process, match, and/or store it. This functionality is typically implemented in hardware/firmware.
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_signature Digital Signature
 * Data appended to, or a cryptographic transformation of, a data unit that allows the recipient of the data unit to
 * prove the origin and integrity of the data unit and protect against forgery, e.g. by the recipient
 * \note \ref bioapi_definition_signature%s may be used for purposes of authentication, data integrity, and non-repudiation.
 * \see <a href="http://en.wikipedia.org/wiki/Digital_signature">Wikipedia: Digital Signature</a>
 * 
 *
 * 
 * 
 * 
 * 
 * \section bioapi_definition_threshold Threshold
 * Predefined value which establishes the degree of similarity or correlation (that is, a score) necessary for a
 * \ref bioapi_definition_biometric_sample to be deemed a \ref bioapi_definition_matching "match" with a biometric 
 * \ref bioapi_definition_reference_template.
 *
 * 
 * 
 * 
 * 
 * \section bioapi_definition_uuid Universally Unique Identifier (UUID)
 * 128-bit value generated in accordance with \ref iso9834-8 and providing unique values between systems and over time.
 * \see <a href="http://en.wikipedia.org/wiki/UUID">Wikipedia: Universally Unique Identifier</a>
 * 
 * 
 * 
 * 
 * 
 * \section bioapi_definition_verification Verification
 * One-to-one process of comparing a single submitted \ref bioapi_definition_biometric_sample against a biometric 
 * \ref bioapi_definition_reference_template to determine whether the submitted biometric sample 
 * \ref bioapi_definition_matching "matches" the reference template.
 * \note This is often called a <i>verification match</i> or <i>verifymatch</i>.
 * \see <a href="http://en.wikipedia.org/wiki/Biometrics">Wikipedia: Biometrics</a>
 */
