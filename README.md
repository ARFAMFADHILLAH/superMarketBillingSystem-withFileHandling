# 🧾 Supermarket Billing System (C++)

Program ini adalah aplikasi terminal sederhana untuk sistem kasir supermarket. Aplikasi ini memungkinkan Anda untuk:

- Menambahkan stok barang.
- Melayani pembelian pelanggan.
- Mencetak total tagihan.
- Mengelola data stok menggunakan file teks.

---

## 📦 Fitur

✅ Tambah data item baru (nama, harga, jumlah)  
✅ Simpan dan update stok otomatis ke file `Bill.txt`  
✅ Mencetak struk belanja pelanggan secara langsung di terminal  
✅ Validasi input untuk mencegah crash saat input tidak valid  
✅ Tampilan antarmuka teks sederhana berbasis menu

---

## 📁 Struktur File

- **`D:/Bill.txt`**  
  Menyimpan daftar item dan stok barang dalam format:
  NamaItem : Harga : Jumlah

- **`D:/Bill_Temp.txt`**  
File sementara untuk memperbarui stok setelah transaksi.

Contoh isi file:
Sabun : 5000 : 20
Roti : 7000 : 15


---

## 🚀 Cara Menggunakan

1. Kompilasi program menggunakan compiler C++:
   ```bash
   g++ -o billing billing.cpp
Jalankan program: billing.exe
Ikuti petunjuk menu:
1. Add Item      -> Menambahkan barang ke stok
2. Print Bill    -> Memproses belanja dan mencetak tagihan
3. Exit          -> Keluar dari aplikasi
   
💻 Persyaratan Sistem
Sistem operasi: Windows (karena menggunakan windows.h, Sleep(), dan system("cls"))

Compiler: GCC (MinGW) atau MSVC yang mendukung C++11 ke atas

Folder D:/ harus ada karena program menyimpan file di sana (atau Anda bisa ubah path di kode)
