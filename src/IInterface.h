/*****************************************************************
* 
* 
* 
* 
* 
****************************************************************/
/**
 * @defgroup  Shared Group of Shared files.
 */
/**
* @file      IInterface.h
* @ingroup   Shared
* @author    Shrawan Kumar
*
* @brief     Interface simulation macros in C++
*
* @note Usage:
* @code{.cpp}
* DeclareInterface
*     // Pure virtual functions
* EndInterface
* @endcode
*/
#ifndef IINTERFACE_H_
#define IINTERFACE_H_

/**
 * Macro to simulate Interface
 */
#define Interface class

/**
 * Macro to declare the interface that is not derived from any base class.
 *
 * Interface pointer should have virtual dtors. This macro takes care of this requirement.
 *
 * @param name Interface Name
 */
#define DeclareInterface(name) Interface name { \
          public: \
          virtual ~name() {}

/**
 * Macro to declare the interface that is derived from any base class.
 *
 * Interface pointer should have virtual Dtor. This macro takes care of this requirement.
 * @param name Interface Name
 * @param base Name of the base Interface for the interface
 *
 * @warning  Do not derive from a non-Interface class.
 */
#define DeclareBasedInterface(name, base) class name : public base { \
          public: \
          virtual ~name() {}

/**
 * Macro to indicate end of the Interface.
 */
#define EndInterface };

/**
 * Macro to simulate the keyword implements
 */
#define implements public

#endif /* IINTERFACE_H_ */
