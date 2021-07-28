/*
 * https://codeforces.com/problemset/problem/110/A
 

Petya loves lucky numbers. We all know that lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Unfortunately, not all numbers are lucky. Petya calls a number nearly lucky if the number of lucky digits in it is a lucky number. He wonders whether number n is a nearly lucky number.
Input

The only line contains an integer n (1 ≤ n ≤ 10^18).

Please do not use the %lld specificator to read or write 64-bit numbers in С++. It is preferred to use the cin, cout streams or the %I64d specificator.
Output

Print on the single line "YES" if n is a nearly lucky number. Otherwise, print "NO" (without the quotes).

SAMPLES:
40047
	NO

7747774
	YES

1000000000000000000
	NO
 */

#include <iostream>

int main()
{
    unsigned long long n;
    std::cin >> n;
    int _4s = 0, _7s = 0;
    
    while (n > 0)
    {
        if (n%10 == 4)      _4s++;
        else if (n%10 == 7) _7s++;
        n /= 10;
    }
    
    if ((_4s+_7s) != 0 && ((_4s+_7s) == 4 || (_4s+_7s) == 7))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    
    return 0;
}