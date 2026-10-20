
# HỆ THỐNG QUẢN LÝ NHẬP XUẤT HÀNG HÓA

## 1. Giới thiệu
Hệ thống quản lý nhập xuất hàng hóa là một chương trình được viết bằng ngôn ngữ C, nhằm hỗ trợ quản lý thông tin sản phẩm trong kho. Chương trình giúp người dùng thực hiện các thao tác thêm, xem, cập nhật, xóa sản phẩm và quản lý quá trình nhập, xuất hàng hóa.

## 2. Chức năng chính
- Thêm sản phẩm mới vào danh sách.
- Hiển thị danh sách sản phẩm.
- Cập nhật thông tin sản phẩm.
- Xóa sản phẩm khỏi danh sách.
- Nhập hàng vào kho.
- Xuất hàng khỏi kho.
- Quản lý thông tin sản phẩm bằng `struct`.
- Giao diện menu cho phép người dùng lựa chọn chức năng.

## 3. Công nghệ sử dụng
- Ngôn ngữ lập trình: C.
- Trình biên dịch: Dev C
- Môi trường phát triển: Dev C

## 4. Cấu trúc dự án
```text
Warehouse-Inventory-Management-System/
├── main.c
├── README.md
└── .dev C/
```

## 5. Yêu cầu hệ thống
Để chạy chương trình, cần chuẩn bị:
- Visual Studio Code.
- Extension C/C++ của Microsoft.
- Trình biên dịch GCC đã được cài đặt và cấu hình trong PATH.

## 6. Hướng dẫn cài đặt và chạy chương trình

### Bước 1: Mở thư mục dự án
Mở thư mục chứa mã nguồn bằng Visual Studio Code.

### Bước 2: Biên dịch chương trình
Mở Terminal tại thư mục dự án và chạy lệnh:

```bash
gcc main.c -o warehouse
```

### Bước 3: Chạy chương trình

Trên Windows:

```bash
.\warehouse.exe
```

Trên Linux hoặc macOS:

```bash
./warehouse
```

## 7. Hướng dẫn sử dụng
1. Khởi chạy chương trình.
2. Chọn chức năng tương ứng trong menu.
3. Nhập thông tin sản phẩm theo yêu cầu.
4. Thực hiện các thao tác quản lý hàng hóa.
5. Chọn chức năng thoát để kết thúc chương trình.

## 8. Cấu trúc dữ liệu
Mỗi sản phẩm có thể bao gồm các thông tin:
- Mã sản phẩm.
- Tên sản phẩm.
- Số lượng.
- Đơn giá.

## 9. Mục tiêu dự án
- Vận dụng kiến thức cơ bản về lập trình C.
- Thực hành sử dụng `struct`, mảng, hàm và vòng lặp.
- Xây dựng các chức năng CRUD: thêm, xem, sửa và xóa dữ liệu.
- Làm quen với quy trình quản lý nhập xuất hàng hóa.

## 10. Hướng phát triển
- Lưu dữ liệu vào tệp để sử dụng lại sau khi tắt chương trình.
- Bổ sung chức năng tìm kiếm sản phẩm.
- Sắp xếp danh sách sản phẩm.
- Kiểm tra dữ liệu đầu vào và xử lý lỗi.
- Thống kê số lượng hàng tồn kho và lịch sử nhập xuất.

## 11. Tác giả
- Bùi Đăng Khôi (NHÓM TRƯỞNG) - Quản lí toàn bộ dự án
- Nguyễn Tuấn - Hoàn Thành giai đoạn then chốt
