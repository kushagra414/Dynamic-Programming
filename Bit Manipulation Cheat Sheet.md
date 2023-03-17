# Bit Manipulation Cheat Sheet

## Check if two integers have opposite signs
```c++
if(x^y >0)
    return false;
else
    return true;
```

## Add 1 to a given number
```c++
(-(~x));
```

## Multiply a number by 2
```c++
x<<1;
```

## Divide a number by 2
```c++
x>>1;
```

## Turn off the rightmost set bit
```c++
x&(x-1);
```

## Check whether a given number is a power of 4 or not
```c++
if(!(x & (x-1))){
    if(__builtin_ctz(x)%2==0)
        return true;
```

## Compute modulus division by a power-of-2-number
```c++
x & (powerOf2 - 1);
```

## Rotate bits of a number
```c++
int leftCircularShift(int x,int shiftBy)
    return (x<<shiftBy) | (x>>(total_bits-shiftBy));

int rightCircularShift(int x,int shiftBy)
    return (x>>shiftBy) | (x<<(total_bits-shiftBy));
```

## Count number of bits to be flipped to convert A to B
```c++
__builtin_popcount(a ^ b);
```

## Find whether a no is power of two
```c++
return (n>0 and !(n&(n-1)));
```

## Position of rightmost set bit
```c++
ffs(x);
//another way
log2(x & -x)+1;
//another way
if(x!=0)
    __builtin_ctz(x)+1;
```

## Calculate XOR from 1 to n
```c++
switch(n & 3) // n % 4  
{ 
    case 0: return n;     // if n is multiple of 4 
    case 1: return 1;     // If n % 4 gives remainder 1   
    case 2: return n + 1; // If n % 4 gives remainder 2     
    case 3: return 0;     // If n % 4 gives remainder 3   
} 
```

## Binary representation of a given number
```c++
void bin(unsigned n) 
{ 
    if (n > 1) 
        bin(n>>1); 
      
    cout<<(d & 1)<<endl;
}
```

## Find position of only set bit
```c++
if(!(n&(n-1)))
	ffs(n);
```

## Turn off a particular bit in a number
```c++
x & (~1<<(pos-1));
```

## Check if 2 numbers are equal
```c++
if((x ^ y))
    return false;
else
    return true;
```

## Find XOR of numbers without using xor operator
```c++
(x | y) & (~x | ~y);
```

## Swap three variables
```c++
x = x ^ y ^ z;
y = x ^ y ^ z;
z = x ^ y ^ z;
x = x ^ y ^ z;
```

## Toggle Kth bit of a number
```c++
x = x ^ 1<<(k-1);
```

## Toggle all bits except Kth bit of a number
```c++
x = ~(x ^ 1<<(k-1);)
```

## Set the rightmost unset bit
```c++
x = x | (x+1)
```

## Toggle the last m bits
```c++
x ^ ~(-1<<m);
```

## Maximum XOR-value of at-most k-elements from 1 to n
```c++
int x = log2(n) + 1;
return x<<1 - 1;

//Alt way

int res = 1; 
while (res <= n) 
    res <<= 1; 
// Finding number greater than 
// or equal to n with most significant  
// bit same as n. For example, if n is 
// 4, result is 7. If n is 5 or 6, result  
// is 7 
// Return res - 1 which denotes 
// a number with all bits set to 1 
return res - 1; 
``` 

## Check if a number is divisible by 8 using bitwise operators
```c++
return (((n >> 3) << 3) == n);
```

## Toggle bits of a number except first and last bits
```c++
int size = sizeof(int)*8 - __builtin_clz(n);
int one = (1<<(size-1))-1;
n = n ^ one;
n = n ^ 1;
```

# Toggle all even bits of a number
```c++
int temp = n,i=1;
while(temp){
    n = n ^ 1>>(i*2);
    i++;
    temp = temp>>1;
}
```

## Brian Kernighan’s Algorithm for counting set Bits
```c++
while(n){
    n &=(n-1);
    count++;
}

```
