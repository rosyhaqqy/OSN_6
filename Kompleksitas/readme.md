
# 📌 Kompleksitas dalam Competitive Programming

## 1. **Kenapa Kompleksitas Penting?**

Di CP, waktu eksekusi biasanya dibatasi **1–2 detik**.
Dengan CPU rata-rata bisa melakukan sekitar **10^8 operasi per detik**.
➡️ Jadi sebelum coding, kita harus tahu **kompleksitas algoritma** yang cukup untuk batas input `n`.

---

## 2. **Aturan Kasar: Input Size vs Algoritma**

| Batas `n`   | Algoritma yang Bisa Dipakai    | Kompleksitas Maksimal |
| ----------- | ------------------------------ | --------------------- |
| `n ≤ 20`    | Brute force, backtracking      | O(2^n), O(n!)         |
| `n ≤ 100`   | DP dengan kompleksitas tinggi  | O(n^3)                |
| `n ≤ 1,000` | DP menengah, sorting           | O(n^2)                |
| `n ≤ 10^5`  | Sorting, binary search, greedy | O(n log n)            |
| `n ≤ 10^6`  | Linear scan, prefix sum        | O(n)                  |
| `n ~ 10^9`  | Logarithmic algorithms         | O(log n)              |
| `n > 10^18` | Formula matematis, closed form | O(1)                  |

---

## 3. **Kompleksitas Klasik dalam CP**

### 🔹 **O(1)** → Konstanta

* Hitung luas lingkaran, cek paritas angka.
* Sangat cepat.

### 🔹 **O(log n)** → Divide and Conquer dasar

* Binary Search.
* Fast Exponentiation (modular exponentiation).
* Segment Tree query.

### 🔹 **O(n)** → Linear

* Prefix sum, two pointers.
* BFS/DFS di graf kecil.
* Cukup aman sampai `n = 10^6`.

### 🔹 **O(n log n)** → Umum di CP

* Merge Sort, Quick Sort.
* Binary Search on Answer.
* D\&C seperti Closest Pair of Points.
* Aman sampai `n = 10^5`.

### 🔹 **O(n^2)** → Quadratic

* Floyd-Warshall untuk graf kecil (`n ≤ 500`).
* DP klasik seperti Longest Common Subsequence (LCS) dengan `n ≤ 1000`.
* Kadang bisa dipakai kalau `n` ≤ 2000.

### 🔹 **O(n^3)** → Cubic

* Matrix Multiplication.
* DP untuk graf kecil (misal Traveling Salesman Problem).
* Hanya aman kalau `n ≤ 300`.

### 🔹 **O(2^n)** → Eksponensial

* Brute force subset (power set).
* Bitmask DP untuk TSP (`n ≤ 20`).
* Aman hanya untuk `n ≤ 20`.

### 🔹 **O(n!)**

* Semua permutasi → backtracking penuh.
* Hanya aman untuk `n ≤ 10`.

---

## 4. **Contoh dalam Competitive Programming**

### 1. **Binary Search on Answer**

* Input: `n ≤ 10^5`, nilai sampai `10^9`.
* Kompleksitas: **O(n log(max))**.

### 2. **Graph Traversal**

* BFS/DFS: **O(V + E)**.
* Dijkstra (heap): **O((V+E) log V)**.
* Floyd-Warshall: **O(n^3)**.

### 3. **Dynamic Programming**

* Knapsack 0/1: **O(nW)** (n = jumlah item, W = kapasitas).
* LCS: **O(n^2)**.
* TSP (Bitmask DP): **O(n \* 2^n)**.

---

## 5. **Tips CP tentang Kompleksitas**

* **Estimasi dulu**: Kalau `n = 10^5`, jangan coba O(n^2).
* **Gunakan logika matematika** untuk ubah O(n^2) → O(n log n) atau O(n).
* **Manfaatkan struktur data**: Fenwick Tree, Segment Tree, Sparse Table → sering jadi solusi O(log n).
* **Greedy + Sorting** sering bisa mengganti O(n^2) jadi O(n log n).

---

## 6. **Kesimpulan**

* Kompleksitas menentukan strategi penyelesaian soal CP.
* **Divide and Conquer** sering muncul di **O(log n)** dan **O(n log n)** kasus.
* DP lebih sering di **O(n^2)** atau lebih.
* Semakin besar `n`, semakin butuh optimasi algoritma.

