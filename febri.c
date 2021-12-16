#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

struct data{
	char nama[100];
	char domain[50];
	char nomber[12];
	char alamat[50];
	char catatan[200];
	struct data *next;
};

struct data *buku_telepon[50];
//null exception hash_table
void init(int);
//list telepon
struct data *list(int);
struct data *edit(int);
struct data *hapus(int);
struct data *view(int); 
struct data *find(int);
int item=0;

int main() {
	int input,n_domain,full,pengisian=0,dom;
	char konfim;
	printf("              Selamat Datang di Buku Telepon            \n\n");
	printf(" Masukkan Jumlah Domain Telepon: ");scanf("%d",&n_domain);system("cls");
	init(n_domain);
	do {
	system("cls");
		printf("              Selamat Datang di Buku Telepon            \n");
		printf("           Silahkan input menu yang Anda sukai!!        \n");
		printf("========================================================\n");
		printf("\n");
		printf("--------------------------------------------------------\n");
		printf("|                     MENU PROGRAM                     |\n");
		printf("--------------------------------------------------------\n");
		printf("|                  1. Tambah Kontak                    |\n");
		printf("|                  2. Edit Kontak                      |\n");
		printf("|                  3. Hapus Kontak                     |\n");
		printf("|                  4. Lihat Kontak                     |\n");
		printf("|                  5. Cari Kontak                      |\n");
		printf("|                  0. Keluar                           |\n");
		printf("--------------------------------------------------------\n");
		printf(" Input pilihan yang Anda inginkan : ");
		scanf("%d", &input);
		system("cls");
		switch(input){
			case 1:
				if(pengisian==0){
					do{
						system("cls");
						//printf("|                  Domain Kontak                    |\n");
						printf("|              Alokasi Domain Kontak                |\n\n");
						struct data *sub, *empty;
						sub=malloc(sizeof(struct data));
						sub->next=NULL;//Petanda Sudah Ada Domain
						fflush(stdin);
						printf(" Nama Domain Kontak ke %i: ",item+1);scanf("%[^\n]",&sub->domain);fflush(stdin);
						buku_telepon[item]=sub;
						++item;
						full=item;
						empty=malloc(sizeof(struct data));
						empty=NULL;
						buku_telepon[full]=empty;//Tidak Ada Domain
						++pengisian;
						printf(" Input Lagi ? (y|t) : ");scanf("%c",&konfim);
					}while(konfim=='y');
				}
				else{
					fflush(stdin);
					printf(" Tambah Domain Kontak? (y|t): ");scanf("%c",&konfim);fflush(stdin);
					if(konfim=='y'){
						do{
							system("cls");
							//printf("|                  Domain Kontak                    |\n");
							printf("|              Alokasi Domain Kontak                |\n\n");
							struct data *sub, *empty;
							sub=malloc(sizeof(struct data));
							sub->next=NULL;//Petanda Sudah Ada Domain
							fflush(stdin);
							printf(" Nama Domain Kontak ke %i: ",item+1);scanf("%[^\n]",&sub->domain);fflush(stdin);
							buku_telepon[item]=sub;
							++item;
							full=item;
							empty=malloc(sizeof(struct data));
							empty=NULL;
							buku_telepon[full]=empty;//Tidak Ada Domain
							printf(" Input Lagi ? (y|t) : ");scanf("%c",&konfim);
						}while(konfim=='y');
					}
				}
				list(full);
				break;
			case 2:
                printf("|                  Domain Kontak                    |\n\n");
				printf("\033[0;36m List Domain: \033[0m \n");
				for(int i=0;i<full;i++){
					printf(" %d.%s\n",i+1,buku_telepon[i]->domain);
				}
				printf("\n Pilih domain : ");scanf("%d",&dom);
				dom=dom-1;
				edit(dom);
				break;

			case 3:
                printf("|                  Domain Kontak                    |\n\n");
				printf("\033[0;36m List Domain: \033[0m \n");
				for(int i=0;i<full;i++){
					printf(" %d.%s\n",i+1,buku_telepon[i]->domain);
				}
				printf("\n Pilih domain : ");scanf("%d",&dom);
				dom=dom-1;
				hapus(dom);
				break;

			case 4:
                view(full);
				break;

			case 5 :
                printf("|                  Domain Kontak                    |\n\n");
				printf("\033[0;36m List Domain: \033[0m \n");
				for(int i=0;i<full;i++){
					printf(" %d.%s\n",i+1,buku_telepon[i]->domain);
				}
				printf("\n Pilih domain : ");scanf("%d",&dom);
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
	system("cls");
	int pilihan;
	printf("|                  Domain Kontak                    |\n\n");
	printf("\033[0;36m List Domain: \033[0m \n");
	for(int i=0;i<full;i++){
		printf(" %d.%s\n",i+1,buku_telepon[i]->domain);
	}
	printf("\n Pilih Domain: ");scanf("%d",&pilihan);
	pilihan=pilihan-1;
	struct data *baru,*ptr;
	baru=malloc(sizeof(struct data));fflush(stdin);
	printf("\n Nama Kontak	: ");scanf("%[^\n]",&baru->nama);fflush(stdin);
	printf(" No Telepon	: ");scanf("%[^\n]",&baru->nomber);fflush(stdin);
	printf(" Alamat		: ");scanf("%[^\n]",&baru->alamat);fflush(stdin);
	printf(" Catatan	: ");scanf("%[^\n]",&baru->catatan);fflush(stdin);
	printf("\n\n\033[0;32m [Kontak Berhasil Ditambah] \033[0m");


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
sleep(1);
}
struct data *edit(int dom){
	system("cls");
	struct data *ptr;
	char nama_edit[50];
	int flag;	
	
	if(ptr!=NULL){
		printf("\n\033[0;36m Domain Kontak	: %s \033[0m", buku_telepon[dom]->domain);
		ptr=buku_telepon[dom]->next;
		while(ptr!=NULL){
			printf("\n Nama Kontak	: %s" , ptr->nama);
			printf("\n Nomor Telepon	: %s",  ptr->nomber);
			printf("\n Alamat Kontak	: %s",  ptr->alamat);
			printf("\n Catatan Kontak	: %s\n",  ptr->catatan);
			ptr=ptr->next;
		}fflush(stdin);
	}
	
	printf("\n\n Pilih Nama Kontak untuk di edit: ");scanf("%[^\n]",&nama_edit);fflush(stdin);
	ptr=buku_telepon[dom]->next;
	
	if(ptr==NULL)
	flag=0;
	
	else if (ptr!=NULL){
		while(ptr!=NULL){
			if(strcmp(ptr->nama,nama_edit)==0){
				fflush(stdin);
				printf(" Nama Kontak [Baru]	: ");scanf("%[^\n]",&ptr->nama);fflush(stdin);
				printf(" No Telepon [Baru]	: ");scanf("%[^\n]",&ptr->nomber);fflush(stdin);
				printf(" Alamat	[Baru]		: ");scanf("%[^\n]",&ptr->alamat);fflush(stdin);
				printf(" Catatan [Baru]		: ");scanf("%[^\n]",&ptr->catatan);fflush(stdin);	
				flag=1;
				break;
			}else
			flag=0;
			ptr=ptr->next;
		}
	}
	
	if (flag==1){
		printf("\n\033[0;32m [Kontak Berhasil Diedit] \033[0m");
	}
	else{
		printf("\n\033[0;31m [Kontak Tidak ditemukan] \033[0m");
	}
sleep(2);
}

struct data *hapus(int dom){
	int flag=0;
	char nama_dom[50];
	struct data *ptr,*preptr;
	
	printf("\n\033[0;36m Domain Kontak	: %s \033[0m", buku_telepon[dom]->domain);
	ptr=buku_telepon[dom]->next;
	while(ptr!=NULL){
		printf("\n Nama Kontak	: %s" , ptr->nama);
		printf("\n Nomor Telepon	: %s",  ptr->nomber);
		printf("\n Alamat Kontak	: %s",  ptr->alamat);
		printf("\n Catatan Kontak	: %s\n\n",  ptr->catatan);
		ptr=ptr->next;
	}fflush(stdin);
	
	fflush(stdin);
	printf(" Nama Kontak (Dihapus): ");scanf("%[^\n]",&nama_dom);fflush(stdin);
	
	preptr=ptr=buku_telepon[dom];
	while(ptr!=NULL){
		if(strcmp(ptr->nama,nama_dom)==0){
			preptr->next=ptr->next;
			free(ptr);
			ptr=preptr;
			flag=1;
			break;
		}
		preptr=ptr;
		ptr=ptr->next;
	}
	
	if (flag==1){
		printf("\n\033[0;32m [Kontak Berhasil Dihapus] \033[0m");
	}
	else{
		printf("\n\033[0;31m [Kontak Tidak ditemukan] \033[0m");
	}
	
sleep(2);
}

struct data *view(int full){
	system("cls");
	int i;
	char condition;
	
	for(i=0;i<full;i++){	
		if(buku_telepon[i]!=NULL){
			struct data *ptr;	
			printf("\n\033[0;36m Domain Kontak	: %s \033[0m\n", buku_telepon[i]->domain);
			
			ptr=buku_telepon[i]->next;
			while(ptr!=NULL){
				printf("\n Nama Kontak	: %s" , ptr->nama);
				printf("\n Nomor Telepon	: %s",  ptr->nomber);
				printf("\n Alamat Kontak	: %s",  ptr->alamat);
				printf("\n Catatan Kontak	: %s\n",  ptr->catatan);
				ptr=ptr->next;
			}
		}
	}fflush(stdin);
	
	printf("\n\n Apakah Anda Ingin Melihat Alur Prosesnya (y/t) ? : ");scanf("%c",&condition);
	if(condition=='y'||condition=='Y'){
		printf("\n|\033[0;36m Domain Kontak  \033[0m | \033[0;36mIdentitas \033[0m\n");
		for(i=0;i<full;i++){
			if(buku_telepon[i]!=NULL){
				struct data *ptr;
				printf("\n| %-7s	  |", buku_telepon[i]->domain);
					
				ptr=buku_telepon[i]->next;
				while(ptr!=NULL){
					printf(" [%s] [%s] [%s] [%s] ->", ptr->nama, ptr->nomber, ptr->alamat, ptr->catatan);
					ptr=ptr->next;
				}
			}
		 printf(" NULL \n");
		}
	sleep(4);
	}fflush(stdin);
}

struct data *find(int dom){
	system("cls");
	struct data *ptr;
	int choose, flag=0;
	char search[50];
	ptr=buku_telepon[dom]->next;

	printf("\n 	Cari Melalui		");
	printf("\n\n 1. Nama				");
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
				printf("\n\033[0;32m [Kontak Ditemukan] \033[0m\n\n");
				printf("\033[0;36m Identitas Kontak  \033[0m ");
				printf("\n Nama Kontak	: %s" , ptr->nama);
				printf("\n Nomor Telepon	: %s",  ptr->nomber);
				printf("\n Alamat Kontak	: %s",  ptr->alamat);
				printf("\n Catatan Kontak	: %s\n",  ptr->catatan);
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
				printf("\n\033[0;32m [Kontak Ditemukan] \033[0m\n\n");
				printf("\033[0;36m Identitas Kontak  \033[0m ");
				printf("\n Nama Kontak	: %s" , ptr->nama);
				printf("\n Nomor Telepon	: %s",  ptr->nomber);
				printf("\n Alamat Kontak	: %s",  ptr->alamat);
				printf("\n Catatan Kontak	: %s\n",  ptr->catatan);
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
sleep(4);
}
