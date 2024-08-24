/*+++
    ATSTDLIB CRYPT HEADER - Antonako1
    
    Licensed under MIT
---*/

#ifndef ATSTDLIB_CRYPT_H
#define ATSTDLIB_CRYPT_H
#include <atstdlib_types.h>



/// @brief Set seed for the random functions. 
///             When seed is 0, seed will be set to system time. 
///             Default value: 0
/// @param seed Seed to set
U0 randseed(U32 seed);

/// @brief Get random unsigned integer
/// @return Random unsigned integer
U32 urand(U0);

/// @brief Returns random number from urand between range
/// @param range_min Minimun number
/// @param range_max Maximun number
/// @return Random number between given range
U32 urand_range(U32 range_min, U32 range_max); 


/*+++
Basic crypt functions.

Security not quaranteed. Don't use on sensitive data!
---*/
#define WORDCOUNT   8 // Size of 256_key array

/// @brief Generates 256-bit key
/// @param input_string String to generate from. Max length: 255
/// @return WORDCOUNT long array of U32. On failure NULLPTR is returned
/// @note 256-bit key allocated into heap
U32 *generate_256_key(const U8 *input_string);

/// @brief Frees key from memory
/// @param key Pointer to key
U0 free_256_key(U32 *key);

#endif // ATSTDLIB_CRYPT_H