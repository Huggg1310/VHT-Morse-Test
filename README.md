# Morse Encoder / Decoder bằng C

Chương trình dòng lệnh viết bằng **ngôn ngữ C** dùng để **mã hóa (encode)** và **giải mã (decode)** văn bản sang **Morse code**.

Project gồm **2 phiên bản triển khai khác nhau** để so sánh cách viết và tối ưu code.

---

# Cấu trúc Project

```
morse_project
│
├── version_1
│   └── my_morse.c
│
├── version_2
│   └── my_morse.c
│
├── tests
│   └── test.c
│
├── data
│   ├── test_input.txt
│   ├── test_morse.txt
│   └── invalid.txt
│
└── README.md
```

---

# Chức năng

Chương trình có các chức năng:

* Mã hóa văn bản sang Morse
* Giải mã Morse sang văn bản
* Đọc dữ liệu từ file
* Ghi kết quả ra `output.txt`
* Hỗ trợ command line
* Có chương trình test tự động

---

# Biểu diễn Morse trong chương trình

Thay vì dùng ký hiệu truyền thống:

```
.  (dot)
-  (dash)
```

Chương trình sử dụng:

```
*   = dot
=== = dash
```

Ví dụ:

```
HELLO
```

sẽ được mã hóa thành

```
**** * *===** *===** =========
```

---

# Biên dịch chương trình

Biên dịch chương trình encoder / decoder:

```
gcc my_morse.c -o my_morse
```

Biên dịch chương trình test:

```
gcc test.c -o test
```

---

# Cách sử dụng

## 1. Encode (Mã hóa)

```
./my_morse -e input.txt
```

Ví dụ:

```
./my_morse -e data/test_input.txt
```

Kết quả sẽ được ghi vào:

```
output.txt
```

---

## 2. Decode (Giải mã)

```
./my_morse -d input.txt
```

Ví dụ:

```
./my_morse -d data/test_morse.txt
```

---

# Chương trình Test

Project có chương trình test tự động để kiểm tra cả **version 1 và version 2**.

Biên dịch:

```
gcc test.c -o test
```

Chạy test:

```
./test
```

Ví dụ kết quả:

```
--- TEST VERSION 1 ---
V1 Encode      : OK
V1 Decode      : OK
V1 Invalid     : OK

--- TEST VERSION 2 (Optimized) ---
V2 Encode      : OK
V2 Decode      : OK
V2 Invalid     : OK
```

---

# So sánh hai phiên bản

| Version   | Cách cài đặt          | Đặc điểm              |
| --------- | --------------------- | --------------------- |
| Version 1 | nhiều `if-else`       | code dài, khó mở rộng |
| Version 2 | lookup table + struct | code gọn, dễ bảo trì  |

Version 2 được tối ưu hơn vì sử dụng **bảng tra cứu (lookup table)**.

---

# Xử lý lỗi

Chương trình có thể phát hiện các lỗi:

* file không tồn tại
* sai tham số command line
* Morse code không hợp lệ

Ví dụ lỗi:

```
Invalid Morse sequence detected: ===***==
```

---

# Mục đích project

Project được viết để:

* luyện tập lập trình C
* làm quen với xử lý file
* học cách tổ chức project
* so sánh các cách triển khai thuật toán

---
