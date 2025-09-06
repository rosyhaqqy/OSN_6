#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sumdigit(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    ll q;
    cin >> q;

    while (q--)
    {
        ll n;
        cin >> n;

        ll jumlahdigit = 0;
        ll sisa = n / 3;

        if (n % 3 == 0)
        {
            jumlahdigit = 10 * (sisa - 5);
            ll belakang = 370370370370370 - sisa;
            jumlahdigit += sumdigit(belakang);
        }
        else if (n % 3 == 1)
        {
            jumlahdigit = 10 * (sisa - 5);
            ll belakang = 3703703703703703 - sisa;
            jumlahdigit += sumdigit(belakang);
        }
        else
        {
            jumlahdigit = 10 * (sisa - 5);
            ll belakang = 37037037037037036 - sisa;
            jumlahdigit += sumdigit(belakang);
        }

        cout << jumlahdigit << "\n";
    }
}