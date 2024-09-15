#include <bitset>

/**
 * @brief The std::bitset  is a statically-sized container offering bit-level
 * adressing.
 * 
 * On top of the storage and bit access, the container also provides the typical
 * boolean (all_of, any_of, none_of), bitwise (AND, OR, XOR, not) and global
 * (set, reset, flip) bit manipulations.
 */

std::bitset<16> data;

//the zero index refers tı the least significnt bit
data[0] = 1;    //data.to_ullong() == 1

//set all bits to 1
data.set();     //data.to_ullong == 65535

//flip all bits (setting them to zero)
data.flip();

data[0] = 1;
data[2] = 1;
data[4] = 1;

std::bitset<16> other;
other[0] = 1;
other[2] = 1;


data &= other;

bool test = data.any(); //any of bit value == 1 
size_t cnt = data.count();  //count of 1 bits
