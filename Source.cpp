#include <stdio.h>
#include <windows.h>
#pragma warning(disable: 4996)
#define SIZE_NAME 30
char* creator(FILE*);
void menuTxt(FILE*);
int checkNameOfFile(char*);
char* findFile();
void printFile(FILE*, char*);
void averageF(FILE* file, char* nameOfFile);
void scanfMod(int& number);
void swap(FILE* file, char*);
void revers(FILE* file, fpos_t begin, fpos_t end);
///////////////////
void chooseTypeFail(FILE* file);
void menuBin(FILE* file);
void addInfBin(FILE* file, char* NameOfFile);
char* creatorBin(FILE*);
char* findFileBin();
void printFileBin(FILE*, char*);
void multiples(FILE*, char*);
void shifting(FILE*, char*);
int checkNameOfFileBin(char*);
void continuationCondition();

int main() {

	FILE* file = nullptr;
	chooseTypeFail(file);
	printf("\nGood bye\n");
}
char* creator(FILE*file) {
	char* name;
	if (!(name = (char*)malloc(sizeof(char) * SIZE_NAME))) {
		printf("No memory.");
		return nullptr;
	}
	do {
		printf_s("Enter the name of a new file:\n");
		rewind(stdin);
		gets_s(name, SIZE_NAME);
		int result = checkNameOfFile(name);
		if (result == 1) break;
		else {
			printf("Your file should be in text formate. Please write a .txt in the end of file.\n");
			printf("Example: text.txt\n");
		}
	} while (1);
	file = fopen("name", "w");
	fclose(file);
	return name;
}
void addInf(FILE* file, char* nameOfFile) {
	int numbOrEnd = 0;
	file = fopen(nameOfFile, "a");
	printf("Hello, write the elements in your file:\n");
	printf("Write numbers in your file, if you want to stop enter 999:\n");
	do {
		scanfMod(numbOrEnd);
		if (numbOrEnd == 999) {
			break;
		}
		fprintf(file, "%d ", numbOrEnd);
	} while (1);
	fclose(file);
}
void menuTxt(FILE*file) {
	int number;
	char* nameOfFile, *headerName;
	nameOfFile = (char*)malloc(sizeof(char) * SIZE_NAME);
	headerName = (char*)malloc(sizeof(char) * SIZE_NAME);
	strcpy(nameOfFile, "File not found");
	do {
		if (nameOfFile == nullptr)
			strcpy(headerName, "File not found");
		else strcpy(headerName, nameOfFile);
		system("CLS");
		printf("======================================================================\n");
		printf("                        %s                                     \n", headerName);
		printf("======================================================================");
		printf("\nHello, what do you want to do?\n1.Create a new file.\n2.Find existing file.\n3.Add information in your file.\n4. Print your file\n5.Calculate average.\n6.Swap first and last.\n");
		printf("7.Exit.\n");
		printf("Enter a number: ");
		scanfMod(number);
		switch (number) {
		case 1:
			nameOfFile = creator(file);
			break;
		case 2:
			nameOfFile = findFile();
			break;
		case 3:
			addInf(file, nameOfFile);
			break;
		case 4:
			printFile(file, nameOfFile);
			break;
		case 5:
			averageF(file, nameOfFile);
			break;
		case 6:
			swap(file, nameOfFile);
			break;
		case 7:
			return;
		}
	} while (1);
}
int checkNameOfFile(char* name) {
	char* checker, *txt;
	if (!(txt = (char*)malloc(sizeof(char) * 5))) {
		printf("No memory.");
		return 0;
	}
	strcpy(txt, ".txt");
	int j = 0;
	if (!(checker = (char*)malloc(sizeof(char) * 5))) {
		printf("No memory.");
		return 0;
	}
	int countSymb = strlen(name);
	for (int i = countSymb - 4; *(name + i - 1) != '\0'; i++, j++) {
		checker[j] = name[i];
		if (j == 4)checker[j] = '\0';
	}
	int result = strcmp(checker, txt);
	if (result == 0) return 1;
	return 0;
}
char* findFile() {
	int num;
	FILE* file;
	char* name;
	if (!(name = (char*)malloc(sizeof(char) * SIZE_NAME))) {
		printf("No memory.");
		return nullptr;
	}
	do {
		system("CLS");
		printf_s("Enter the name of a exist file:\n");
		rewind(stdin);
		gets_s(name, SIZE_NAME);
		int result = checkNameOfFile(name);
		if (result == 1)
		{
			if (!(file = fopen(name, "rt"))) {
				system("CLS");
				printf("File not found. Check the correctness of the entered data.\nEnter any number to continue , else enter 0 for exit.\n");
				scanfMod(num);
				if (num == 0)
					return nullptr;
				else continue;
			}
			break;
		}

		else {
			printf("Your file should be in text formate. Please write a .txt in the end of file.\n");
			printf("Example: text.txt\n");
			system("CLS");
		}
	} while (1);
	return name;
}
void printFile(FILE*file, char* nameOfFile) {
	system("CLS");
	if (!(file = fopen(nameOfFile, "r"))) {
		printf("File is empty. Firstly enter information");
		continuationCondition();
		return;
	}
	int number;
	char string[255];
	printf("----------------------------------------------------------------------\n");
	printf("                        %s                                     \n", nameOfFile);
	printf("----------------------------------------------------------------------\n||");

	while (1) {
		//fscanf(file, "%d", &number);
		fgets(string, 255, file);
		printf("%s", string);
		//printf("%d ", number);
		if (feof(file))
			break;
	}
	printf("||");
	fclose(file);
	continuationCondition();
}
void averageF(FILE* file, char* nameOfFile) {// êð÷, ìîæíî íå ïåðåäîâàÿ óêàçàòåëü íà ôàéë, ïðîñòî âåçäå fopen
	file = fopen(nameOfFile, "r");
	int number, sum = 0, counter = 0;
	float average;
	while (!feof(file)) {
		fscanf(file, "%d", &number);
		sum += number;
		counter++;

	}
	average = (float)sum / (float)counter;
	printf_s("%.3f", average);
	fclose(file);
	continuationCondition();
}
void scanfMod(int& number) {
	do {
		if (!(scanf_s("%d", &number))) {
			printf("\n---------------------------!!!!!---------------------------\n");
			printf("               Error! Please write a number.               ");
			printf("\n---------------------------!!!!!---------------------------\n");
			printf("Enter again: ");
			rewind(stdin);
		}
		else break;
	} while (1);
}
void swap(FILE* file, char* nameOfFile) {
	file = fopen(nameOfFile, "r+");
	char symb;
	fpos_t begin = 0, end;
	//rewind(file);
	//while (1) {                  //Ïðîïóñê ïðîáåëîâ â íà÷àëå
	//	fscanf(file, "%c", &symb);
	//	if (symb == ' ') {
	//		fseek(file, -1, 1);
	//		fgetpos(file, &begin);
	//		break;
	//	}
	//}
	int i = 1;
	fseek(file, -1, 2);
	do {
		fscanf(file, "%c", &symb);
		if (symb == ' ') {
			fseek(file, -i, 1);
			fgetpos(file, &end);
			break;
		}
		fseek(file, -i, 1);
		if (i < 2)i++;
	} while (1);
	revers(file, begin, end);

	fclose(file);
	continuationCondition();
	fclose(file);
}
void revers(FILE* file, fpos_t begin, fpos_t end) {
	if (!file) return;
	fpos_t pos;
	char string[255];
	char numb;
	char changSymbBeg, changSymbEnd, symbBeg, symbEnd;
	while (1) {
		fseek(file, begin, 0);
		fgetpos(file, &pos);
		fscanf(file, "%c", &symbBeg);
		fgetpos(file, &pos);
		changSymbBeg = symbBeg;
		fseek(file, end, 0);
		fgetpos(file, &pos);
		//printf("%c", symbBeg);
		fscanf(file, "%c", &symbEnd);
		fgetpos(file, &pos);
		changSymbEnd = symbEnd;
		fseek(file, -1, 1);
		fgetpos(file, &pos);
		//printf("%c", symbEnd);
		fprintf(file, "%c", &changSymbBeg);
		fgetpos(file, &pos);
		//fseek(file, -1, 1);  //
		//fscanf(file, "%c", &numb); //
		//printf("%c", numb); // 
		fseek(file, begin, 0);
		fgetpos(file, &pos);
		fprintf(file, "%c", &changSymbEnd);
		fgetpos(file, &pos);
		//fseek(file, -1, 1);      //
		//fscanf(file, "%c", &numb); //
		//printf("%c", numb); ///
		begin++;
		end--;
		if (begin >= end) break;
	}
}


/////////////////////////////////////////////////////////

void chooseTypeFail(FILE* file) {
	int number;
	printf("Choose type of file.\n1.Text files.\n2.Binary files.\nEnter number: ");
	scanfMod(number);
	switch (number) {
	case 1:
		menuTxt(file);
		break;
	case 2:
		menuBin(file);
		break;
	}
}
void menuBin(FILE* file) {
	int number;
	char* nameOfFile, *headerName;
	nameOfFile = (char*)malloc(sizeof(char) * SIZE_NAME);
	headerName = (char*)malloc(sizeof(char) * SIZE_NAME);
	strcpy(nameOfFile, "File not found");
	do {
		if (nameOfFile == nullptr)
			strcpy(headerName, "File not found");
		else strcpy(headerName, nameOfFile);
		system("CLS");
		printf("======================================================================\n");
		printf("                        %s                                     \n", nameOfFile);
		printf("======================================================================");
		printf("\nHello, what do you want to do?\n1.Create a new file.\n2.Find existing file.\n3.Add information in your file.\n4. Print your file\n5.Calculate multiplies.\n6.Shifting elements.\n");
		printf("7.Exit.\n");
		printf("Enter a number: ");
		scanfMod(number);
		switch (number) {
		case 1:
			nameOfFile = creatorBin(file);
			break;
		case 2:
			nameOfFile = findFileBin();
			break;
		case 3:
			addInfBin(file, nameOfFile);
			break;
		case 4:
			printFileBin(file, nameOfFile);
			break;
		case 5:
			multiples(file, nameOfFile);
			break;
		case 6:
			shifting(file, nameOfFile);
			break;
		case 7:
			return;
		}
	} while (1);
}
char* creatorBin(FILE*file) {
	char* name;
	if (!(name = (char*)malloc(sizeof(char) * SIZE_NAME))) {
		printf("No memory.");
		return nullptr;
	}
	system("CLS");
	do {
		printf_s("Enter the name of a new file:\n");
		rewind(stdin);
		gets_s(name, SIZE_NAME);
		int result = checkNameOfFileBin(name);
		if (result == 1) break;
		else {
			printf("Your file should be in binary formate. Please write a .bin in the end of file.\n");
			printf("Example: file.bin\n");
		}
	} while (1);
	file = fopen("name", "w+b");
	fclose(file);
	return name;
}
char* findFileBin() {
	system("CLS");
	char* name;
	if (!(name = (char*)malloc(sizeof(char) * SIZE_NAME))) {
		printf("No memory.");
		return nullptr;
	}
	do {
		printf_s("Enter the name of a exist file:\n");
		rewind(stdin);
		gets_s(name, SIZE_NAME);
		int result = checkNameOfFileBin(name);
		if (result == 1) break;
		else {
			system("CLS");
			printf("Your file should be in binary formate. Please write a .bin in the end of file.\n");
			printf("Example: file.bin\n");
		}
	} while (1);
	return name;
}
int checkNameOfFileBin(char* name) {
	char* checker, *bin;
	if (!(bin = (char*)malloc(sizeof(char) * 5))) {
		printf("No memory.");
		return 0;
	}
	strcpy(bin, ".bin");
	int j = 0;
	if (!(checker = (char*)malloc(sizeof(char) * 5))) {
		printf("No memory.");
		return 0;
	}
	int countSymb = strlen(name);
	for (int i = countSymb - 4; *(name + i - 1) != '\0'; i++, j++) {
		checker[j] = name[i];
		if (j == 4)checker[j] = '\0';
	}
	int result = strcmp(checker, bin);
	if (result == 0) return 1;
	return 0;
}
void addInfBin(FILE* file, char* nameOfFile) {
	int numbOrEnd = 0;
	file = fopen(nameOfFile, "a+b");
	system("CLS");
	printf("Hello, write the elements in your file:\n");
	printf("Write numbers in your file, if you want to stop enter 999:\n");
	do {
		scanfMod(numbOrEnd);
		if (numbOrEnd == 999) break;
		fwrite(&numbOrEnd, sizeof(int), 1, file);
	} while (1);
	fclose(file);
}
void printFileBin(FILE* file, char* nameOfFile) {
	system("CLS");
	if(!(file = fopen(nameOfFile, "r+b"))){
		printf("File is empty. Firstly enter information");
		continuationCondition();
		return;
	}
	int number;
	printf("----------------------------------------------------------------------\n");
	printf("                        %s                                     \n", nameOfFile);
	printf("----------------------------------------------------------------------\n||");
	while (1) {
		fread(&number, sizeof(int), 1, file);
		if (feof(file))
			break;
		printf("%d ", number);
	}
	printf("||");
	fclose(file);
	continuationCondition();
}
void multiples(FILE*file, char*nameOfFile) {
	int number, numberFile, counter = 0;
	file = fopen(nameOfFile, "rb");
	printf("Enter the desired number:\n");
	scanfMod(number);
	printf("Your multiplies:\n | ");
	do {
		fread(&numberFile, sizeof(int), 1, file);
		if (numberFile == 0)
			continue;
		if (feof(file))
			break;
		if (numberFile % number == 0) {
			counter++;
			printf("%d ", numberFile);
		}
	} while (1);
	printf("|");
	printf("\nAmount = %d", counter);
	fclose(file);
	continuationCondition();
}
void shifting(FILE* file, char* nameOfFile) {
	file = fopen(nameOfFile, "r+b");
	fpos_t end = sizeof(int), begin;
	int number, null = 0;
	int	value;
	printf("Enter the number of shifts:\n");
	scanfMod(number);
	fseek(file, -4, 2);
	fgetpos(file, &begin);
	end = begin + sizeof(int)*number;
	while (1) {
		rewind(file);
		fseek(file, begin, 0);
		fread(&value, sizeof(int), 1, file);
		fseek(file, -4, 1);
		fwrite(&null, sizeof(int), 1, file);

		fseek(file, end, 0);
		fwrite(&value, sizeof(int), 1, file);
		begin = begin - sizeof(int);
		end = end - sizeof(int);
		if (begin < 0) break;
		/*fseek(file, begin, 0);
		fread(&value, sizeof(int), 1, file);
		fseek(file, -4, 1);
		fwrite(&null, sizeof(int), 1, file);
		begin = begin + sizeof(int)*number;
		fseek(file, begin, 0);
		fwrite(&value, sizeof(int), 1, file);
		begin = begin - sizeof(int)*(number + 1);
*/
	}
	fclose(file);
	printFileBin(file, nameOfFile);
}
void continuationCondition() {
	int num;
	printf("\nEnter any number to continue...  ");
	scanf_s("%d", &num);
	rewind(stdin);
}