#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

/*
Lessons: 
The bitset<N> should be constant.
1. when initialized with strings it truncates from right.
2. when initialized with num it truncates from left.
3. We can perform bitwise operation on two bitsets and it returns a bitset given that they are of same length.
4. bs[] has undefined behaviour so, use .test() for bound checking.
*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // Initializing with binary strings.
    bitset<8> bs_str("0100001010");
    cout << bs_str << endl;
    bitset<8> bs_num(4);
    cout << bs_num << endl;

    // Initializing with binary represented number.
    bitset<8> bs_bin(0b1010'0000);
    cout << bs_bin << endl;

    bs_bin.set(1);
    bs_bin.set(2);

    cout << bs_bin << endl;

    bs_bin.reset(5);

    cout << bs_bin << endl;

    // undefined behaviour: no bound checking 
    cout << bs_bin[100] << endl;

    // using .test()
    cout << bs_bin.test(7) << endl;
    // cout << bs_bin.test(8) << endl;
    // cout << bs_bin.test(100) << endl;

    // flipping bits. Flips and return the bitwise set.
    bs_bin.flip(6);
    cout << bs_bin << endl;

    // Flips all bits and returns the bitwise set.
    bs_bin.flip();
    cout << bs_bin << endl;

    // Some other operations
    cout << bs_bin.any() << endl;
    cout << bs_bin.all() << endl;
    cout << bs_bin.none() << endl;
    cout << bs_bin.count() << endl;
    cout << bs_bin.size() << endl;

    // converting to number
    cout << bs_bin.to_ulong() << endl;
    cout << bs_bin.to_ullong() << endl;
    

    // converting to string
    cout << bs_bin.to_string() << endl;
    // Throws error
    // string str = bs_bin;

    // Works
    string str = bs_bin.to_string();
    cout << str << endl;

    return 0;
}