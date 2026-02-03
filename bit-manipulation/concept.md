Proof of 2's complement

negative number are represented in binary with help of 2's complement
so, -x = ~x + 1

---
Some bit operations on num

1. set(x, i) = x | (1 << i)
2. unset(x, i) = x & ~(1 << i)
=> if (check(x, i)) x -= (1 << i)
3. check(x, i) = (x >> i) & 1
4. flip(x, i) = x ^ (1 << i)
5. count(x) = lambda x == 0 ? 0 : count(x >> 1) + (x & 1), applies to x >= 0.
For negatives use, __builtin_popcount()
or just use,
while (x): { x = x & (x - 1); ans++ } since, -1 would cause carry from latest one to go backward to all and thus, & operation would eat the right-most one.
Like, 
x = 101...01000
x - 1 = 101...00111 (carry will go from rightmost 1 to left side where it is needed)
x & (x - 1) = 101...00000 (So, right most bit is eaten.)

