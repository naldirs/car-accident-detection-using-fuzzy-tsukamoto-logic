# Pendeteksi Kecelakaan Mobil menggunakan Logika Fuzzy Tsukamoto
Ini adalah kode program dari tugas akhir skripsi.

- Himpunan Fuzzy Fungsi Input

| Variabel | Satuan | Semesta Pembicaraan | Nama Himpunan |
|----------|--------|---------------------|---------------|
| Akselerometer(X) | Gravitasi(g)| ≤-4 | Tinggi(n)
| | | -4 – 4	| Rendah |
| | | ≥ 4	| Tinggi(p) |
| Akselerometer (Y) | Gravitasi(g) | ≤-8 |	Sangat Tinggi(n) |
| | | -8 – 0 |	Tinggi(n)
| | | -4 – 4 |	Rendah
| | | 0 – 8	| Tinggi(p)
| | | ≥ 8	| Sangat Tinggi(p)
| Getaran	 | Getaran | 0 – 5000 |	Rendah |
| |	|	≥ 5000 |	Tinggi |

- Himpunan Fuzzy Fungsi Output

| Variabel | Semesta Pembicaraan | Nama Himpunan |
|----------|---------------------|---------------|
| Status |	0 – 3 |	Normal |
| |	3 – 6 |	Tabrakan |
| |	6 – 9 |	Terguling |

- Aturan

| Ke- | Akselerometer(X) | Akselerometer(Y) | Getaran | Status |
|-----|------------------|------------------|---------|--------|
| 1	| Tinggi(n)	| SangatTinggi(n)	| Tinggi	| Terguling |
| 2	| Tinggi(n)	| SangatTinggi(n)	| Rendah	| Normal |
| 3	| Tinggi(n)	| Tinggi(n)	| Tinggi	| Tabrakan |
| 4	| Tinggi(n)	| Tinggi(n)	| Rendah	| Normal	 |
| 5	| Tinggi(n)	| Rendah	| Tinggi	| Tabrakan |
| 6	| Tinggi(n)	| Rendah	| Rendah	| Normal |
| 7	| Tinggi(n)	| Tinggi(p)	| Tinggi	| Tabrakan |
| 8	| Tinggi(n)	| Tinggi(p)	| Rendah	| Normal |
| 9	| Tinggi(n)	| SangatTinggi(p)	| Tinggi	| Terguling |
| 10 | Tinggi(n)	| SangatTinggi(p)	| Rendah	| Normal |
| 11 | Rendah	| SangatTinggi(n)	| Tinggi	| Terguling |
| 12 | Rendah	| SangatTinggi(n)	| Rendah	| Normal |
| 13 | Rendah	| Tinggi(n)	| Tinggi	| Tabrakan |
| 14 | Rendah	| Tinggi(n)	| Rendah	| Normal |
| 15 | Rendah	| Rendah	| Tinggi	| Normal |
| 16 | Rendah	| Rendah	| Rendah	| Normal |
| 17 | Rendah	| Tinggi(p)	| Tinggi	| Tabrakan |
| 18 | Rendah	| Tinggi(p)	| Rendah	| Normal |
| 19 | Rendah	| SangatTinggi(p)	| Tinggi	| Terguling |
| 20 | Rendah	| SangatTinggi(p)	| Rendah	| Normal |
| 21 | Tinggi(p)	| SangatTinggi(n)	| Tinggi	| Terguling |
| 22 | Tinggi(p)	| SangatTinggi(n)	| Rendah	| Normal |
| 23 | Tinggi(p)	| Tinggi(n)	| Tinggi	| Tabrakan |
| 24 | Tinggi(p)	| Tinggi(n)	| Rendah	| Normal |
| 25 | Tinggi(p)	| Rendah	| Tinggi	| Tabrakan |
| 26 | Tinggi(p)	| Rendah	| Rendah	| Normal |
| 27 | Tinggi(p)	| Tinggi(p)	| Tinggi	| Tabrakan |
| 28 | Tinggi(p)	| Tinggi(p)	| Rendah	| Normal |
| 29 | Tinggi(p)	| SangatTinggi(p)	|Tinggi	| Terguling |
| 30 | Tinggi(p)	| SangatTinggi(p)	|Rendah	| Normal |

# Wiring Diagram
![skripsi sensor pendeteksi fix 3_bb](https://user-images.githubusercontent.com/74083958/193984130-8657b2d0-5125-4660-97df-59785a902755.png)
Part:
1. Sensor getar SW-420
2. Akselerometer ADXL345
3. Buzzer passive
4. GSM SIM900A
5. GPS Ublox NEO-6M

Note:
- yang digunakan di projek ini WEMOS D1 Mini ver 3.1.0
- tambahkan step up di modul gsm (kadang gsmnya hidup-mati kalau disambung langsung ke seperti di diagram)
