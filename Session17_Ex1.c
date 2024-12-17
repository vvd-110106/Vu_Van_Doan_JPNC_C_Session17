#include<stdio.h>
#include<stdlib.h>

void showMenu();
void nhapMang();
void show();
void tinhDoDaiMang();
void tinhTongMang();
void hienThiMax();

int choice;
int *arr = NULL;
int n=0;
int main(){
	do{
	showMenu();
	switch(choice){
		case 1:
		    nhapMang();
			break;
		case 2:
			show();
			break;
		case 3:
			tinhDoDaiMang();
			break;
		case 4:
			tinhTongMang();
			break;
		case 5:
			hienThiMax();
			break;
		case 6:
			printf("Cam on ban da dung chuong trinh. \n");
			return 0;
	}
		
	}while(choice!=6);
	
	return 0;
}

void showMenu(){
	printf("\n----------MENU----------\n");
	printf(" 1.Nhap vao so phan tu va tung phan tu. \n");
	printf(" 2.Hien thi cac phan tu trong mang. \n");
	printf(" 3.Tinh do dai mang. \n");
	printf(" 4.Tinh tong cac phan tu trong mang. \n");
	printf(" 5.Hien thi cac phan tu lon nhat. \n");
	printf(" 6.Thoat chuong trinh. \n");
	printf("--->Lua chon cua ban la:  ");
	scanf("%d", &choice);
}

void nhapMang(){
	printf("Ban hay nhap vào so luong phan tu: ");
    scanf("%d", &n);
    
    arr = (int*) malloc(n * sizeof(int)); // Cong thuc
    
    if (n <= 0) {
        printf("So luong phan tu khong hop le...\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("Phan tu thu %d là: ", i + 1);
            scanf("%d", &arr[i]);
        }
    }
}

void show(){
	if(n==0){
		printf("Mang rong.....");
	}else{
		printf("So cac phan tu cua mang la: ");
		for(int i=0; i<n; i++){
			printf("%d\t", arr[i] );
		}
	}
}

void tinhDoDaiMang(){
	if(n==0){
		printf("Mang rong khong the tinh do dai........");
	}else{
		printf("Do dai cua mang la: %d", n);
	}
}

void tinhTongMang(){
	if(n==0){
		printf("Mang rong khong the tinh tong........");
	}else{
		int sum=0;
		for(int i=0; i<n; i++){
			sum += arr[i];
		}
		printf("Tong cac phan tu cua mang la: %d", sum);
	}
}

void hienThiMax(){
	if(n==0){
		printf("Mang rong khong co gia tri Max (GTLN)........");
	}else{
		int max=arr[0];
		int check=-1;
		for(int i=0; i<n; i++){
			if(max<arr[i]){
				max = arr[i];
				check=1;
			}
		}
		printf("Gia tri lon nhat cua mang la: %d", max);
	}
}
