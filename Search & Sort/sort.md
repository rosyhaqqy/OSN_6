# Algoritma Sorting

## Bubble Sort

Algoritma **Bubble Sort** merupakan proses pengurutan yang secara berangsur-angsur berpindah ke posisi yang tepat, karena itulah dinamakan Bubble yang artinya gelembung. Algoritma ini akan mengurutkan data dari yang terbesar ke yang terkecil (_ascending_) atau sebaliknya (_descending_).

Secara sederhana, **algoritma Bubble Sort adalah pengurutan dengan cara pertukaran data dengan data di sebelahnya secara terus menerus hingga tidak ada lagi perubahan**. Bubble Sort adalah metode _sorting_ yang sederhana, namun merupakan metode pengurutan yang tidak efisien karena ketika mengurutkan data yang sangat besar akan sangat lambat prosesnya.

Sifat algoritma Bubble Sort adalah sebagai berikut:

1. Jumlah iterasi sama dengan banyaknya bilangan dikurang 1.
2. Di setiap iterasi, jumlah pertukaran bilangannya sama dengan jumlah banyaknya bilangan.
3. Dalam algoritma Bubble Sort, meskipun deretan bilangan tersebut sudah terurut, proses _sorting_ akan tetap dilakukan.
4. Tidak ada perbedaan cara yang berarti untuk teknik algoritma Bubble Sort _ascending_ dan _descending_.

![bubble](https://github.com/Algoritma-dan-Pemrograman-ITS/DasarPemrograman/raw/master/img/bubblesort.PNG)

**Implementasi Bubble Sort**:

```c
void swap(int *xp, int *yp) {
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

void bubbleSort(int arr[], int n) {
   int i, j, swapped;        // dioptimasi dengan bool `swapped`:
   for (i = 0; i < n-1; i++) {
      swapped = 0;
      for (j = 0; j < n-i-1; j++) {
         if (arr[j] > arr[j+1]) {
            swap(&arr[j], &arr[j+1]);
            swapped = 1;
         }
      }
      if (swapped == 0)
         break;
   }
}
```

## Insertion Sort

**Insertion Sort** merupakan salah satu jenis sort yang mirip seperti saat kalian melakukan pengurutan kartu remi di tangan. Algoritma ini dua elemen data pertama, mengurutkannya, kemudian mengecek elemen data berikutnya satu persatu dan membandingkannya dengan elemen data yang telah diurutkan. Ide dasar dari algoritma ini adalah mencari tempat yang “tepat” untuk setiap elemen array.

Secara umum, langkah-langkah algoritma insertion sort adalah sebagai berikut.

1. Ambil elemen dari array ke-i.
2. Taruh di urutan sebelumnya ( arr[ …i-1] ) yang telah diurutkan di tempat yang sesuai.

![insertion](https://miro.medium.com/1*5WXRN62ddiM_Gcf4GDdCZg.gif)

**Implementasi Insertion Sort**:

```c
void insertionSort(int arr[]. int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
      key = arr[i];
      j = i-1;

      while (j >= 0 && arr[j] > key) {
         arr[j+1] = arr[j];
         j = j-1;
      }
      arr[j+1] = key;
   }
}
```

## Merge Sort

**Merge Sort** adalah algoritma sorting yang dilakukan secara rekursif dengan membagi array menjadi 2 bagian, melakukan merge-sort pada 2 bagian tersebut, lalu melakukan merge pada kedua array tersebut.

Secara formal, proses merge sort dapat dituliskan sebagai berikut:

```
Sort(L,R):

If(R > L):

  1. M = (L + R) / 2
  2. Sort(L,M)
  3. Sort(M + 1,R)
  4. Merge(L,R)
```

**Penjelasan lebih detail dan contoh implementasi**: [https://www.interviewbit.com/tutorial/merge-sort-algorithm/](https://www.interviewbit.com/tutorial/merge-sort-algorithm/)

Contoh alur rekursi untuk Merge Sort pada array dengan 8 elemen:

![merge](https://github.com/Algoritma-dan-Pemrograman-ITS/DasarPemrograman/raw/master/img/mergesort.PNG)

Pada setiap tahap, akan dilakukan proses _merge_. Proses _merge_ dilakukan dengan mengurutkan secara naif dengan memanfaatkan fakta bahwa kedua array hasil partisi sudah terurut.

Karena setiap kali rekursi ukuran array menjadi setengahnya, maka kedalaman maksimal rekursi adalah **log2(N)**.

Karena di setiap tahap rekursi total proses _merge_ yang dilakukan ada sebanyak N, maka total kompleksitas pengurutan menggunakan Merge Sort adalah **N log2(N)**.

## Quick Sort

Mirip seperti Merge Sort, **Quick Sort** adalah algoritma sorting yang dilakukan secara rekursif dan menggunakan prinsip Divide and Conquer.

Secara formal, proses Quick Sort dapat dituliskan sebagai berikut:

```
Sort(L,R)

If (R > L):

  1. M = Partisi(L,R). //M adalah index yang posisinya sudah fix.
  2. Sort(L,M - 1)
  3. Sort(M + 1,R)
```

Sedangkan untuk bagian partisi dapat dituliskan sebagai berikut:

```
Partisi(L,R):

  1. Pivot = arr[L]
  2. storeIndex = L + 1
  3. Iterasi i dari L + 1 sampai R, jika arr[i] < pivot, lanjut ke step 4.
  4. swap(arr[i],arr[storeIndex])
  5. storeIndex = storeIndex + 1
  6. Jika i masih kurang dari atau sama dengan R, kembali ke step 3. Jika tidak, lanjut ke step 7
  7. swap(arr[L],arr[storeIndex - 1])
  8. Return storeIndex - 1
```

Terkait proses partisi, terdapat berbagai cara dalam pemilihan pivot. Bisa saja menggunakan data paling kiri (seperti di atas), data paling kanan, atau data _random_, tergantung implementasi masing-masing.

**Penjelasan lebih detail dan contoh implementasi**: [https://www.interviewbit.com/tutorial/quicksort-algorithm/](https://www.interviewbit.com/tutorial/quicksort-algorithm/)

---

Jika dirata-rata, total kompleksitas dari Quick Sort adalah **O(N log2(N))**. Meskipun begitu, kompleksitas terburuk dari Quick Sort adalah **O(N2)**. Proses partisi dengan cara memilih index random sebagai pivot terbukti cukup efisien untuk membuat **Quick Sort** dilakukan dalam kompleksitas **O(N log2(N))**.

Merge Sort dan Quick Sort adalah algoritma _sorting_ yang paling umum dipakai karena memiliki efisiensi yang sangat baik meskipun terdapat algoritma yang lebih efisien seperti Radix Sort. Sedangkan untuk Bubble Sort dan Insertion Sort hampir tidak pernah dipakai. Algoritma tersebut sebaiknya hanya dipelajari untuk pengetahuan saja.

Di antara Merge Sort dan Quick Sort, penggunaan Quick Sort sering kali lebih dipilih dikarenakan Quick Sort adalah algoritma pengurutan yang bersifat _in-place_ yang berarti tidak membutuhkan memori tambahan dalam implementasinya, tidak seperti Merge Sort yang membutuhkan memori tambahan dengan ukuran yang linear terhadap array yang akan di-_sort_.
