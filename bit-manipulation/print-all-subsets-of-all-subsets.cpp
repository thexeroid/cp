/*
Note:

Don't assume the TC is 2^n * n^2
if you clearly take a look at first 2 loops, 
you will see that the no. of iterations for each submask = no. of set bits

=> total iterations across all mask = sigma(set bits) across all masks.

Outer loop = 2^n (no doubt)

total submasks formed from all masks containing k set bits (from first two loops) = C(n, k) * (2^k - 1)

This done for masks with k ranging from 0 set bits to n set bits =
k: 0 -> n, sigma(C(n, k) * (2^k - 1))
=> sigma(C(n, k) * 2^k - C(n, k))
=> sigma(C(n, k) * 2^k) - sigma(C(n, k))

By binomial theorem, (a + b)^n = k: 0 -> n; sigma(C(n, k) * a ^ (n - k) * b ^ k)
Our expression looks similar, except there is only 2^k in one and nothing in other.

So, for the one with 2^k, we do
(1 + b)^n = sigma(C(n, k) * b^k) => b = 2 => (3)^n = sigma(C(n, k) * 2^k)

For the one with nothing it looks like,
(1 + 1)^n = sigma(C(n, k)) => a, b = 1 => 2^n = sigma(C(n, k))

Thus, the time complexity of first two loops becomes: (3^n - 2^n)
=> (3^n - 2^n) * n => roughly 3^n * n is the TC.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;

    std::cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for (int mask = 0; mask < (1 << n); mask++)
    {
        cout << "Subset " << mask << ": ";

        // Iterate through submasks
        for (int submask = mask; submask; submask = (submask - 1) & mask)
        {
            cout << "{ ";

            // Iterate through positions
            for (int pos = 0; pos < n; pos++)
            {
                if ((submask & (1 << pos)) != 0)
                {
                    cout << arr[pos] << " ";
                }
            }

            cout << "} ";
        }

        cout << endl;
    }

    return 0;
}
