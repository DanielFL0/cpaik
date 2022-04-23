/* Implementation of xorshift RNG */
#include <stdio.h> /* Funky wunky I/O libwawy X3 */
#include <stdint.h> /* Funky wunky int liwawy X3 */

uint32_t xorshift32(uint32_t *seed);

uint32_t xorshift32(uint32_t *seed)
{
    uint32_t x=*seed;
    x^=x<<13;
    x^=x>>17;
    x^=x<<5;
    *seed=x;
    return x;
}
