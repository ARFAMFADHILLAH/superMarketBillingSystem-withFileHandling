# 🧾 Supermarket Billing System

Program ini adalah sistem billing sederhana berbasis **C++** yang digunakan untuk mengelola stok dan transaksi di sebuah supermarket. Program ini berjalan di **Windows** dan menyimpan data menggunakan file teks.

---

## 📌 Fitur

- Menambahkan item ke dalam stok.
- Menyimpan data item ke file `Bill.txt`.
- Melayani proses pembelian dari pelanggan.
- Menghitung total tagihan.
- Memperbarui stok setelah pembelian.
- Tampilan interaktif melalui terminal.

---

## 🏗️ Struktur Program

### 1. `class Bill`
Mewakili satu item barang dengan atribut:
- `Item`: Nama barang
- `Rate`: Harga per unit
- `Quantity`: Jumlah stok

**Metode:**
- Setter: `setItem()`, `setRate()`, `setQuant()`
- Getter: `getItem()`, `getRate()`, `getQuant()`

---

### 2. `addItem(Bill b)`

Digunakan untuk menambahkan item baru ke stok.

**Langkah-langkah:**
- Meminta input dari user: nama, harga, jumlah.
- Menyimpan data ke file `D:/Bill.txt` dalam format:


---

### 3. `PrintBill(Bill b)`

Digunakan untuk mencetak tagihan belanja pelanggan.

**Langkah-langkah:**
- User memasukkan nama barang dan jumlah yang ingin dibeli.
- Program mencari item di file `Bill.txt`.
- Jika ditemukan dan stok mencukupi:
- Menghitung total.
- Menampilkan rincian pembelian.
- Mengurangi jumlah stok dan memperbarui file.
- Menyimpan hasil sementara di `Bill_Temp.txt` sebelum mengganti file utama.

---

### 4. `main()`

Program utama yang menampilkan menu:

```text
1. Add Item
2. Print Bill
3. Exit
