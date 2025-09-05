

# Divide and Conquer (D&C)

## 📌 Apa itu Divide and Conquer?
**Divide and Conquer (D&C)** adalah paradigma algoritma yang menyelesaikan masalah dengan tiga langkah utama:

1. **Divide** → Membagi masalah besar menjadi beberapa sub-masalah yang lebih kecil.  
2. **Conquer** → Menyelesaikan masing-masing sub-masalah (biasanya dengan rekursi).  
3. **Combine** → Menggabungkan solusi sub-masalah untuk membentuk solusi masalah semula.  

Paradigma ini digunakan dalam banyak algoritma klasik seperti **Merge Sort**, **Quick Sort**, dan **Binary Search**.

---

## 📌 Contoh Kasus: Fibonacci

### 1. Fibonacci dengan **Divide and Conquer**
Implementasi sederhana menggunakan rekursi murni:

```cpp
#include <bits/stdc++.h>
using namespace std;

long long fib(int n) {
    if (n <= 1) return n; // base case
    return fib(n-1) + fib(n-2); // divide & conquer
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
}
````

**Penjelasan:**

* Masalah `fib(n)` dipecah menjadi dua sub-masalah: `fib(n-1)` dan `fib(n-2)`.
* Hasilnya digabung dengan operasi penjumlahan.

**Kelemahan:**
Banyak perhitungan berulang → kompleksitas waktu **O(2^n)**.

---

### 2. Fibonacci dengan **Dynamic Programming (Optimalisasi D\&C)**

Untuk mengatasi perhitungan berulang, kita bisa menyimpan hasil sub-masalah (**memoization** atau **tabulation**).

#### a. Top-Down (Memoization)

```cpp
#include <bits/stdc++.h>
using namespace std;

long long memo[1000];

long long fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n]; // gunakan hasil yang sudah ada
    return memo[n] = fib(n-1) + fib(n-2);
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
}
```

#### b. Bottom-Up (Tabulation)

```cpp
#include <bits/stdc++.h>
using namespace std;

long long fib(int n) {
    vector<long long> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
}
```

**Keunggulan DP:**

* Tidak ada perhitungan berulang.
* Kompleksitas waktu **O(n)**, kompleksitas ruang **O(n)** (atau bisa dipangkas jadi **O(1)** dengan hanya menyimpan dua nilai terakhir).

---

## 📌 Perbandingan D\&C vs DP pada Fibonacci

| Metode                 | Pendekatan                  | Kompleksitas Waktu | Kompleksitas Ruang |
| ---------------------- | --------------------------- | ------------------ | ------------------ |
| Divide & Conquer murni | Rekursi tanpa penyimpanan   | O(2^n)             | O(n)               |
| DP (Memoization)       | Rekursi + penyimpanan hasil | O(n)               | O(n)               |
| DP (Tabulation)        | Iteratif + tabel            | O(n)               | O(n) → O(1)        |

---

