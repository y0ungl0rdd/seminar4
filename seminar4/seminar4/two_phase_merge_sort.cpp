#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

template <typename T> void two_phase_merge_sort(const char* file_name) {
	std::ifstream fin("input.txt");
	int n;
	if (!(fin >> n)) {
		fin.close();
	}
	else {
		FILE* main_file = fopen(file_name, "r+");
		FILE* file_1 = fopen("file_1.txt", "w+");
		FILE* file_2 = fopen("file_2.txt", "w+");

		int quantity_el_main = 0;
		int quantity_el_sub1 = 0;
		int count_el_sub2 = 0;

		T number = 0;
		int counter = 1;

		if (main_file != NULL) {
			while (feof(main_file) == false) {
				fscanf(main_file, "%f ", &number);
				quantity_el_main++;
			}
		}

		else {
			std::cout << "error" << std::endl;
		}

		fclose(main_file);

		while (counter < quantity_el_main) {

			main_file = fopen(file_name, "r");
			file_1 = fopen("file_1.txt", "w");
			file_2 = fopen("file_2.txt", "w");

			int turn = 1;
			number = 0;

			while (!feof(main_file)) {
				if (turn == 1) {
					for (int i = 0; i < counter and !feof(main_file); i++) {
						fscanf(main_file, "%f ", &number);
						fprintf(file_1, "%f ", number);
						quantity_el_sub1++;
					}
					turn *= -1;
				}
				else {
					for (int j = 0; j < counter and !feof(main_file); j++) {
						fscanf(main_file, "%f ", &number);
						fprintf(file_2, "%f ", number);
						count_el_sub2++;
					}
					turn *= -1;
				}
			}

			fclose(main_file);
			fclose(file_1);
			fclose(file_2);

			main_file = fopen(file_name, "w");
			file_1 = fopen("file_1.txt", "r");
			file_2 = fopen("file_2.txt", "r");

			int i = 0;
			int j = 0;

			T number_1;
			T number_2;

			if (!feof(file_1)) {
				fscanf(file_1, "%f", &number_1);
			}
			if (!feof(file_2)) {
				fscanf(file_2, "%f", &number_2);
			}

			while (!feof(file_1) and !feof(file_2)) {
				i = 0;
				j = 0;

				while (i < counter and j < counter and !feof(file_1) and !feof(file_2)) {

					if (number_1 < number_2) {
						fprintf(main_file, "%f ", number_1);
						fscanf(file_1, "%f", &number_1);
						i++;
					}

					else {
						fprintf(main_file, "%f ", number_2);
						fscanf(file_2, "%f", &number_2);
						j++;
					}
				}

				while (i < counter and !feof(file_1)) {
					fprintf(main_file, "%f ", number_1);
					fscanf(file_1, "%f", &number_1);
					i++;
				}

				while (j < counter and !feof(file_2)) {
					fprintf(main_file, "%f ", number_2);
					fscanf(file_2, "%f", &number_2);
					j++;
				}
			}
			while (!feof(file_1)) {
				fprintf(main_file, "%f ", number_1);
				fscanf(file_1, "%f", &number_1);
			}
			while (!feof(file_2)) {
				fprintf(main_file, "%f ", number_2);
				fscanf(file_2, "%f", &number_2);
			}
			fclose(file_1);
			fclose(file_2);
			fclose(main_file);
			counter *= 2;
		}
	}
}