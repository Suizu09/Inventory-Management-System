
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define LOW_STOCK 5

typedef struct {
    char ma[20];
    char ten[50];
    double gia;
    int soLuong;
} SanPham;

SanPham kho[MAX];
int n = 0;

void nhapChuoi(char *s, int size) {
    fgets(s, size, stdin);
    s[strcspn(s, "\n")] = '\0';
}

int nhapSoNguyen(const char *thongBao) {
    char buf[100], *end;
    long x;

    while (1) {
        printf("%s", thongBao);
        nhapChuoi(buf, sizeof(buf));
        x = strtol(buf, &end, 10);

        while (*end == ' ' || *end == '\t')
            end++;

        if (buf[0] != '\0' && *end == '\0'
            && end != buf && x >= 0 && x <= 1000000000L)
            return (int)x;

        printf("Du lieu khong hop le!\n");
    }
}

double nhapGia(void) {
    char buf[100], *end;
    double x;

    while (1) {
        printf("Nhap gia: ");
        nhapChuoi(buf, sizeof(buf));
        x = strtod(buf, &end);

        while (*end == ' ' || *end == '\t')
            end++;

        if (buf[0] != '\0' && *end == '\0'
            && end != buf && x >= 0)
            return x;

        printf("Gia khong hop le!\n");
    }
}

int timTheoMa(const char *ma) {
    for (int i = 0; i < n; i++) {
        if (strcmp(kho[i].ma, ma) == 0)
            return i;
    }
    return -1;
}

void hienThi(const SanPham *sp) {
    printf("%-12s %-25s %12.2f %8d\n",
           sp->ma, sp->ten, sp->gia, sp->soLuong);
}

void themSanPham(void) {
    if (n >= MAX) {
        printf("Kho da day!\n");
        return;
    }

    SanPham sp;

    printf("Nhap ma san pham: ");
    nhapChuoi(sp.ma, sizeof(sp.ma));

    if (strlen(sp.ma) == 0 || timTheoMa(sp.ma) != -1) {
        printf("Ma rong hoac da ton tai!\n");
        return;
    }

    printf("Nhap ten san pham: ");
    nhapChuoi(sp.ten, sizeof(sp.ten));

    if (strlen(sp.ten) == 0) {
        printf("Ten khong duoc de trong!\n");
        return;
    }

    sp.gia = nhapGia();
    sp.soLuong = nhapSoNguyen("Nhap so luong: ");

    kho[n++] = sp;
    printf("Them san pham thanh cong!\n");
}

void xemDanhSach(void) {
    if (n == 0) {
        printf("Kho chua co san pham.\n");
        return;
    }

    printf("\n%-12s %-25s %12s %8s\n",
           "Ma SP", "Ten san pham", "Gia", "So luong");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
        hienThi(&kho[i]);
}

void timSanPham(void) {
    char tuKhoa[50];
    int timThay = 0;

    printf("Nhap ma hoac ten can tim: ");
    nhapChuoi(tuKhoa, sizeof(tuKhoa));

    for (int i = 0; i < n; i++) {
        if (strcmp(kho[i].ma, tuKhoa) == 0 ||
            strstr(kho[i].ten, tuKhoa) != NULL) {
            hienThi(&kho[i]);
            timThay = 1;
        }
    }

    if (!timThay)
        printf("Khong tim thay san pham!\n");
}

void suaSanPham(void) {
    char ma[20];
    printf("Nhap ma san pham can sua: ");
    nhapChuoi(ma, sizeof(ma));

    int i = timTheoMa(ma);
    if (i == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    printf("Nhap ten moi: ");
    nhapChuoi(kho[i].ten, sizeof(kho[i].ten));
    kho[i].gia = nhapGia();
    kho[i].soLuong = nhapSoNguyen("Nhap so luong moi: ");

    printf("Cap nhat thanh cong!\n");
}

void xoaSanPham(void) {
    char ma[20];
    printf("Nhap ma san pham can xoa: ");
    nhapChuoi(ma, sizeof(ma));

    int i = timTheoMa(ma);
    if (i == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    for (int j = i; j < n - 1; j++)
        kho[j] = kho[j + 1];

    n--;
    printf("Xoa san pham thanh cong!\n");
}

void nhapKho(void) {
    char ma[20];
    printf("Nhap ma san pham: ");
    nhapChuoi(ma, sizeof(ma));

    int i = timTheoMa(ma);
    if (i == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    int sl = nhapSoNguyen("So luong nhap them: ");
    if (sl > 1000000000 - kho[i].soLuong) {
        printf("So luong vuot gioi han!\n");
        return;
    }

    kho[i].soLuong += sl;
    printf("Nhap kho thanh cong!\n");
}

void xuatKho(void) {
    char ma[20];
    printf("Nhap ma san pham: ");
    nhapChuoi(ma, sizeof(ma));

    int i = timTheoMa(ma);
    if (i == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    int sl = nhapSoNguyen("So luong can xuat: ");

    if (sl > kho[i].soLuong) {
        printf("Khong du hang trong kho!\n");
        return;
    }

    kho[i].soLuong -= sl;
    printf("Xuat kho thanh cong!\n");
}

void thongKe(void) {
    long long tongSoLuong = 0;
    double tongGiaTri = 0;

    printf("\n--- SAN PHAM SAP HET ---\n");
    int coHangThap = 0;

    for (int i = 0; i < n; i++) {
        tongSoLuong += kho[i].soLuong;
        tongGiaTri += kho[i].gia * kho[i].soLuong;

        if (kho[i].soLuong <= LOW_STOCK) {
            hienThi(&kho[i]);
            coHangThap = 1;
        }
    }

    if (!coHangThap)
        printf("Khong co san pham nao sap het.\n");

    printf("\nTong mat hang: %d\n", n);
    printf("Tong so luong ton: %lld\n", tongSoLuong);
    printf("Tong gia tri ton kho: %.2f\n", tongGiaTri);
}

int main(void) {
    int chon;

    do {
        printf("\n========== QUAN LY KHO ==========\n");
        printf("1. Them san pham\n");
        printf("2. Xem danh sach\n");
        printf("3. Tim kiem san pham\n");
        printf("4. Sua san pham\n");
        printf("5. Xoa san pham\n");
        printf("6. Nhap kho\n");
        printf("7. Xuat kho\n");
        printf("8. Thong ke va canh bao\n");
        printf("0. Thoat\n");

        chon = nhapSoNguyen("Nhap lua chon: ");

        switch (chon) {
            case 1: themSanPham(); break;
            case 2: xemDanhSach(); break;
            case 3: timSanPham(); break;
            case 4: suaSanPham(); break;
            case 5: xoaSanPham(); break;
            case 6: nhapKho(); break;
            case 7: xuatKho(); break;
            case 8: thongKe(); break;
            case 0: printf("Ket thuc chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);

    return 0;
}
