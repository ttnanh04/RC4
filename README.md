Đề tài: Mã hoá chuỗi thông tin sử dụng thuật toán RC4
Cấu trúc thư mục
RC4/
├── rc4_encrypt/
│   ├── main.c
│   ├── rc4_encrypt.c
│   ├── rc4_encrypt.h
│   └── encrypt.exe       ← file chạy sau khi build
│
├── rc4_decrypt/
    ├── main.c
    ├── rc4_decrypt.c
    ├── rc4_decrypt.h    
    ├── decrypt.exe       ← file chạy sau khi build
    └── cipher.bin       ← file nhị phân chứa ciphertext
            
 1. Giới thiệu
Chương trình hiện thực thuật toán RC4 bằng ngôn ngữ C, bao gồm:
RC4 Encryption: mã hóa chuỗi văn bản thành dữ liệu nhị phân.
RC4 Decryption: đọc file mã hóa (cipher.bin) và giải mã lại về plaintext gốc.
RC4 là thuật toán mã hóa dòng (stream cipher) hoạt động bằng cách tạo ra một keystream được XOR với dữ liệu gốc.

2. Nguyên lý hoạt động
RC4 gồm 2 giai đoạn:
- Giai đoạn 1: Khởi tạo (rc4_init)
Tạo mảng hoán vị S[256] từ 0 đến 255.
Trộn S dựa trên khóa bí mật (KEY).
- Giai đoạn 2: Sinh keystream (rc4_generate)
Sinh từng byte của keystream bằng hoán vị của S.
XOR từng byte của plaintext/ciphertext với keystream → thu được output.
Vì RC4 là đối xứng, nên:
Mã hóa và giải mã dùng cùng một hàm rc4_generate.

3. Biên dịch (Compile)
Yêu cầu:
Đã cài GCC (MinGW nếu trên Windows).
Có sẵn terminal (cmd hoặc PowerShell).
- Mã hóa
Vào thư mục: cd rc4_encrypt
Biên dịch: gcc main.c rc4_encrypt.c -o encrypt.exe
Chạy: encrypt.exe

Kết quả hiển thị ví dụ:

Plaintext: Hanoi University of Science and Technology
Ciphertext (hex): BA 0F CE AF E5 E8 85 C2 12 27 31 3A ...
Đã ghi ciphertext vào file cipher.bin
- Giải mã
Vào thư mục: cd rc4_decrypt
Biên dịch: gcc main.c rc4_decrypt.c -o decrypt.exe
Chạy: decrypt.exe
Kết quả:

Đã đọc ciphertext từ file cipher.bin
Plaintext: Hanoi University of Science and Technology

4. Cấu hình khóa
Trong cả rc4_encrypt.h và rc4_decrypt.h đều có khai báo:
#define KEY "HUST2025"
#define KEY_LEN 8

->  Nếu muốn đổi khóa, chỉ cần thay chuỗi trong KEY ở cả hai file header.

5. Mô tả các file chính
File	Mô tả
main.c	Xử lý nhập/xuất, gọi hàm RC4, ghi/đọc file.
rc4_encrypt.c / rc4_decrypt.c	Hiện thực hàm rc4_init và rc4_generate.
rc4_encrypt.h / rc4_decrypt.h	Khai báo hàm và định nghĩa khóa (KEY, KEY_LEN).
cipher.bin	File nhị phân chứa dữ liệu đã mã hóa.
6. Bộ test vecto
KEY: HUST2025
Mã hóa:
Plaintext: Hanoi University of Science and Technology
Ciphertext (hex):BA 0F CE AF E5 E8 85 C2 12 27 31 3A 9A B1 F2 27 F6 75 3C DF 66 96 D4 ED B4 8F 5E 59 5F C0 04 6E 9A DA E7 5A AE D0 65 A8 DB A6
Giải mã:
Đã đọc ciphertext từ file cipher.bin
Plaintext: Hanoi University of Science and Technology
