# Simulation-of-flash-memory
Development of a program that simulates flash memory. Functions for writing and reading data from flash memory. <br>
<br>
void write_uint16_t(uint16_t val); <br>
void write_uint8_t(uint8_t val); <br>
void write_uint32_t(uint32_t val); <br>
void write_bool(bool val); <br>
void print_data(); <br>
void erase_data(); <br>
uint8_t is_busy(); <br>
<br> 
Program should be able to write different data types to the memory, as it
can be seen above. These data types (for instance,
1 integer is 4 bytes, if you try to write more than 64 integers to the memory you
will get an error). You should also add functions for printing the whole data inside
your memory and for erasing the whole memory. Function is_busy() should
return hexadecimal value of bytes that are not empty inside your memory. Handling of cases when you try to write to the full memory or read/clear the
empty memory. Basically, we are going to create a new mixed type data
structure.

