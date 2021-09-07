

// input library
//-------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>





// Mendeklarasikan fungsi
//-------------------------------------------------------------------------------------------------------------------------------

void halamanutama();
void halamanlogin();
void halamanloginadmin();
void halamanloginkasir();
void logout();
void tentangkami();
void merge(int arr[], int left, int mid, int right);
void split(int arr[], int left, int right);
void sort(int arr[], int n);
void print(int arr[], int n);
void mergesort_extras();
void nilaikami();
void bintang();
void keluar();
void halamanregister();
void halamanregisteradmin();
void halamanregisterkasir();
void menuadmin();
void caribarang(); 
void tambahbarang();
void updatebarang();
void lihatdaftarbarang();
void hapusdatabase();
void infosupplier();
void cariinfosupplier(); 
void tambahsupplier(); 
void updatesupp();
void lihatdaftarsupplier(); 
void menukasir();
void jamtanggal();
void transaksibaru();
void historitransaksi();






// Mendeklarasikan Variable
//-------------------------------------------------------------------------------------------------------------------------------

struct gudang {
	int code;
	int qtybarang;
	long long int hargajual;
	char namasupplier[100];
	char namabarang[100];
}gud;

struct supplier{
	char nama[100];
	char barang[300];
	int pengiriman;
}sup;

struct kasir{
	short int qtybarang;
	int kodebarang;
	long int hargabarang;
	char namabarang[100];	
}kas;

struct gudang namabarang() {
	char namabarang[100];
	printf("\nEnter Item Name You Want to Find: \n");
    scanf("%s", namabarang);
    
	FILE *fp = fopen("./daftarbarang.txt", "r");
    struct gudang gud;
    
    while(fscanf(fp, "%[^#]#%d#%lld\n", gud.namabarang, &gud.qtybarang, &gud.hargajual) != EOF) {
             if(strcmp(namabarang, gud.namabarang) == 0) {
              return gud;
	    }
	  }
 
  struct gudang temp;
  return temp;
};

struct supplier findsupplier(){
    char name[100];
    printf("\nEnter Supplier Name You Want to Find: \n");
    scanf("%s", name);
    FILE *fp = fopen("./supplier.txt", "r");
    struct supplier sup;
    while(fscanf(fp, "%[^#]#%[^#]#%d\n", sup.nama, sup.barang, &sup.pengiriman) != EOF){
        if(strcmp(name, sup.nama) == 0){
            return sup;
        }
    }
    struct supplier temp;
    return temp;
}





// Badan Utama
//-------------------------------------------------------------------------------------------------------------------------------

int main(){
	halamanutama();
	return 0;
}

int namabarang(char all_Item[][15], int n, char barang[]) { 
 int min = 0, max = n - 1;
    while(min <= max){
        int mid = (min + max) / 2;

        if(strcmp(barang, all_Item[mid]) < 0){
            max = mid - 1;
        } else if(strcmp(barang, all_Item[mid]) > 0){
            min = mid + 1;
        } else{
            return mid;
        }
    }
    return -1;
}





//halaman depan 
//-------------------------------------------------------------------------------------------------------------------------------

void halamanutama(){
 printf("\n--------------------------------------");//38
    printf("\n          Welcome to Onemart");
    printf("\n--------------------------------------\n\n");
   
    int x;
    puts("\n1. Login");
    puts("2. Register");
    puts("3. About Us");
    puts("4. Rate Us");
    puts("5. Extras");
    puts("6. Exit\n\n");
	printf("Enter your choice: ");
    scanf("%d", &x);
    system("cls");
    switch(x){
    	
    case 1:{
        halamanlogin();
        break;
	}
	
    case 2:{
        halamanregister();
        break;
	}
	
    case 3:{
        tentangkami();
        break;
	}
    
    case 4:{
    	nilaikami();
		break;
	}
    case 5:{
    	mergesort_extras();
		break;
	}
    case 6:{
    	keluar();
    		break;
	}
        
    default:{
        printf("\nWrong input\nPlease Tryagain\n\n");
        system("pause");
        system("cls");
        halamanutama();
        break;
		}
	
	}
    
}

void halamanlogin() {
 int choice;
 char uname[50], pass[50];
 char username[50], password[50];
 printf("\n           Login Page");
 printf("\n-------------------------------------\n");
 puts("1. Login as Admin");
 puts("2. Login as Cahier");
 puts("3. Back");
 printf("Enter Your Choice: ");
 scanf("%d", &choice);
 system("cls");
 
 switch (choice) {
	  case 1:  {
	   halamanloginadmin();
	   break;
		}
	  
	  case 2: {
	  	halamanloginkasir();
		break;
		}
	   
	  case 3: {
	  	halamanutama();
		break;
	  }
	   
	  default: {
        printf("\nWrong input\nPlease Tryagain\n\n");
        system("pause");
        system("cls");
        halamanlogin();
        break;
		}
	
	   
 	}
 	
 return;
}

void halamanloginadmin(){
	char uname[50];
	char pass[50];
	char username[50];
	char password[50];
	
	printf("\n------- LOGIN AS ADMIN --------\n");
	printf("Masukkan Username: ");
	scanf("%s", &uname);
	printf("Masukkan password: ");
	scanf("%s", &pass);
    
	FILE *fp=fopen("./admindatabase.txt", "r");
  		 while (fscanf(fp,"%[^#]#%s\n", username, password)!=EOF){
   			 if(strcmp(uname,username)==0 && strcmp(pass,password)==0){
     			getchar();
				system("cls");
    			menuadmin();
    			}
   			}
   			
  		 if(strcmp(uname,username)!=0 && strcmp(pass,password)!=0){
		    printf("\nUsername or Password is invalid!");
		    printf("\nPlease Try Again");
		    getchar();
		    system("cls");
	    	halamanloginadmin();
    
   }
   fclose(fp);
   system("pause");
   system("cls");
}

void halamanloginkasir(){
	char uname[50];
	char pass[50];
	char username[50];
	char password[50];
	
	printf("\n------- LOGIN AS CASHIER --------\n");
   	printf("Masukkan Username: ");
   	scanf("%s", &uname);
   	printf("Masukkan password : ");
   	scanf("%s", &pass);
   
   	FILE *fp=fopen("./cashierdatabase.txt", "r");
   		while (fscanf(fp, "%[^#]#%s\n", username, password)!=EOF){
    		if(strcmp(uname,username)==0 && strcmp(pass,password)==0){
     		system("cls");
     		menukasir();
    		}
   		}
   		
   		if(strcmp(uname,username)!=0 && strcmp(pass,password)!=0){
     		printf("\nUsername or Password is invalid!");
     		getchar();
     		system("cls");
     		halamanloginkasir(); 
   		} 
   
   fclose(fp);
   system("pause");
   system("cls");
}

void halamanregister() {
 int choice;
 char uname[50], pass[50];
 char username[50], password[50];
 printf("\n        Registration Page");
 printf("\n-------------------------------------\n");
 puts("1. Register as Admin");
 puts("2. Register as Cahier");
 puts("3. Back");
 printf("Enter Your Choice: ");
 scanf("%d", &choice);
 getchar();
 system("cls");
 
 switch(choice){
 	
  case 1: {
   halamanregisteradmin();
   break;
  }
  
  case 2: {
   halamanregisterkasir();
   break;
  }
  
  case 3: {
  	halamanutama();
	break;
  }
  
  default:{
        printf("\nWrong input\nPlease Tryagain\n\n");
        system("pause");
        system("cls");
        halamanregister();
        break;
		}
	
 }
 
}

void halamanregisteradmin(){
  char uname[50], pass[50];
   char username[50], password[50];
   printf("\n------- REGISTER AS ADMIN --------\n");
   printf("Enter Your Username: ");
   scanf("%s", uname);
   printf("Enter Your Password: ");
   scanf("%s", pass);
   FILE *fp = fopen("./admindatabase.txt", "a+");
   
   while(fscanf(fp,"%[^#]#%s\n", username, password)!=EOF){
    if(strcmp(uname,username)==0){
       printf("\nUsername has been used!! Please Use Another Username.\n\n");
       system("pause");
       system("cls");
      halamanregister();
     } 
   }
    fprintf(fp, "%s#%s\n", uname, pass);
    fclose(fp);
    getchar();
   
   printf("Your Admin Account Successfully Created!\n You can now login as Admin.\n");
   system("pause");
   system("cls");
   halamanutama();  	
}

void halamanregisterkasir(){
 char uname[50], pass[50];
 char username[50], password[50];
 printf("\n------- REGISTER AS CASHIER --------\n");
   printf("Enter Your Username: ");
   scanf("%s", &uname);
   printf("Enter Your Password : ");
   scanf("%s", &pass);
   
   FILE *fp = fopen("cashierdatabase.txt", "a+");
   while(fscanf(fp,"%[^#]#%s\n", username, password)!=EOF){
    if(strcmp(uname,username)==0){
       printf("Username has been used!! Please Use Another Username.\n\n");
       system("pause");
       system("cls");
      halamanregister();
     }
   } //bila username baru, maka tinggal disalin ke file
    fprintf(fp, "%s#%s\n", uname, pass);
    fclose(fp);
    getchar();
   
   printf("Your Cashier Account Successfully Created!\n You can now login as Cashier.\n\n");
   system("pause");
   system("cls");
   halamanutama(); 	
}

void tentangkami(){
	MessageBox(0,"One mart is a sales managing Program made by Mie Tech Tech, \na group of five binusian who loves noddle.\n","Onemart - About Us",MB_OK);
    halamanutama();
}

void merge(int arr[], int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    for(int i = 0; i < leftSize; i++){
        leftArr[i] = arr[i + left];
    }
    for(int i = 0; i < rightSize; i++){
        rightArr[i] = arr[i + mid + 1];
    }

    int idx = left;
    int idxL = 0;
    int idxR = 0;

    while(idxL < leftSize && idxR < rightSize){
        if(leftArr[idxL] > rightArr[idxR]){
            arr[idx] = leftArr[idxL];
            idx++;
            idxL++;
        }
        else{
            arr[idx] = rightArr[idxR];
            idx++;
            idxR++;
        }
    }
    while(idxL < leftSize){
        arr[idx] = leftArr[idxL];
        idx++;
        idxL++;
    }

    while(idxR < rightSize){
        arr[idx] = rightArr[idxR];
        idx++;
        idxR++;
    }

}

void split(int arr[], int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
    split(arr, left, mid);
    split(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void sort(int arr[], int n){
    split(arr, 0, n - 1);
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergesort_extras(){
    int n, choice;
    int arr[n];
    puts("================FREE SORTING MACHINE JUST FOR YOU!===============");
    printf("\n");
    puts("Wanna sort a group of numbers?");
    puts("Just throw the numbers down here! And we'll sort them for you!!");
    puts("(we'll help you sort descendingly)");
    printf("\n\n");
    puts("Press 1, if you want to proceed!");
    puts("<or if you wanna go back to menu, enter any number!>");
    printf("\n------------------------------------------------------------------\n");
    printf("\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    
    switch (choice) {
		case 1: {
			printf("\nGreat!\n\n");
		    printf("Put the amount of numbers you want to sort (less than 5 numbers): ");
		    scanf("%d", &n);
		    puts("Type down the numbers you wnat to sort! ");
		    puts("(ex. 1(press enter) 2(press enter) 12(press enter) 10(press enter) ... n)");
			for (int i = 0; i<n; i++) {
				scanf("%d", &arr[i]);
				}
		    sort(arr, n);
		    printf("There You Go.. \n");
		    print(arr, n);
		    printf("\n");
			printf("Hope this features helps!\n See Ya!\n");
			system("pause");
			system("cls");
			halamanutama();
			break;
		}
		default: {
			printf("Well then, See You Later!");
			system("cls");
			halamanutama();
			break;
		}
	}
}

void bintang(int n){
	if(n==0)
		return;
	else
		printf("*");
		return bintang(n-1);
}

void nilaikami(){
	printf("How many stars would you rate us out of five?\n");
	int star;
	scanf("%d", &star);
	bintang(star);
	printf("\nThank you\n\n\n");
	system("pause");
	getchar();
	system("cls");
	halamanutama();
}

void logout(){
	getchar();
	system("cls");
	halamanutama();
}

void keluar(){
	char decision[10];
	system("cls");
	printf("\nDo you want to quit program?\n");
	scanf("%s", decision);
	
	if(strcmp(decision, "Yes")== 0 || strcmp(decision, "yes")== 0|| strcmp(decision, "YES")== 0) {
		getchar();
		system("cls");
		  printf("Are you satisfied with the program?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  int answer;
  scanf("%d", &answer);
  (answer == 1) ? puts("Thank you") : puts("We will gladly accept your feedback at Onemart@gmail.com");
		
		MessageBox(0,"See You!","Onemart",MB_OK);
        exit(0);
	} 
	else if(strcmp(decision, "No")== 0 || strcmp(decision, "no")== 0|| strcmp(decision, "NO")== 0) {
		getchar();
		system("cls");
		halamanutama();
	}
	else{
		keluar();
	}
	return;
}





// admin
//-------------------------------------------------------------------------------------------------------------------------------

void menuadmin(){
	int n;
	printf("\n-------------------------------------");//37
    printf("\n            Welcome Admin");
    printf("\n-------------------------------------");
	printf("\n1. Find Item");
	printf("\n2. Add Item");
	printf("\n3. View Item List");
	printf("\n4. Item Information Update");
	printf("\n5. Supplier Information");
	printf("\n6. Factory Reset");
	printf("\n7. Logout");
	printf("\n-------------------------------------\n");
	puts("Enter your choice: ") ;
	scanf("%d", &n);
	switch(n){
	case 1: 
		    caribarang();
	    	break;
	   
	case 2:
	        tambahbarang();
	        break;
	        
	case 3:
	        lihatdaftarbarang();
	        break;
		
	case 4:
			updatebarang();
			break;
	        
	case 5:
	        infosupplier();
	        break;
	  
	case 6:
	        hapusdatabase();
	        break;
	  
	case 7:
	        logout();
	        break;
	        
	default:
	        printf("\nWrong input\nPlease Tryagain\n\n");
	        system("pause");
	        system("cls");
	        menuadmin();
	        break;
    }
}

void caribarang(){
	struct gudang temp = namabarang();
		  char all_Item[][15] = {"Adaptor", "Headset", "Mouse", "Printer", "Speaker"};
		  int n = 5;
		  char barang[15];
		    printf("Item: %s\nQty: %d\nPrice: %lld\n", temp.namabarang, temp.qtybarang, temp.hargajual);
		    printf("\n");
		    
		    system("cls");
			menuadmin();
}

void tambahbarang() {
	  struct gudang gud;
	  system("cls");
	  FILE *in; 
		in = fopen("./daftarbarang.txt","a+"); 
		printf("Add the item code: ");
		scanf("%d", &gud.code);
		printf("Add the item name: ");
		getchar();
	    scanf("%[^\n]s", gud.namabarang);
		printf("Add the item quantity: ");
		scanf("%d", &gud.qtybarang);
//	        fgets(gud.qtybarang, 100, stdin);
		printf("Add the selling price: ");
		scanf("%d", &gud.hargajual);
		printf("Add the supplier name: ");
		getchar();
	    scanf("%[^\n]s", gud.namasupplier);
        
        if(in != NULL){
		 fprintf(in, "%d#%s#%d#%d#%s\n", gud.code, gud.namabarang, gud.qtybarang, gud.hargajual, gud.namasupplier);
		}
		else{
			printf("Database is not found");
			exit(EXIT_FAILURE);
		}
		
		fclose(in);
			printf("\n\nData saved succesfully");
		
		getchar();
		system("cls");
		menuadmin();
		return ;
	
//note:
// a+ -> sama dengan mode"a", namun file dapat ditulis dan di baca juga
//fflush digunakan untuk membersihkan stream 
//fgets digunakan untuk membaca baris dari stream yang sudah ditentukan dan di simpen ke string yang sudah di tunjuki oleh str
//format fgets =  "fgets(char *str, int n, FILE *stream)"
//str -> lokasi string dimana array disimpan
//n -> maksimum char yang bisa dibaca
//stream -> penunjuk ke stream dimana file dibaca
//exit(EXIT_FAILURE); -> untuk menghentinkan sistem
//system("cls"); -> untuk membersihkan ouput screen
}

void updatebarang(){
	FILE *fp1, *fp;
 	system("cls");
	int code;
	char namasupplier[100];
	char namabarang[100];
	int hargajual;
	int qtybarang;
	int f=0;
	char name1[30];
	fp=fopen("daftarbarang.txt","r");
	fp1=fopen("temp.txt","a");
	printf("Enter Item Name: ");
	scanf("%s", name1);
	while(fscanf(fp,"%d#%[^#]#%d#%d#%s\n", &code, namabarang, &qtybarang, &hargajual, namasupplier) !=EOF)
	{
		if((strcmp(namabarang,name1))==0)
		{
			f=1;
			printf("Please re-enter the item code: ");
			scanf("%d", &code);
			printf("Enter New Selling Price: ");
			scanf("%d", &hargajual);
			printf("Enter New Quantity: ");
			scanf("%d", &qtybarang);
			fprintf(fp1, "%d#%s#%d#%d#%s\n", code, namabarang, qtybarang, hargajual, namasupplier);
			
		}
		else
		{
			fprintf(fp1, "%d#%s#%d#%d#%s\n", code, namabarang, qtybarang, hargajual, namasupplier);	
		}
	}
	if(f==0)
	{
		printf("Item Name Not Found");
	}
	
	fclose(fp);
	fclose(fp1);
	
	fp=fopen("daftarbarang.txt","w"); // to delete contents of daftarbarang.txt
	fclose(fp);
	
	fp=fopen("daftarbarang.txt","w");
	fp1=fopen("temp.txt","r");
	while(fscanf(fp1,"%d#%[^#]#%d#%d#%s\n", &code, namabarang, &qtybarang, &hargajual, namasupplier) !=EOF)
	{
		fprintf(fp, "%d#%s#%d#%d#%s\n", code, namabarang, qtybarang, hargajual, namasupplier);
	}
	fclose(fp);
	fclose(fp1);
//	remove("temp.txt");
	fp=fopen("temp.txt","w");
	fclose(fp);
	getchar();
	system("pause");
	system("cls");
	menuadmin();
}

void lihatdaftarbarang(){
	struct gudang gud;
	system("cls");
	FILE *in = fopen("./daftarbarang.txt","r");
			while(fscanf(in,"%d#%[^#]#%d#%d#%s\n", &gud.code, gud.namabarang, &gud.qtybarang, &gud.hargajual, gud.namasupplier)!=EOF){
				printf("Item Code       : %d\n", gud.code);
				printf("Item name       : %s\n", gud.namabarang);
		        printf("Item Quantity   : %d\n", gud.qtybarang);
		        printf("Selling Price   : %d\n", gud.hargajual);
		        printf("Supplier Name   : %s\n\n", gud.namasupplier);
		        printf("-----------------------------------------------------\n");		        
			}
			system("pause");
			system("cls");
			menuadmin();

		
//note		
//getc = untuk ambil char dari stream yang ditentukan 
//format getc = getc(File *stream)
//exit(EXIT_FAILURE); -> untuk end sistem
}

void infosupplier(){
	int choice;
	system("cls");
	do{
		printf("\n-------------------------------------");//37
    	printf("\n        Supplier Information");
   		printf("\n-------------------------------------\n");
		puts("1. Find Supplier");
	    puts("2. Add Supplier");
	    puts("3. View All Supplier");
	    puts("4. Supplier Information Update");
	    puts("5. Back");
	    puts("Enter your choice: ");
	    scanf("%d", &choice);
	    
		    switch(choice){
		        case 1:
		            cariinfosupplier();
		            break;
		        
				case 2:
		            tambahsupplier();
		            break;
		        		        
				case 3:
		            lihatdaftarsupplier();
		            break;
		    					
				case 4: 
					updatesupp();
					break;
						    	
				case 5:
		    		system("cls");
		    		menuadmin();
					break;				
			}
		}
		    			while(choice !=5);
		
	}

void cariinfosupplier(){
	struct supplier temp = findsupplier();
            printf("Informasi Supplier:\n Nama Supplier    : %s\n Nama Barang      : %s\n Biaya Pengiriman : %d\n\n", temp.nama, temp.barang, temp.pengiriman);
            system("pause");
            system("cls");
			infosupplier();
}

void tambahsupplier(){
	struct supplier sup;
		printf("Add supplier name: ");
			scanf("%s^\n", sup.nama);
		printf("Add goods available: ");
			scanf("%s^\n", sup.barang);
		printf("Price per delivery: ");
			scanf("%d", &sup.pengiriman);
		
		FILE *fp= fopen("supplier.txt", "a");
		fprintf(fp, "%s#%s#%d \n", sup.nama, sup.barang, sup.pengiriman);
		fclose(fp);
	system("pause");
    system("cls");
    infosupplier();
}

void updatesupp() { 
		FILE *fp1, *fp;
	//info: ini txt nya aku pakai yg supplier.txt
	//dari sini
	char nama[100];
	char barang[300];
	int pengiriman;
	//sampai sini itu dicopy isinya struct supplier
	int f=0;
	char name1[20];//si nama item yang di provide sama suppliernya (buat track down supplier yang mau diganti dari barang yang ditawarkan)
//	clrscr();
	fp=fopen("supplier.txt","r");
	fp1=fopen("temp.txt","a");
	printf("Enter Item Name Provided by The Supplier: ");
	scanf("%s", name1);
//di sini kita scan dari original file, lalu rewrite ke file temp.txt
	while(fscanf(fp, "%[^#]#%[^#]#%d\n", 
            nama, barang, &pengiriman) != EOF)
	{
		if((strcmp(barang,name1))==0)
		{
			f=1;
			printf("Enter New Supplier: ");
			scanf("%s", nama);
			fprintf(fp1, "%s#%s#%d\n", nama, barang, pengiriman);
			
		}
		else
		{
			fprintf(fp1, "%s#%s#%d\n",  nama, barang, pengiriman);
			//ini untuk menyalin daftar barang lain yang tidak diubah
		}
	}
	if(f==0)
	{
		printf("Item Not Found");
	}
	fclose(fp);
	fclose(fp1);
	
	//tahap ini, menyalin kembali dari temp.txt balik ke file originalnya (supplier.txt)
	fp=fopen("supplier.txt","w"); // to delete contents of supplier.txt
	fclose(fp);
	
	fp=fopen("supplier.txt","w");
	fp1=fopen("temp.txt","r");
	while(fscanf(fp1, "%[^#]#%[^#]#%d\n", nama, barang, &pengiriman) != EOF)
	{
		fprintf(fp, "%s#%s#%d\n",  nama, barang, pengiriman);
	}
	fclose(fp);
	fclose(fp1);
//	remove("temp.txt");
	fp=fopen("temp.txt","w"); //cm enak pakai ini aja biar ntr file temp.txt (temporary) nya masih ada, tpi kosong
	//fungsi temp.txt -> menampung informasi yang diperbaiki dari original file, lalu karena informasi di temp.txt sudah disalin
	//balik ke file original.. isi temp.txt bisa dihapus
	fclose(fp);
	getchar();
	system("pause");
	infosupplier();
	
}

void lihatdaftarsupplier(){
		FILE *fp = fopen("./supplier.txt", "r");
    struct supplier sup;
    while(fscanf(fp, "%[^#]#%[^#]#%d\n", sup.nama, sup.barang, &sup.pengiriman) != EOF){
        printf("Name of Supplier: %s\n", sup.nama);
        printf("Goods Provided: %s\n", sup.barang);
        printf("Cost Per Delivery: %d\n\n", sup.pengiriman);
    }
    
	system("pause");
    system("cls");
    infosupplier();
}

void hapusdatabase(){
	system("cls");
	remove("./daftarbarang.txt");
	puts("\nFactory Reset Completed\n\n\n");
	system("pause");
	getchar();
	system("cls");
	menuadmin();
	return;
}





// kasir
//-------------------------------------------------------------------------------------------------------------------------------

void menukasir(){
	int n;
	printf("\n-------------------------------------");//37
    printf("\n           Welcome Cashier");
    printf("\n-------------------------------------");
	printf("\n1. New Transaction");
	printf("\n2. Transaction History");
	printf("\n3. Logout");
	printf("\n-------------------------------------\n");
	scanf("%d", &n);
	
	switch(n){
	case 1:
        transaksibaru();
        break;

    case 2:
        historitransaksi();
        break;
  
    case 3:
        logout();
        break;
        
    default:
        printf("\nWrong input\nPlease Tryagain\n\n");
        system("pause");
        getchar();
        system("cls");
        menukasir();
        break;
    }
}

void jamtanggal(){
    time_t t = time(NULL);
    struct tm* tm_local = localtime(&t);
    printf("%s", asctime(tm_local));
}

void transaksibaru(){
 struct kasir kas[200];
 int tc; 
 int hargatotal=0;
 int bayar;
 int kembalian;
 int totalhargaperbarang[200];
 time_t t = time(NULL);
    struct tm* tm_local = localtime(&t);
    
 int nomorpembelian;
 printf("\nTransaction Number: ");
 scanf("%d", &nomorpembelian);
 
	char namapelanggan[100];
	int lengthCostumer = strlen(namapelanggan);
	do {
	printf("Input name of costumers   :");
	getchar();
	scanf("%[^\n]", namapelanggan);
	} while (strlen(namapelanggan)<3);
 
 
    getchar();
    system("cls");
 
 printf("\nTotal item type: ");
 scanf("%d", &tc);
 printf("------------------------------------\n");
 
 for(int i = 1; i <= tc; i++){
  printf("Item Code: ");
   getchar ();
    scanf("%d", &kas[i].kodebarang);
  printf("Item Name: ");
   getchar ();
    scanf("%[^\n]s", kas[i].namabarang);
  printf("Qty: "); 
   getchar ();
    scanf("%d", &kas[i].qtybarang);
  printf("Price: "); 
   getchar ();
    scanf("%ld", &kas[i].hargabarang);
    printf("\n"); 
  kas[i].qtybarang = kas[i].qtybarang;
  totalhargaperbarang[i] = kas[i].hargabarang * kas[i].qtybarang;
  hargatotal = hargatotal + totalhargaperbarang[i];
  
  FILE *fp= fopen("./historitransaksi.txt", "a+");
  fprintf(fp, "\n----------------------------------------------------\nPeriod of Transaction: %s \nItem Code     : %d \nItem Name     : %s \nQuantity      : %d \nSelling Price : %ld \n----------------------------------------------------\n\n", asctime(tm_local),kas[i].kodebarang, kas[i].namabarang, kas[i].qtybarang, kas[i].hargabarang);
  fclose(fp);
  
  FILE *in; 
  in = fopen("./historitransaksi.txt","a+"); 
  
  
 }
 
 
  printf("Total: %d\n", hargatotal);
  start1:
  printf("Enter payment amount: ");
     scanf("%d", &bayar);
     
     if (bayar>hargatotal){
  kembalian= bayar-hargatotal;
  } 
  else {
  puts("Sorry, the amount of money is not enough");
     goto start1;
     }
     
  system("pause");
     system("cls");
 
 puts("\n");
 printf("____________________________________________One Mart____________________________________________");
 puts("\n");
 printf("%s\n", asctime(tm_local));
 printf("No. %d\n", nomorpembelian);
 printf("Customer Name: %s\n\n", namapelanggan);
 
  puts("\xda\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
 puts("\xb3 No \xb3    Code   \xb3         Name          \xb3     Price     \xb3     Qty      \xb3       Subtotal        \xb3");
 puts("\xc3\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb4");
  
  for ( int i = 1; i <= tc; i++){
   printf("\xb3  %d \xb3   %d\t \xb3", i, kas[i].kodebarang); 
   printf("\t%s\t\t \xb3", kas[i].namabarang); 
   printf(" Rp. %ld\t \xb3", kas[i].hargabarang); 
   printf("\t%d\t\xb3", kas[i].qtybarang); 
   printf("  Rp. %d\t\t\xb3\n", kas[i].qtybarang*kas[i].hargabarang);
   }
   
   puts("\xc3\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb4"); 
   printf("\xb3                              Total Price                              \xb3  Rp. %d\t\t\xb3\n", hargatotal);
   puts("\xc3\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb4"); 
   printf("\xb3                                Cash                                   \xb3  Rp. %d\t\t\xb3\n", bayar);
   puts("\xc3\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb4"); 
   printf("\xb3                                Return                                 \xb3  Rp. %d\t\t\xb3\n", kembalian);
   puts("\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n\n"); 

 puts("________________________________________________________________________________________________\n");
 puts("                                     THANKYOU FOR YOUR VISIT                                    ");
 puts("                                    ONE MART CUSTOMER SERVICE                                   ");
 puts("                                        onemart@gmail.com                                       ");

system("pause");
system("cls");
menukasir();

}

void historitransaksi(){
	struct kasir kas;
	time_t t = time(NULL);
    struct tm* tm_local = localtime(&t);
	FILE *in;
	char buffer;
		
		in = fopen("./historitransaksi.txt","r");
		if (in != NULL){
			while((buffer = getc(in)) != EOF){
				printf("%c",buffer);
			}
		}
		else{
			printf("Database is not found");
			exit(EXIT_FAILURE);
		}
    
	system("pause");
    system("cls");
    menukasir();
}






