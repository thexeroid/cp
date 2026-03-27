LCCM Framework

Divide and conquer: It is where we split the problem into multiple non-overlapping problems and solve them on their own and merge the result
Recursion with DP: While in this case, we split the problem in multiple parts out of which some sub-trees overlaps and repeat in the recursion tree so, we save them and all.

---

(The lemma is false for array with duplicates) 
Lemma: i < j && A[i] != A[j] => swap(A[i], A[j]) causes inversions -= odd
we conclude from that the parity(# of swaps) = parity(# of inversions)

Mainly proved for ascending order. Guess, it works for both orders.

---

Master's theorem: (For computing mostly the TC of divide and conquer)

T(n) = a * T(n / b) + C

Steps:
Compute pair: (first = n^log_B(A), second=C)

If pair.first == C:
=> TC = ClogN
If pair.first > C:
=> TC = n^log_B(A)
If pair.first < C:
=> TC = C

For example, for merge sort, it is

T(n) = 2 * T(n / 2) + N => A = 2, B = 2, C = N
Computing pair: (first = N ^ log_2(2), second = N)
=> (first = N, second = N)
Since first == second => TC = ClogN = NlogN