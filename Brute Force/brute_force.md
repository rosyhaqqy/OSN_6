# Brute Force

## Definisi

_Brute force_ adalah sebuah pendekatan penyelesaian masalah dengan cara **mencoba semua kemungkinan solusi yang ada secara sistematis** hingga ditemukan jawaban yang benar. Pendekatan ini sering digunakan dalam pemrograman kompetitif ketika:

- Ruang pencarian (_search space_) masih relatif kecil.
- Tidak ada algoritma yang lebih efisien diketahui atau dapat diterapkan dengan mudah.
- Digunakan sebagai solusi awal (_baseline solution_) sebelum mengoptimalkan.

---

## Karakteristik Utama

- **Eksplorasi lengkap**: setiap kemungkinan solusi atau kombinasi diuji.
- **Tidak optimal dari sisi waktu**: biasanya memiliki kompleksitas eksponensial atau polinomial tinggi (misalnya `O(n!)`, `O(2^n)`, atau `O(n^k)`).
- **Mudah diimplementasikan**: karena hanya mengikuti definisi masalah tanpa memerlukan algoritma kompleks.
- **Bergantung pada batasan masalah**: seringkali hanya layak digunakan apabila ukuran input (_constraints_) kecil.

---

## Contoh Kasus

1. **Permutasi dan Kombinasi**

   - Mencoba semua urutan (permutasi) atau subset (kombinasi) dari sebuah himpunan.
   - Contoh: mencari urutan kota terbaik dalam masalah _Travelling Salesman Problem (TSP)_ untuk `n ≤ 10`.

2. **Pencarian Subset**

   - Memeriksa semua kemungkinan subset dari sebuah array untuk memenuhi suatu kondisi (misalnya, _Subset Sum Problem_).
   - Kompleksitas: `O(2^n)`.

3. **Pencarian Pola (Pattern Matching)**
   - Mengecek setiap posisi string sebagai kandidat kecocokan pola.
   - Kompleksitas: `O(n * m)` untuk string sepanjang `n` dan pola sepanjang `m`.

---

## Analisis Kompleksitas

- Kompleksitas waktu pada _brute force_ biasanya sangat tinggi. Oleh karena itu, **analisis constraint** sangat penting:

  | Ukuran Input (n) | Kompleksitas yang Masih Bisa Diterima  |
  | ---------------- | -------------------------------------- |
  | `n ≤ 10`         | `O(n!)` masih mungkin                  |
  | `n ≤ 20`         | `O(2^n)` kadang masih diterima         |
  | `n ≤ 1000`       | `O(n^2)` bisa diterapkan               |
  | `n ≤ 10^5`       | biasanya perlu `O(n log n)` atau lebih |

---

## Peran dalam Kompetisi

- **Baseline solution**: digunakan sebagai solusi awal untuk menguji kebenaran implementasi.
- **Checker / Validator**: dipakai untuk membuat solusi pembanding terhadap algoritma yang lebih cepat.
- **Latihan berpikir sistematis**: membantu peserta memahami struktur masalah sebelum beralih ke optimisasi.

---

## Strategi Penggunaan Efektif

- Batasi ruang pencarian dengan **pruning** (memotong cabang pencarian yang jelas tidak mungkin menghasilkan solusi optimal).
- Gunakan **backtracking** untuk mempercepat pencarian solusi dibanding enumerasi buta.
- Kombinasikan dengan teknik lain (misalnya _meet in the middle_ atau _bitmasking_) agar lebih efisien.

---

## Ringkasan

_Brute force_ adalah metode mencoba semua kemungkinan solusi. Walaupun tidak efisien, metode ini **sangat penting** dalam pemrograman kompetitif sebagai:

- dasar pemahaman masalah,
- solusi darurat untuk input kecil,
- pembanding algoritma canggih.

## Contoh kasus

Two Sum Problem: https://meheedihasaan.medium.com/solving-the-two-sum-problem-brute-force-and-hash-map-approaches-5bc3b77cb5ba
