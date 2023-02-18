# Car Accident Detection Using Fuzzy Tsukamoto Logic
Pendeteksi Kecelakaan Mobil menggunakan Logika Fuzzy Tsukamoto
Lampiran perancangan dan kode program dari tugas akhir skripsi.

## Design Fuzzy

### Membership Fuzzy Input Sets

#### Akselerometer(X) Membership
<img src="https://user-images.githubusercontent.com/74083958/219872555-daa4794e-1bd7-43dc-bed6-81d626db7d05.png" width="450" height="250">
- xTinggin {-4, 0} - xRendah {-4, 0, 4} - xTinggip {0, 4} 


#### Akslerometer(Y) Membership
<img src="https://user-images.githubusercontent.com/74083958/219873821-dc252ef2-d0d9-4e90-bbc6-e96308fb62f0.png" width="450" height="250">
- ySangatTinggin {-8, -4} - yTinggin {-8, -4, 0} - yRendah {-4, 0, 4} - yTinggip {0, 4, 8} - ySangatTinggip {4, 8}

#### Getaran Membership
<img src="https://user-images.githubusercontent.com/74083958/219874331-a14afffb-c24c-4235-8392-4fa6dec275f2.png" width="450" height="250">
- gRendah {0, 5000} - gTinggi {5000, 0}


### Membership Fuzzy Output

| Variabel | Semesta Pembicaraan | Nama Himpunan |
|----------|---------------------|---------------|
| Status |	0 – 3 |	Normal |
| |	3 – 6 |	Tabrakan |
| |	6 – 9 |	Terguling |

### Rules

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

## Flowchart
<img src="https://user-images.githubusercontent.com/74083958/219877315-fb5eb901-f4a3-410d-a6f9-3c91789d5304.png" width="750" height="550">

## Wiring Diagram
<img src="https://user-images.githubusercontent.com/74083958/193984130-8657b2d0-5125-4660-97df-59785a902755.png" >
Part:

1. Vibration Sensor SW-420 for detect vibration (getaran) from car
2. Accelerometer ADXL345 for detect collision direction 
3. Buzzer passive
4. GSM SIM900A
5. GPS Ublox NEO-6M

Note:
- im using WEMOS D1 Mini ver 3.1.0 in this project
- i recommend to add DC to DC step up module, because gsm modul cant turn on if i using power from my laptop, but if i using from powerbank or adapter it can turn on

## Results and Documentation
### Overall design
<img src="https://user-images.githubusercontent.com/74083958/206363446-bcba1f2c-aae3-4c83-97a3-a2459413a16b.PNG">

### Serial Monitor Output
<img src="https://user-images.githubusercontent.com/74083958/219877685-c8f61e7d-21f5-4bff-9290-9c06ba7e65b6.PNG" width="750" height="350">

### Result reciving sms
<img src="https://user-images.githubusercontent.com/74083958/206363499-45680fda-e81e-42a2-b97c-446a1697cb20.jpg" width="450" height="550">

1. first message if the car crashes
2. if the car rolls over

### Data collection and testing documentation
1. Collecting data for crashes and roll over using RC 1:16
<img src="https://user-images.githubusercontent.com/74083958/206364580-7a3126a6-1683-4181-8b67-284e4206f742.JPG" width="850" height="450">
2. Testing in real car for normal use
<img src="https://user-images.githubusercontent.com/74083958/206368583-fa8326c0-80e7-42ce-b5a1-ebd5f41d4930.jpg" width="850" height="550">

