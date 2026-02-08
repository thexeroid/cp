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
6. reverse(x): reverses the current binary representation of x. Starts reversing from MSB.
For example, for (4)10 -> (0100)2
it gives reverse(4) -> (0001)2

So, it becomes:
ans = 0
while (x) {
    ans = (ans << 1) + (x & 1);  
    x >>= 1;
}
---
Bitmask: Representing and manipulating small set using only numbers.

---

Insights:
1. num & -num will give a number with LSB set.
2. Be careful with >> with signed numbers it doesn't behave as expected sometimes like with -1.
3. In C++ 14+, we can do `int num = 0b1111` and we can use it via XOR to flip a range. 