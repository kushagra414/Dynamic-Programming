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
x&(powerOf2-1);
```

## Rotate bits of a number
```c++
int leftCircularShift(int x,int shiftBy)
    return (x<<shiftBy) | (x>>shiftBy);

int rightCircularShift(int x,int shiftBy)
    return (x>>shiftBy) | (x<<shiftBy);
```

## Count number of bits to be flipped to convert A to B
```c++
__builtin_popcount(a^b);
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