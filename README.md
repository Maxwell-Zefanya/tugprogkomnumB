# Tugas Pemgoraman B Komputasi Numerik 01
### Made by Kelompok 13
Anggota:  
- Anthonius Hendhy Wirawan - 2306161795
- Kelvin Ferrel Tjoe - 2306205393
- Maxwell Zefanya Ginting - 2306221200
- Musyaffa Iman Supriadi - 2306208464
## Nama Program: Heat Integration Calculator
Program ini dibuat untuk mencari kalori yang dibutuhkan untuk meningkatkan suhu sebuah benda dengan menggunakan Simpson's 1/3 Rule, dan memberikan step-by-step perhitungannya.

dalam program ini, ditentukan terlebih dahulu massa, suhu awal, dan suhu akhir untuk melakukan perhitungan. setelah itu dilakukan kapasitas kalor dengan fungsi heat_capacity(). program akan menampilkan kapasitas kalor dari rentang suhu yang dibagi dalam 7 titik (perbedaan suhu dibagi menjadi 6 segmen).

setelah itu, program akan melakukan perhitungan dengan menggunakan metode Simpson's 1/3 Rule dengan fungsi simpson_rule(). dimana rentang suhu (perbedaan suhu awal dan akhir) akan dipecah menjadi beberapa segmen yang jumlahnya genap. Nilai integral dihitung menggunakan nilai dari heat_capacity sebagai parameter. program lalu akan mencetak hasil perhitungan fungsi tersebut berdasarkan jumlah segmennya (6, 12, 24, 48 segmen).

kemudian, program akan memberikan step-by-step perhitungan menggunakan Simpson's 1/3 Rule yang membagi rentang suhu menjadi 6 segmen sebagai pembuktian. dalam pembuktian ini hasil kali kapasitas kalor per segmen dengan koefisiennya akan dijumlah, lalu diintegralkan (dikali panjang segmen, lalu dibagi 3). jumlah kalor ditemukan dengan mengkalikan hasil integrasi dengan massa yang ditentukan di awal.

contoh output:

![image](https://github.com/user-attachments/assets/d9a052ff-bfa3-4e18-a9e8-d00accbc6082)
![image](https://github.com/user-attachments/assets/ff3c04f8-dcc9-4987-a565-9c6f96962e00)
