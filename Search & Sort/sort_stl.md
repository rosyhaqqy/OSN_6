# sort()

Di bahasa C++, sudah disediakan suatu fungsi yaitu `sort()` untuk menangani setiap pengurutan yang kita perlukan dari library `<algorithm>`. `sort()` hanya berlaku pada struktur data vector dan array.

Berikut merupakan contoh penggunaan dalam `vector`

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 3, 2, 1, 4};

    // Sort vector (by default in ascending order)
    sort(v.begin(), v.end());

    for (int i : v)
        cout << i << " ";
    return 0;
}
```

Sinteks sort untuk vector sebagai berikut:

`sort(first, last, comp);`
Parameters:

- first: Iterator to the beginning of the range to be sorted.
- last: Iterator to the element just after the end of the range.
- comp (optional): Binary function, functor, or lambda expression that compares two elements in the range. By default, it is set as < operator so the sort() function sorts the data in ascending order.

Berikut merupakan contoh penggunaan dalam array:

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {5, 3, 2, 1, 4};
  	int n = sizeof(arr)/sizeof(arr[0]);

    // Sort array (by default in ascending order)
    sort(arr, arr + n);

    for (int i : arr)
        cout << i << " ";
    return 0;
}
```

```c++
#include <bits/stdc++.h>
using namespace std;

// Custom comparator for descending order
bool comp(int a, int b) {
  	return a > b;
}

int main() {
    int arr[5] = {5, 3, 2, 1, 4};
  	int n = sizeof(arr)/sizeof(arr[0]);

    // Sort array in descending order
    sort(arr, arr + n, comp);

    for (int i : arr)
        cout << i << " ";
    return 0;
}
```
