# BettRand v1.0.0
Is a simple but convenient wrapper around the C++ random library.  
Replaces the standard `rand()` with powerful computational mathematics that guarantees a strong distribution of random values.
  
 - It provides a simplified syntax, built upon a combination of other libraries,  
for generating random numbers of various types.
 - Ideally suited for simulations and random distribution tasks.


## Functions And Their Syntax  
  namespace `betrand`.
  ### Random Data Generation
  `betrand::rand_I<type>(<MIN>, <MAX>)` - Generates random [*integer type*] number in the range [MIN, MAX].  
  
  `betrand::rand_I_fast<type>(<MIN>, <MAX>)` - It functions just like the previous version but employs simpler mathematics;  
  however, the random number distribution is of lower quality in exchange for increased speed.

  `betrand::rand_F<type>(<MIN>, <MAX>)` - Generates [*real type*] number in the range from [MIN, MAX]. 
  
  `betrand::rand_F_fast<type>(<MIN>, <MAX>)` - It functions just like the previous version but employs simpler mathematics;  
  however, the random number distribution is of lower quality in exchange for increased speed.

  ### Data Distribution  
  `betrand::chance(<VALUE>)` - Returns true if a chance equal to <VALUE> triggers randomly. 
  `VALUE` must be in the range from 0 to 1.

  `betrand::chance_to_attempts(<VALUE>)` - This serves as a representation of the previous function,  
  but returns a random integer number of attempts required for a success to occur with a probability of `VALUE`.

  `betrand::normal_distribution()` - Returns a random real number in the range from 0 to 1.

  ### Arrays
  `betrand::chance_to_attempts(<ORIGIN_VECTOR>)` - Randomly shuffles the values ​​in an array by index.  

  `betrand::rand_select(<ORIGIN_VECTOR>, <RESULT_VECTOR>, <AMOUNT>)` - Selects `AMOUNT` random elements  
  from `ORIGIN_VECTOR` and inserts them into `RESULT_VECTOR`.

  `betrand::generate_data<type>(<ORIGIN_EMPTY_VECTOR>, <AMOUNT>, <MIN>, <MAX>)` - Generates `AMOUNT` random numbers  
  within the range [MIN, MAX] into `ORIGIN_EMPTY_VECTOR`. Supports both integers and real numbers.
