#include<stdio.h>
#include<string.h>

struct mineralWater{
	char merk[5];
	int size;
};

struct carboWater{
	char merk[5];
	int size;
	char powder[35];
};


struct mineralWater mineral[100];//buat mineralWater
struct carboWater carbo[100];//buat carbonated
int min_count = 0, carbo_count = 0;//buat ngecek uda ada ga di store, klo uda ada ga ditambain lg


void storeMineral(){
	printf("Mineral Water\n");
	printf("==========================\n");
	printf("No. Merk \t Size\n");
	
	for(int i=0; i<min_count; i++){
		if(min_count==0){
			printf("\n");
			break;
		}else{
			printf("%d %4s %13d\n", i+1, mineral[i].merk, mineral[i].size);
		}
	}
	printf("\n");
}


void inNew(){
	char merk[5];
	int size;
	
	printf("Mineral Water\n");
	printf("==========================\n");
	
	do{//MASUKIN MERKKKK
		printf("Merk [2] ? ");
		scanf("%[^\n]", &merk); getchar();
	}while(strlen(merk)!=2);
	
	do{
		printf("Size [240/600/1500] ml? ");
		scanf("%d", &size); getchar();
	}while(size!=240 && size!=600 && size!=1500);
	
	if(min_count>0){//klo uda ada inputan sebelum e, dicek dulu sama ga
		for(int i=0; i<min_count; i++){
			if(strcmp(mineral[i].merk, merk) == 0 && mineral[i].size == size){//strcmp == 0 brarti kedua string e sama
				printf("Sudah ada minuman %s size %d ml\n", merk, size);
				break;//biar klo dah jalan yg ini ga ke yg bawah
			}else{
				printf("Minuman %s %d ml berhasil ditambahkan!", merk, size);
				strcpy(mineral[min_count].merk, merk);
				mineral[min_count].size = size;
				min_count++;
				break;
			}
		}
	}else{//klo belom ada inputan samsek
		printf("Minuman %s %d ml berhasil ditambahkan!", merk, size);
		strcpy(mineral[min_count].merk, merk);
		mineral[min_count].size = size;
		min_count++;
	}
	
	getchar();
	storeMineral();
	
//	3.	Pada Menu 1, minta user memasukkan merk dan size dari Mineral Water. 
//	a.	Validasi merk hanya boleh 2 karakter
//	b.	Validasi size hanya boleh 240, 600 atau 1500
//	c.	Validasikan juga tidak boleh ada merk dan size yang sama.
}
	
	
void mngMenu(){
	int choice;
	
	if(min_count==0){
		printf("Tidak ada produk\n");
		getchar(); getchar();
		storeMineral();
	}else{
		printf("Manage Menu\n");
		printf("==============\n");
		printf("1. Edit\n");
		printf("2. Delete\n");
		
		do{
			printf("Choice : \n");
			scanf("%d", &choice); getchar();
		}while(choice!=1 && choice!=2);
		
		switch(choice){
			case 1:{//EDITTTTTTT
				int choice, size;
				char merk[5];
				
				do{
					printf("Produk mana yang anda mau edit [1..%d] : ", min_count);
					scanf("%d", &choice); getchar();
				}while(choice<1 || choice>min_count);
				
				do{//MASUKIN MERKKKK
					printf("Merk [2] ? ");
					scanf("%[^\n]", &merk); getchar();
				}while(strlen(merk)!=2);
				
				do{
					printf("Size [240/600/1500] ml? ");
					scanf("%d", &size); getchar();
				}while(size!=240 && size!=600 && size!=1500);
				
				for(int i=0; i<min_count; i++){
					if(strcmp(mineral[i].merk, merk) == 0 && mineral[i].size == size){//strcmp == 0 brarti kedua string e sama
						printf("Sudah ada minuman %s size %d ml\n", merk, size);
						break;//biar klo dah jalan yg ini ga ke yg bawah
					}else{
						printf("Minuman menjadi %s %d ml berhasil!", merk, size);
						strcpy(mineral[choice-1].merk, merk);
						min_count++;
						break;
					}
				}
				
				getchar();
				storeMineral();
				break;
			}
			
			case 2:{//DELETEEEEEEEE
				int choice;
				
				do{
					printf("Produk mana yang anda mau delete [1..%d] : ", min_count);
					scanf("%d", &choice); getchar();
				}while(choice<1 || choice>min_count);
				
				for(int i=choice-1; i<=min_count-1; i++){
					strcpy(mineral[i].merk, mineral[i+1].merk);
					mineral[i].size = mineral[i+1].size;
				}
				min_count--;
				printf("Berhasil dihapus!\n");
				
				getchar(); getchar();
				storeMineral();
				break;
			}
		}
		printf("\n");
	}	
}


void storeCarbo(){
	printf("Carbonated Water\n");
	printf("==========================\n");
	printf("No. Merk \t Powder \t Size\n");
	
	for(int i=0; i<carbo_count; i++){
		if(carbo_count==0){
			printf("\n");
			break;
		}else{
			printf("%d %4s %15s \t \t %d\n", i+1, carbo[i].merk, carbo[i].powder, carbo[i].size);
		}
	}
	printf("\n");
}


void newCarbo(){
	char merk[5];
	int size;
	char powder[35];
	
	printf("Carbonated Water\n");
	printf("==========================\n");
	
	do{//MASUKIN MERKKKK
		printf("Merk [2] ? ");
		scanf("%[^\n]", &merk); getchar();
	}while(strlen(merk)!=2);
	
	do{
		printf("Size [240/600/1500] ml? ");
		scanf("%d", &size); getchar();
	}while(size!=240 && size!=600 && size!=1500);
	
	do{
		printf("Carbonated Powder [2..30] ? ");
		scanf("%[^\n]", &powder); getchar();
	}while(strlen(powder)<2 && strlen(powder)>30);
	
	if(carbo_count>0){//ada inputan
		for(int i=0; i<carbo_count; i++){
			if(strcmp(carbo[i].merk, merk) == 0 && strcmp(carbo[i].powder, powder) == 0 && carbo[i].size == size){
				printf("Sudah ada minuman %s size %d ml berkarbonasi %s\n", merk, size, powder);
				break;
			}else{
				printf("Minuman %s berkarbonasi %s %d ml berhasil ditambahkan!\n", merk, powder, size);
				strcpy(carbo[carbo_count].merk, merk);
				strcpy(carbo[carbo_count].powder, powder);
				carbo[carbo_count].size = size;
				carbo_count++;
				break;
			}
		}
	}else{//belom ada inputan
		printf("Minuman %s berkarbonasi %s %d ml berhasil ditambahkan!\n", merk, powder, size);
		strcpy(carbo[carbo_count].merk, merk);
		strcpy(carbo[carbo_count].powder, powder);
		carbo[carbo_count].size = size;
		carbo_count++;
	}
	
	getchar();
	storeCarbo();
}


void mngCarbo(){
	int choice;
	
	if(carbo_count==0){
		printf("Tidak ada produk\n");
		getchar(); getchar();
		storeCarbo();
	}else{
		printf("Manage Menu\n");
		printf("==============\n");
		printf("1. Edit\n");
		printf("2. Delete\n");
		
		do{
			printf("Choice : \n");
			scanf("%d", &choice); getchar();
		}while(choice!=1 && choice!=2);
		
		switch(choice){
			case 1:{//EDITTTTTTT
				int choice, size;
				char merk[5], powder[35];
				
				do{
					printf("Produk mana yang anda mau edit [1..%d] : ", carbo_count);
					scanf("%d", &choice); getchar();
				}while(choice<1 || choice>carbo_count);
				
				do{//MASUKIN MERKKKK
					printf("Merk [2] ? ");
					scanf("%[^\n]", &merk); getchar();
				}while(strlen(merk)!=2);
				
				do{
					printf("Size [240/600/1500] ml? ");
					scanf("%d", &size); getchar();
				}while(size!=240 && size!=600 && size!=1500);
				
				do{
					printf("Carbonated Powder [2..30] ? ");
					scanf("%[^\n]", &powder); getchar();
				}while(strlen(powder)<2 && strlen(powder)>30);
				
				for(int i=0; i<min_count; i++){
					if(strcmp(carbo[i].merk, merk) == 0 && carbo[i].size == size && strcmp(carbo[i].powder, powder) == 0){//strcmp == 0 brarti kedua string e sama
						printf("Sudah ada minuman %s size %d ml\n", merk, size);
						break;//biar klo dah jalan yg ini ga ke yg bawah
					}else{
						printf("Minuman menjadi %s %d ml berhasil!", merk, size);
						strcpy(carbo[choice-1].merk, merk);
						strcpy(carbo[choice-1].powder, powder);
						carbo[choice-1].size = size;
						break;
					}
				}
				
				getchar();
				storeCarbo();
				break;
			}
			
			case 2:{//DELETEEEEEEEE
				int choice;
				
				do{
					printf("Produk mana yang anda mau delete [1..%d] : ", carbo_count);
					scanf("%d", &choice); getchar();
				}while(choice<1 || choice>carbo_count);
				
				for(int i=choice-1; i<=carbo_count-1; i++){
					strcpy(carbo[i].merk, carbo[i+1].merk);
					carbo[i].size = carbo[i+1].size;
					strcpy(carbo[i].powder, carbo[i+1].powder);
				}
				carbo_count--;
				printf("Berhasil dihapus!\n");
				
				getchar();
				storeCarbo();
				break;
			}
		}
		printf("\n");
	}	
}



	
int main(){
	char title[25] = {"Juragan Air"};
	printf("%50s\n\n", title);
	
	while(1){
		printf("Menu :");
		printf("==========================\n");
		printf("1. Insert New\n");
		printf("2. Manage Products\n");
		printf("3. Insert New Carbonated\n");
		printf("4. Manage Carbonated Products\n");
		printf("5. Exit\n");
		
		int choice;
		printf("Choice : ");
		scanf("%d", &choice); getchar();
		
		switch(choice){
			case 1:{
				inNew();
				break;
			}
			case 2:{
				mngMenu();
				break;
			}
			case 3:{
				newCarbo();
				break;
			}
			case 4:{
				mngCarbo();
				break;
			}
			case 5:{
				return 0;
			}
		}
	}
	
	
	return 0;
}


	
