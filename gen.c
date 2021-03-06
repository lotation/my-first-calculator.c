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
	fprintf(fp, "\tprintf(\"WELCOME ð TO MY ðļ FIRST ð CALCULATOR ðēð°  ;) \\n\");\n");
	fprintf(fp, "\tprintf(\"MAXIMUM NUMBER ðĶðą AVIALIABLE: %d ðŊ\\n\");\n", max_num);
	fprintf(fp, "\tprintf(\"CURRENTLY THERE ð ARE ONLY ðĢ THESE ðą OPERATIONS AVAILABLE ðĒðĐ \\n\");\n");
	fprintf(fp, "\tprintf(\"K IT'S SAD ððĶ BUT IM ðĄ WORKING TO GET ðū EVERY ðŊðĪŽ OPERATION WORKING ðĐð―âðŦðĒ WITH EVERY ð NUMBER ðą\\n\");\n");
	fprintf(fp, "\tprintf(\"(YEAH, âð FLOATS TOO!!) ð \\n\");\n");
	for (size_t i = 0; calc_operators[i].symbol != '\0'; i++)
		fprintf(fp, "\tprintf(\"\\t%ld) %c \\n\");\n", i+1, calc_operators[i].symbol);
	
	fprintf(fp, "\tprintf(\"\\n\\n\");\n");
	fprintf(fp, "\tprintf(\"ðĶ /   OK ðĪŠð LESSSGO!! (LOL ð DABABY MEME) ðļ  ) \\n\");\n");
	fprintf(fp, "\tprintf(\"WRITE THE FIRST ðĨ NUMBER ðĒ:  \");\n");
	fprintf(fp, "\tscanf(\" %%d\", &a);\n");
	fprintf(fp, "\tprintf(\"WRITE THE OPERATION âĻ YOU WANT ð ME ðž TO CALCULATE ðŦ (e.g. +):  \");\n");
	fprintf(fp, "\tscanf(\" %%c\", &operation);\n");
	fprintf(fp, "\tprintf(\"WRITE THE SECOND ðĨ NUMBER ðĒ:  \");\n");
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
	fprintf(fp, "\tprintf(\"THANK ð YOU ð FOR ðšðĪ USING ðĪģðŧ MY CALCULATOR ð°\\n\");\n");
	fprintf(fp, "\tprintf(\"BYE ð BYE ð\\n\");\n");
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