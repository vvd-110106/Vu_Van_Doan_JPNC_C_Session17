#include <stdio.h>
#include <stdlib.h>

void showMenu();
void nhapvaoSoPhanTu(int *arr, int *n);
void inSoChan(int *arr, int n);
void inSoNguyenTo(int *arr, int n);
void daoNguoc(int *arr, int n);
void sapXep(int *arr, int n);
void nhapvaTimKiem(int *arr, int n);

int main() {
    int *arr = NULL;
    int n = 0;
    int choice;

    do {
        showMenu();
        printf("---> Lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                nhapvaoSoPhanTu(arr, &n);
                break;
            case 2:
                inSoChan(arr, n);
                break;
            case 3:
                inSoNguyenTo(arr, n);
                break;
            case 4:
                daoNguoc(arr, n);
                break;
            case 5:
                sapXep(arr, n);
                break;
            case 6:
                nhapvaTimKiem(arr, n);
                break;
            case 7:
                printf("Thoat.\n");
                free(arr);
                return 0;
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    } while(choice != 7);

    return 0;
}

void showMenu() {
    printf("\n----------MENU----------\n");
    printf("1. Nhap vao so luong phan tu va cac phan tu\n");
    printf("2. In ra cac so chan cua mang\n");
    printf("3. In ra so nguyen to cua mang\n");
    printf("4. Dao nguoc mang\n");
    printf("5. Sap xep mang\n");
    printf("6. Nhap phan tu va tim kiem phan tu trong mang\n");
    printf("7. Thoat\n");
}

void nhapvaoSoPhanTu(int *arr, int *n) {
    printf("Nhap vao so luong phan tu: ");
    scanf("%d", n);

    arr = (int*) malloc(*n * sizeof(int));

    if (*n <= 0) {
        printf("So luong phan tu khong hop le.\n");
        return;
    }

    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inSoChan(int *arr, int n) {
    if (n == 0) {
        printf("Mang rong.....\n");
        return;
    }
    printf("Cac so chan trong mang: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d\t", arr[i]);
        }
    }
    printf("\n");
}

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void inSoNguyenTo(int *arr, int n) {
    if (n == 0) {
        printf("Mang rong.....\n");
        return;
    }
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d\t", arr[i]);
        }
    }
    printf("\n");
}

void daoNguoc(int *arr, int n) {
    if (n == 0) {
        printf("Mang rong.....\n");
        return;
    }
    printf("Mang dao nguoc: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void sapXep(int *arr, int n) {
    if (n == 0) {
        printf("Mang rong.....\n");
        return;
    }

    int choice;
    printf("\n1. Sap xep tang dan\n");
    printf("2. Sap xep giam dan\n");
    printf("---> Lua chon cua ban: ");
    scanf("%d", &choice);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((choice == 1 && arr[i] > arr[j]) || (choice == 2 && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void nhapvaTimKiem(int *arr, int n) {
    if (n == 0) {
        printf("Mang rong.....\n");
        return;
    }

    int x;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d co trong mang.\n", x);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Phan tu %d khong co trong mang.\n", x);
    }
}

