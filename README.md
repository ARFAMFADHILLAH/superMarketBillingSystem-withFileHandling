🔧 Struktur Utama Program
1. Class Bill
Digunakan untuk merepresentasikan satu item. Memiliki:

Private Members:

Item (nama barang)

Rate (harga satuan)

Quantity (jumlah stok)

Public Methods:

Setters: setItem(), setRate(), setQuant()

Getters: getItem(), getRate(), getQuant()

2. Fungsi addItem(Bill b)
Digunakan untuk menambah item ke dalam stok dan menyimpannya ke file.

Alur:
Menampilkan pilihan: 1 (Add), 2 (Close).

Jika Add dipilih:

Minta input nama, harga, dan jumlah.

Simpan ke file D:/Bill.txt dengan format:

yaml
Copy
Edit
NamaItem : Harga : Jumlah
Jika Close dipilih:

Keluar dari loop dan kembali ke menu utama.

3. Fungsi PrintBill(Bill b)
Digunakan untuk memproses pembelian dan mencetak tagihan.

Alur:
Menampilkan pilihan: 1 (Add Bill), 2 (Close Session).

Jika Add Bill dipilih:

Masukkan nama item dan jumlah yang ingin dibeli.

Buka D:/Bill.txt, cari item tersebut.

Jika ditemukan:

Cek apakah stok cukup.

Hitung total harga.

Tampilkan rincian item.

Kurangi stok, simpan ke file temporary Bill_Temp.txt.

Ganti file lama dengan yang baru.

Jika Close Session dipilih:

Menampilkan total tagihan semua item.

4. main()
Adalah entry point program:

Menampilkan menu utama:

markdown
Copy
Edit
1. Add Item
2. Print Bill
3. Exit
Pilihan akan memanggil addItem(), PrintBill(), atau keluar.

