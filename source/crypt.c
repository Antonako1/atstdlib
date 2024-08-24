/*+++
    ATSTDLIB CRYPT C SOURCE - Antonako1
    
    Licensed under MIT
---*/
#include <atstdlib_crypt.h>
#include <atstdlib_ext_types.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#define WORDSIZE            4
#define MAGIC 0xFF4F
#define MAXSTRLEN 255
/*+++
Somewhat working Rijndael algorithm
---*/

const U8 sbox[] = {
    0x63, 	0x7c, 	0x77, 	0x7b, 	0xf2, 	0x6b, 	0x6f, 	0xc5, 	0x30, 	0x01, 	0x67, 	0x2b, 	0xfe, 	0xd7, 	0xab, 	0x76,
    0xca, 	0x82, 	0xc9, 	0x7d, 	0xfa, 	0x59, 	0x47, 	0xf0, 	0xad, 	0xd4, 	0xa2, 	0xaf, 	0x9c, 	0xa4, 	0x72, 	0xc0,
    0xb7, 	0xfd, 	0x93, 	0x26, 	0x36, 	0x3f, 	0xf7, 	0xcc, 	0x34, 	0xa5, 	0xe5, 	0xf1, 	0x71, 	0xd8, 	0x31, 	0x15,
    0x04, 	0xc7, 	0x23, 	0xc3, 	0x18, 	0x96, 	0x05, 	0x9a, 	0x07, 	0x12, 	0x80, 	0xe2, 	0xeb, 	0x27, 	0xb2, 	0x75,
    0x09, 	0x83, 	0x2c, 	0x1a, 	0x1b, 	0x6e, 	0x5a, 	0xa0, 	0x52, 	0x3b, 	0xd6, 	0xb3, 	0x29, 	0xe3, 	0x2f, 	0x84,
    0x53, 	0xd1, 	0x00, 	0xed, 	0x20, 	0xfc, 	0xb1, 	0x5b, 	0x6a, 	0xcb, 	0xbe, 	0x39, 	0x4a, 	0x4c, 	0x58, 	0xcf,
    0xd0, 	0xef, 	0xaa, 	0xfb, 	0x43, 	0x4d, 	0x33, 	0x85, 	0x45, 	0xf9, 	0x02, 	0x7f, 	0x50, 	0x3c, 	0x9f, 	0xa8,
    0x51, 	0xa3, 	0x40, 	0x8f, 	0x92, 	0x9d, 	0x38, 	0xf5, 	0xbc, 	0xb6, 	0xda, 	0x21, 	0x10, 	0xff, 	0xf3, 	0xd2,
    0xcd, 	0x0c, 	0x13, 	0xec, 	0x5f, 	0x97, 	0x44, 	0x17, 	0xc4, 	0xa7, 	0x7e, 	0x3d, 	0x64, 	0x5d, 	0x19, 	0x73,
    0x60, 	0x81, 	0x4f, 	0xdc, 	0x22, 	0x2a, 	0x90, 	0x88, 	0x46, 	0xee, 	0xb8, 	0x14, 	0xde, 	0x5e, 	0x0b, 	0xdb,
    0xe0, 	0x32, 	0x3a, 	0x0a, 	0x49, 	0x06, 	0x24, 	0x5c, 	0xc2, 	0xd3, 	0xac, 	0x62, 	0x91, 	0x95, 	0xe4, 	0x79,
    0xe7, 	0xc8, 	0x37, 	0x6d, 	0x8d, 	0xd5, 	0x4e, 	0xa9, 	0x6c, 	0x56, 	0xf4, 	0xea, 	0x65, 	0x7a, 	0xae, 	0x08,
    0xba, 	0x78, 	0x25, 	0x2e, 	0x1c, 	0xa6, 	0xb4, 	0xc6, 	0xe8, 	0xdd, 	0x74, 	0x1f, 	0x4b, 	0xbd, 	0x8b, 	0x8a,
    0x70, 	0x3e, 	0xb5, 	0x66, 	0x48, 	0x03, 	0xf6, 	0x0e, 	0x61, 	0x35, 	0x57, 	0xb9, 	0x86, 	0xc1, 	0x1d, 	0x9e,
    0xe1, 	0xf8, 	0x98, 	0x11, 	0x69, 	0xd9, 	0x8e, 	0x94, 	0x9b, 	0x1e, 	0x87, 	0xe9, 	0xce, 	0x55, 	0x28, 	0xdf,
    0x8c, 	0xa1, 	0x89, 	0x0d, 	0xbf, 	0xe6, 	0x42, 	0x68, 	0x41, 	0x99, 	0x2d, 	0x0f, 	0xb0, 	0x54, 	0xbb, 	0x16,
};

const U8 rcon[] ={
    0x01,   0x02,   0x04,   0x08,   0x10,   0x20,   0x40,   0x80,   0x1B,   0x36
};

void rotate_word(U32 *word){
    U8 left_byte = (*word >> 24) & 0xFF;
    *word <<= 8;
    *word |= left_byte;
}
void substition_box(U32 *word){
    U32 new_word = 0;
    for (U8 i = 0; i < WORDSIZE; i++) {
        U8 byte = (*word >> (i * 8)) & 0xFF;
        byte = sbox[byte];
        new_word |= (byte << (i * 8));
    }
    *word = new_word;
}

U8 rcon_func(U8 round_index){
    if(0 < round_index <= (sizeof(rcon) / sizeof(rcon[0]))){
        return rcon[round_index - 1];
    } else {
        return 0;
    }
}

void expand_key(U32 *expanded_key, U256 *generate_from) {
    // Initialize the first 8 words (256 bits) from the original key
    expanded_key[0] = (U32)(generate_from->parts[0] >> 32) & 0xFFFFFFFF;
    expanded_key[1] = (U32)generate_from->parts[0] & 0xFFFFFFFF;
    expanded_key[2] = (U32)(generate_from->parts[1] >> 32) & 0xFFFFFFFF;
    expanded_key[3] = (U32)generate_from->parts[1] & 0xFFFFFFFF;
    expanded_key[4] = (U32)(generate_from->parts[2] >> 32) & 0xFFFFFFFF;
    expanded_key[5] = (U32)generate_from->parts[2] & 0xFFFFFFFF;
    expanded_key[6] = (U32)(generate_from->parts[3] >> 32) & 0xFFFFFFFF;
    expanded_key[7] = (U32)generate_from->parts[3] & 0xFFFFFFFF;

    U32 temp;
    U8 i = WORDCOUNT;  // Start at the first word after the initial key

    while (i < WORDCOUNT) {
        temp = expanded_key[i - 1];

        if (i % WORDCOUNT == 0) {
            rotate_word(&temp);                // RotWord
            substition_box(&temp);             // SubWord
            temp ^= rcon_func(i / WORDCOUNT);  // Rcon XOR with the first byte of temp
        } else if (i % WORDCOUNT == 4) {
            substition_box(&temp);  // Apply SubWord every 4 words for AES-256
        }

        expanded_key[i] = expanded_key[i - WORDCOUNT] ^ temp;
        i++;
    }
}


void initialize_seeds_part(U256 *seed, U16 index, const U8 *pass){
    for(size_t i = 0; i < strlen(pass); i++){
        seed->parts[index] ^= (pass[i] * (index + 1)) | (i+1) & MAGIC * 2;
    }
    if(seed->parts[index] >= U64_MAX){
        seed->parts[index] %= (pass[3] * (index + 1)) ^ MAGIC;
    }
    while(seed->parts[index] < EIGHT_BYTE_MINIMUM){
        seed->parts[index] *= seed->parts[index] * MAGIC * 2 ^ 0xAD * (index + 1);
    }
}

U32 *generate_256_key(const U8 *input_string){
    if(strlen(input_string) > 255){
        return NULLPTR;
    }
    U32 *key = malloc(sizeof(U32) * WORDCOUNT);
    U256 large_key_input;
    for(I16 i = 0; i < _256_PARTS; i++){
        large_key_input.parts[i] = 1;
        initialize_seeds_part(&large_key_input, i, input_string);
    }
    expand_key(key, &large_key_input);
    return key;
}

U0 free_256_key(U32 *key){
    free(key);
}

/*+++
RAND FUNCTIONS

Randomizer is the Mersenne Twister. 
Code taken mercilessly from wikipedia. Only types are changed
Link: https://en.wikipedia.org/wiki/Mersenne_Twister#C_code
---*/

#define n 624
#define m 397
#define w 32
#define r 31
#define UMASK (0xffffffffUL << r)
#define LMASK (0xffffffffUL >> (w-r))
#define a 0x9908b0dfUL
#define u 11
#define s 7
#define t 15
#define l 18
#define b 0x9d2c5680UL
#define c 0xefc60000UL
#define f 1812433253UL

typedef struct mt_state{
    U32 state_array[n];         // the array for the state vector 
    I32 state_index;            // index into state vector array, 0 <= state_index <= n-1   always
} mt_state;

U32 global_seed = 0; // 19650218UL

U0 initialize_state(mt_state* state, U32 seed) {
    U32* state_array = &(state->state_array[0]);
    
    state_array[0] = seed;                          // suggested initial seed = 19650218UL
    
    for (int i=1; i<n; i++){
        seed = f * (seed ^ (seed >> (w-2))) + i;    // Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier.
        state_array[i] = seed; 
    }
    
    state->state_index = 0;
}

U32 random_uint32(mt_state* state){
    U32* state_array = &(state->state_array[0]);
    
    int k = state->state_index;      // point to current state location
                                     // 0 <= state_index <= n-1   always
    
//  int k = k - n;                   // point to state n iterations before
//  if (k < 0) k += n;               // modulo n circular indexing
                                     // the previous 2 lines actually do nothing
                                     //  for illustration only
    
    int j = k - (n-1);               // point to state n-1 iterations before
    if (j < 0) j += n;               // modulo n circular indexing

    U32 x = (state_array[k] & UMASK) | (state_array[j] & LMASK);
    
    U32 xA = x >> 1;
    if (x & 0x00000001UL) xA ^= a;
    
    j = k - (n-m);                   // point to state n-m iterations before
    if (j < 0) j += n;               // modulo n circular indexing
    
    x = state_array[j] ^ xA;         // compute next value in the state
    state_array[k++] = x;            // update new state value
    
    if (k >= n) k = 0;               // modulo n circular indexing
    state->state_index = k;
    
    U32 y = x ^ (x >> u);       // tempering 
             y = y ^ ((y << s) & b);
             y = y ^ ((y << t) & c);
    U32 z = y ^ (y >> l);
    
    return z; 
}



U0 randseed(U32 seed){
    global_seed = seed;
}
U32 urand(U0){
    mt_state state;
    U32 seed_to_use;
    if(global_seed == 0){
        seed_to_use = (U32)time(NULLPTR);
    } else {
        seed_to_use = global_seed;
    }
    initialize_state(&state, seed_to_use);
    return random_uint32(&state);
}
U32 urand_range(U32 range_min, U32 range_max){
    U32 range = range_max - range_min;
    U32 res = urand() % (range + 1) + range_min;
    return res;
}
