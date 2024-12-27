#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

template <typename T> void natural_merge_sort(const char* file_name) {
	std::ifstream fin(file_name);
	int n;
	if (!(fin >> n)) {
		fin.close();
	}
	else {
		FILE* main_file = fopen(file_name, "r+");
		FILE* file_1 = fopen("file_1.txt", "w+");
		FILE* file_2 = fopen("file_2.txt", "w+");

		FILE* file_g1;
		FILE* file_g2;

		int quantity_el_mail = 0;
		int quantity_el_sub1 = 0;
		int quantity_el_sub2 = 0;

		T number = 0;
		int counter = 1;

		if (main_file != NULL) {
			while (feof(main_file) == false) {
				fscanf(main_file, "%f ", &number);
				quantity_el_mail++;
			}
		}
		else {
			std::cout << "error" << std::endl;
		}

		fclose(main_file);

		main_file = fopen(file_name, "r");
		file_1 = fopen("file_1.txt", "w+");
		file_2 = fopen("file_2.txt", "w+");

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
					quantity_el_sub2++;
				}
				turn *= -1;
			}
		}

		fclose(main_file);
		fclose(file_1);
		fclose(file_2);


		turn = 1;

		T number_1;
		T number_2;


		while (counter < quantity_el_mail and quantity_el_mail > 1) {

			if (turn == 1) {
				file_1 = fopen("file_1.txt", "r");
				file_2 = fopen("file_2.txt", "r");
				file_g1 = fopen("file_g1.txt", "w");
				file_g2 = fopen("file_g2.txt", "w");
				turn = -1;

				if (!feof(file_1)) {
					fscanf(file_1, "%f", &number_1);
				}
				if (!feof(file_2)) {
					fscanf(file_2, "%f", &number_2);
				}

				int turn_2 = 1;
				while (!feof(file_1) and !feof(file_2)) {
					if (turn_2 == 1) {
						int i = 0;
						int j = 0;
						while (i < counter and j < counter and !feof(file_1) and !feof(file_2)) {
							if (number_1 < number_2) {
								fprintf(file_g1, "%f ", number_1);
								fscanf(file_1, "%f", &number_1);
								i++;
							}
							else {
								fprintf(file_g1, "%f ", number_2);
								fscanf(file_2, "%f", &number_2);
								j++;
							}
						}

						while (i < counter and !feof(file_1)) {
							fprintf(file_g1, "%f ", number_1);
							fscanf(file_1, "%f", &number_1);
							i++;
						}

						while (j < counter and !feof(file_2)) {
							fprintf(file_g1, "%f ", number_2);
							fscanf(file_2, "%f", &number_2);
							j++;
						}

						turn_2 = -1;
					}

					else if (turn_2 == -1) {
						int i = 0;
						int j = 0;
						while (i < counter and j < counter and !feof(file_1) and !feof(file_2)) {
							if (number_1 < number_2) {
								fprintf(file_g2, "%f ", number_1);
								fscanf(file_1, "%f", &number_1);
								i++;
							}
							else {
								fprintf(file_g2, "%f ", number_2);
								fscanf(file_2, "%f", &number_2);
								j++;
							}
						}

						while (i < counter and !feof(file_1)) {
							fprintf(file_g2, "%f ", number_1);
							fscanf(file_1, "%f", &number_1);
							i++;
						}

						while (j < counter and !feof(file_2)) {
							fprintf(file_g2, "%f ", number_2);
							fscanf(file_2, "%f", &number_2);
							j++;
						}

						turn_2 = 1;
					}
				}

				if (turn_2 == 1) {
					if (!feof(file_1)) {
						while (!feof(file_1)) {
							fprintf(file_g1, "%f ", number_1);
							fscanf(file_1, "%f", &number_1);
						}
					}
					else {
						while (!feof(file_2)) {
							fprintf(file_g1, "%f ", number_2);
							fscanf(file_2, "%f", &number_2);
						}
					}
				}

				else if (turn_2 == -1) {
					if (!feof(file_1)) {
						while (!feof(file_1)) {
							fprintf(file_g2, "%f ", number_1);
							fscanf(file_1, "%f", &number_1);
						}
					}
					else {
						while (!feof(file_2)) {
							fprintf(file_g2, "%f ", number_2);
							fscanf(file_2, "%f", &number_2);
						}
					}
				}

				counter *= 2;


				fclose(file_1);
				fclose(file_2);
				fclose(file_g1);
				fclose(file_g2);
			}

			else if (turn == -1) {
				file_1 = fopen("file_1.txt", "w");
				file_2 = fopen("file_2.txt", "w");
				file_g1 = fopen("file_g1.txt", "r");
				file_g2 = fopen("file_g2.txt", "r");

				turn = 1;

				if (!feof(file_g1)) {
					fscanf(file_g1, "%f", &number_1);
				}
				if (!feof(file_g2)) {
					fscanf(file_g2, "%f", &number_2);
				}

				int turn_2 = 1;

				while (!feof(file_g1) and !feof(file_g2)) {
					if (turn_2 == 1) {
						int i = 0;
						int j = 0;
						while (i < counter and j < counter and !feof(file_g1) and !feof(file_g2)) {
							if (number_1 < number_2) {
								fprintf(file_1, "%f ", number_1);
								fscanf(file_g1, "%f", &number_1);
								i++;
							}
							else {
								fprintf(file_1, "%f ", number_2);
								fscanf(file_g2, "%f", &number_2);
								j++;
							}
						}

						while (i < counter and !feof(file_g1)) {
							fprintf(file_1, "%f ", number_1);
							fscanf(file_g1, "%f", &number_1);
							i++;
						}

						while (j < counter and !feof(file_g2)) {
							fprintf(file_1, "%f ", number_2);
							fscanf(file_g2, "%f", &number_2);
							j++;
						}

						turn_2 = -1;
					}
					else if (turn_2 == -1) {
						int i = 0;
						int j = 0;
						while (i < counter and j < counter and !feof(file_g1) and !feof(file_g2)) {
							if (number_1 < number_2) {
								fprintf(file_2, "%f ", number_1);
								fscanf(file_g1, "%f", &number_1);
								i++;
							}
							else {
								fprintf(file_2, "%f ", number_2);
								fscanf(file_g2, "%f", &number_2);
								j++;
							}
						}


						while (i < counter and !feof(file_g1)) {
							fprintf(file_2, "%f ", number_1);
							fscanf(file_g1, "%f", &number_1);
							i++;
						}

						while (j < counter and !feof(file_g2)) {
							fprintf(file_2, "%f ", number_2);
							fscanf(file_g2, "%f", &number_2);
							j++;
						}

						turn_2 = 1;
					}
				}

				if (turn_2 == 1) {
					if (!feof(file_g1)) {
						while (!feof(file_g1)) {
							fprintf(file_1, "%f ", number_1);
							fscanf(file_g1, "%f", &number_1);
						}
					}
					else {
						while (!feof(file_g2)) {
							fprintf(file_1, "%f ", number_2);
							fscanf(file_g2, "%f", &number_2);
						}
					}
				}
				else if (turn_2 == -1) {
					if (!feof(file_g1)) {
						while (!feof(file_g1)) {
							fprintf(file_2, "%f ", number_1);
							fscanf(file_g1, "%f", &number_1);
						}
					}
					else {
						while (!feof(file_g2)) {
							fprintf(file_2, "%f ", number_2);
							fscanf(file_g2, "%f", &number_2);
						}
					}
				}

				counter *= 2;

				fclose(file_1);
				fclose(file_2);
				fclose(file_g1);
				fclose(file_g2);
			}

		}

		if (turn == 1) {
			main_file = fopen(file_name, "w+");
			file_1 = fopen("file_1.txt", "r");

			while (!feof(file_1)) {
				fscanf(file_1, "%f ", &number_1);
				fprintf(main_file, "%f ", number_1);
			}

			fclose(main_file);
			fclose(file_1);
		}
		else {
			main_file = fopen(file_name, "w+");
			file_g1 = fopen("file_g1.txt", "r");

			while (!feof(file_g1)) {
				fscanf(file_g1, "%f ", &number_1);
				fprintf(main_file, "%f ", number_1);
			}

			fclose(main_file);
			fclose(file_g1);
		}
	}
}