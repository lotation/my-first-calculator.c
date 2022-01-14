#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define PROGRAM_NAME "calc-gen"
#define FILENAME     "my-first-calculator.c"

typedef double (*operation_)(double, double);
typedef struct operators_ {
	char symbol;
	operation_ operation;
} operators;

void usage(void);

double addition(double a, double b);
double subtraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);


int main(int argc, char *argv[]) {

	if (argc != 2)
		usage();

	if (atoi(argv[1]) <= 0 || atoi(argv[1]) > 1000)
		usage();

	
	setlocale(LC_CTYPE, "");

	const operators calc_operators[] =  {
		{'+', 	addition}, 
		{'-',	subtraction}, 
		{'*', 	multiplication},
		{'/', 	division},

		{'\0', (void *) NULL}
	};

	int max_num = atoi(argv[1]);
	
	FILE *fp;
	fp = fopen(FILENAME, "w");
	if (!fp) {
		fprintf(stderr, "Failed to open file.\n");
		perror("fopen failed: ");
	}

	fprintf(fp, "#include <stdio.h>\n\nint main()\n{\n");
	fprintf(fp, "\tint a;\n\tint b;\n\tchar operation;\n\n\n");
	fprintf(fp, "\tprintf(\"------------------------------------------------------------------------------------------------\\n\");\n");
	fprintf(fp, "\tprintf(\"WELCOME 😋 TO MY 👸 FIRST 👆 CALCULATOR 💲🎰  ;) \\n\");\n");
	fprintf(fp, "\tprintf(\"MAXIMUM NUMBER 🎦📱 AVIALIABLE: %d 💯\\n\");\n", max_num);
	fprintf(fp, "\tprintf(\"CURRENTLY THERE 😍 ARE ONLY 🐣 THESE 😱 OPERATIONS AVAILABLE 💢😩 \\n\");\n");
	fprintf(fp, "\tprintf(\"K IT'S SAD 😔🦍 BUT IM 😡 WORKING TO GET 🌾 EVERY 💯🤬 OPERATION WORKING 👩🏽‍🏫😢 WITH EVERY 👏 NUMBER 📱\\n\");\n");
	fprintf(fp, "\tprintf(\"(YEAH, ✅😜 FLOATS TOO!!) 😎 \\n\");\n");
	for (size_t i = 0; calc_operators[i].symbol != '\0'; i++)
		fprintf(fp, "\tprintf(\"\\t%ld) %c \\n\");\n", i+1, calc_operators[i].symbol);
	
	fprintf(fp, "\tprintf(\"\\n\\n\");\n");
	fprintf(fp, "\tprintf(\"💦 /   OK 🤪👀 LESSSGO!! (LOL 😆 DABABY MEME) 🐸  ) \\n\");\n");
	fprintf(fp, "\tprintf(\"WRITE THE FIRST 🥇 NUMBER 🔢:  \");\n");
	fprintf(fp, "\tscanf(\" %%d\", &a);\n");
	fprintf(fp, "\tprintf(\"WRITE THE OPERATION ✨ YOU WANT 😋 ME 😼 TO CALCULATE 🔫 (e.g. +):  \");\n");
	fprintf(fp, "\tscanf(\" %%c\", &operation);\n");
	fprintf(fp, "\tprintf(\"WRITE THE SECOND 🥈 NUMBER 🔢:  \");\n");
	fprintf(fp, "\tscanf(\" %%d\", &b);\n");
	fprintf(fp, "\n\n");

	for (size_t k = 0; calc_operators[k].symbol != '\0'; k++) {
		for (int i = 0; i <= max_num; i++) {
			for (int j = 0; j <= max_num; j++) {
				fprintf(fp, "\tif (a == %d && operation == '%c' && b == %d) {\n", i, calc_operators[k].symbol, j);
				fprintf(fp, "\t\tprintf(\"\\n%d %c %d = %.10g \\n\");\n", i, calc_operators[k].symbol, j, calc_operators[k].operation(i, j));
				fprintf(fp, "\t}\n"); 
			}
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n");
	}

	fprintf(fp, "\tprintf(\"\\n\\n\");\n");
	fprintf(fp, "\tprintf(\"THANK 🙏 YOU 👈 FOR 🎺🤗 USING 🤳🏻 MY CALCULATOR 🎰\\n\");\n");
	fprintf(fp, "\tprintf(\"BYE 👋 BYE 💝\\n\");\n");
	fprintf(fp, "\tprintf(\"------------------------------------------------------------------------------------------------\\n\");\n");
	
	fprintf(fp, "\n}\n");

	fclose(fp);


	return 0;
}

double addition(double a, double b) {
	return a + b;
}

double subtraction(double a, double b) {
	return a - b;
}

double multiplication(double a, double b) {
	return a * b;
}

double division(double a, double b) {
	return a / b;
}

void usage(void) {
	fprintf(stderr, "%s num\nWhere 0 < num <= 1000\n", PROGRAM_NAME);
	exit(EXIT_FAILURE);
}