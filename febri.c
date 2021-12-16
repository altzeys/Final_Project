#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
struct data{
	char nama[100];
	char domain[50];
	char nomber[12];
	struct data *next;
};
struct data *buku_telepon[50];
//null exception hash_table
void init(int);
//list telepon
struct data *list(int);
struct data *edit(int);
struct data *view(int); 
struct data *find(int); 

int item=0;
int main() {
	int input,n_domain,full,pengisian=0,dom;
	char konfim;
	printf("              Selamat Datang di Buku Telepon            \n");
	printf("Jumlah Domain Telepon:");scanf("%d",&n_domain);system("cls");
	init(n_domain);
	do {
	sleep(3);
	system("cls");	
		printf("              Selamat Datang di Buku Telepon            \n");
		printf("           Silahkan input menu yang Anda sukai!!        \n");
		printf("========================================================\n");
		printf("\n");
		printf("--------------------------------------------------------\n");
		printf("|                      MENU PROGRAM                    |\n");
		printf("--------------------------------------------------------\n");
		printf("|                  1. Tambah Kontak                    |\n");
		printf("|                  2. Edit Kontak                      |\n");
		printf("|                  3. Hapus Kontak                     |\n");
		printf("|                  4. Lihat Kontak                     |\n");
		printf("|                  5. Cari Kontak                      |\n");
		printf("|                  0. Keluar                           |\n");
		printf("--------------------------------------------------------\n");
		printf("Input pilihan yang Anda inginkan : ");
		scanf("%d", &input);
		system("cls");
		switch(input){

			case 1:
				if(pengisian==0){
					do{
						printf("|                  Domain Kontak                    |\n");
						struct data *sub, *empty;
						sub=malloc(sizeof(struct data));
						sub->next=NULL;//Petanda Sudah Ada Domain
						printf("\nAlokasi Domain Barang:\n");
						fflush(stdin);
						printf("Domain Barang ke %i:",item+1);scanf("%[^\n]",&sub->domain);fflush(stdin);
						buku_telepon[item]=sub;
						++item;
						full=item;
						empty=malloc(sizeof(struct data));
						empty=NULL;
						buku_telepon[full]=empty;//Tidak Ada Domain
						++pengisian;
						printf("Lagi(y|t) :");scanf("%c",&konfim);
					}while(konfim=='y');
				}
				else{
					fflush(stdin);
					printf("Tambah Domain?(y|t):");scanf("%c",&konfim);fflush(stdin);
					if(konfim=='y'){
						do{
							printf("|                  Domain Kontak                    |\n");
							struct data *sub, *empty;
							sub=malloc(sizeof(struct data));
							sub->next=NULL;//Petanda Sudah Ada Domain
							printf("\nAlokasi Domain Barang:\n");
							fflush(stdin);
							printf("Domain Barang ke %i:",item+1);scanf("%[^\n]",&sub->domain);fflush(stdin);
							buku_telepon[item]=sub;
							++item;
							full=item;
							empty=malloc(sizeof(struct data));
							empty=NULL;
							buku_telepon[full]=empty;//Tidak Ada Domain
							printf("Lagi(y|t) :");scanf("%c",&konfim);
						}while(konfim=='y');
					}
				}
				list(full);
				break;
			case 2:
                printf("|                  Domain Kontak                    |\n");
				printf("List Domain:\n");
				for(int i=0;i<full;i++){
					printf("%d.%s\n",i+1,buku_telepon[i]->domain);
				}
				printf("Pilih domain :");scanf("%d",&dom);
				dom=dom-1;
				edit(dom);
				break;

			case 3:
                printf("Halo");
				break;

			case 4:
                view(full);
				break;

			case 5 :
                printf("|                  Domain Kontak                    |\n");
				printf("List Domain:\n");
				for(int i=0;i<full;i++){
					printf("%d.%s\n",i+1,buku_telepon[i]->domain);
				}
				printf("Pilih domain :");scanf("%d",&dom);
				dom=dom-1;
				find(dom);
                break;


			case 0 :
				printf("Anda Telah Keluar Dari Program, Terima Kasih!!");
				break;

			default:{
				printf("Input Menu Salah");
				break;
			}
		}
	} while(input!=0);


	return 0;
}
void init(int n_domain){
	for(int i=0;i<n_domain;i++){
		buku_telepon[i]=NULL;
	}
}
struct data *list(int full){
	int pilihan;
	printf("|                  Domain Kontak                    |\n");
	printf("List Domain:\n");
	for(int i=0;i<full;i++){
		printf("%d.%s\n",i+1,buku_telepon[i]->domain);
	}
	printf("Pilih Domain:");scanf("%d",&pilihan);
	pilihan=pilihan-1;
	struct data *baru,*ptr;
	baru=malloc(sizeof(struct data));fflush(stdin);
	printf("Nama Kontak:");scanf("%[^\n]",&baru->nama);fflush(stdin);
	printf("No Telepon:");scanf("%[^\n]",&baru->nomber);fflush(stdin);
	baru->next=NULL;
	if(buku_telepon[pilihan]->next==NULL){
		buku_telepon[pilihan]->next=baru;
	}
	else{
		ptr=buku_telepon[pilihan]->next;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=baru;
	}
	ptr=buku_telepon[pilihan]->next;
	
}
struct data *edit(int dom){
	struct data *ptr;
	char nama_edit[50];
	ptr=buku_telepon[dom]->next;
	while(ptr!=NULL){
		printf("%s->",ptr->nama);
		ptr=ptr->next;
	}
	printf("NULL");
	fflush(stdin);
	printf("\nPilih Nama Kontak untuk di edit: ");scanf("%[^\n]",&nama_edit);fflush(stdin);
	ptr=buku_telepon[dom]->next;
	while(ptr!=NULL){
		if(strcmp(ptr->nama,nama_edit)==0){
			fflush(stdin);
			printf("Nama Kontak:");scanf("%[^\n]",&ptr->nama);fflush(stdin);
			printf("No Telepon:");scanf("%[^\n]",&ptr->nomber);fflush(stdin);
			break;
		}
		ptr=ptr->next;
	}
}

struct data *view(int full){
	int i;
	char condition;
	
	for(i=0;i<full;i++){	
		if(buku_telepon[i]!=NULL){
			struct data *ptr;	
			printf("\n\033[0;36m Jenis Kontak	: %s \033[0m", buku_telepon[i]->domain);
			
			ptr=buku_telepon[i]->next;
			while(ptr!=NULL){
				printf("\n Nama Kontak	: %s" , ptr->nama);
				printf("\n Nomor Telepon	: %s\n",  ptr->nomber);
				ptr=ptr->next;
			}
		}
	}fflush(stdin);
	
	printf("\n\nApakah Anda Ingin Melihat Alur Prosesnya (y/t) ? : ");scanf("%c",&condition);
	if(condition=='y'||condition=='Y'){
		printf("\n|\033[0;36m Jenis Kontak %s \033[0m | \033[0;36m Identitas \033[0m\n");
		for(i=0;i<full;i++){
			if(buku_telepon[i]!=NULL){
				struct data *ptr;
				printf("\n| %-7s	|", buku_telepon[i]->domain);
					
				ptr=buku_telepon[i]->next;
				while(ptr!=NULL){
					printf(" %s ", ptr->nama);
					printf(" %s -> ", ptr->nomber);
					ptr=ptr->next;
				}
			}
		 printf(" NULL \n");
		}
	}fflush(stdin);
}

struct data *find(int dom){
	struct data *ptr;
	int choose, flag=0;
	char search[50];
	ptr=buku_telepon[dom]->next;
	
	/*while(ptr!=NULL){
		printf("%s->",ptr->nama);
		ptr=ptr->next;
	}*/
	//printf("NULL");
	
	printf("\n 	Cari Melalui		");
	printf("\n 1. Nama				");
	printf("\n 2. Nomor Telepon\n	");
	printf("\n Input Pilihan: ");
	scanf("%d",&choose);
	fflush(stdin);

	switch(choose){
		case 1:
			printf("\n Input Nama yang ingin di dicari: ");
			scanf("%[^\n]",&search);fflush(stdin);
				while(ptr!=NULL){
					if(strcmp(ptr->nama,search)==0){
					flag=1;
					break;
				}
				ptr=ptr->next;
			}
			if (flag==1){
				printf("\n\033[0;32m [Kontak Ditemukan] \033[0m");
			}
			else{
				printf("\n\033[0;31m [Kontak Tidak ditemukan] \033[0m");
			}
			
			break;
			
		case 2:
			printf("\n input Nomor Telepon yang ingin di dicari: ");
			scanf("%[^\n]",&search);fflush(stdin);
				while(ptr!=NULL){
					if(strcmp(ptr->nomber,search)==0){
					flag=1;
					break;
					}
				ptr=ptr->next;
			}
			if (flag==1){
				printf("\n\033[0;32m [Kontak Ditemukan] \033[0m");
			}
			else{
				printf("\n\033[0;31m [Kontak Tidak ditemukan] \033[0m");
			}
			break;
			
		default:
			printf("\n\033[0;31m INPUTAN SALAH \033[0m");
			break;
	}
	fflush(stdin);
}
