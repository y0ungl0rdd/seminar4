#define _CRT_SECURE_NO_WARNINGS
#include "catch.hpp"
#include "one_phase_merge_sort.h"

TEST_CASE("One phase: Normal file (one phase)") {
	one_phase_merge_sort<float>("normal.txt");

	FILE* file_1 = fopen("normal.txt", "r+");

	float number_1;
	float number_2;
	int file_1_length = 0;

	if (file_1 != NULL) {
		while (fscanf(file_1, "%f ", &number_1) == 1) {
			file_1_length++;
		}
	}

	if (file_1 != NULL) {
		fclose(file_1);
	}

	file_1 = fopen("normal.txt", "r+");

	if (fscanf(file_1, "%f ", &number_1) != 1) {
		REQUIRE(false);
	}

	for (int i = 1; i < file_1_length; i++) {
		if (fscanf(file_1, "%f ", &number_2) != 1) {
			REQUIRE(false);
			break;
		}
		if (number_1 > number_2) {
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}

	if (file_1 != NULL) {
		fclose(file_1);
	}
}

TEST_CASE("One phase: Reverse file (one phase)") {
	one_phase_merge_sort<float>("reverse.txt");
	FILE* file = fopen("reverse.txt", "r+");

	float number_1;
	float number_2;
	int file_length = 0;

	if (file != NULL) {
		while (fscanf(file, "%f ", &number_1) == 1) {
			file_length++;
		}
	}

	if (file != NULL) {
		fclose(file);
	}

	file = fopen("reverse.txt", "r+");

	if (fscanf(file, "%f ", &number_1) != 1) {
		REQUIRE(false);
	}

	for (int i = 1; i < file_length - 1; i++) {
		if (fscanf(file, "%f ", &number_2) != 1) {
			REQUIRE(false);
			break;
		}
		if (number_1 > number_2) {
			std::cout << number_1 << " " << number_2;
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}

	if (file != NULL) {
		fclose(file);
	}
}

TEST_CASE("One phase: Similar file (one phase)") {
	one_phase_merge_sort<float>("similar.txt");
	FILE* file = fopen("similar.txt", "r+");

	float number_1;
	float number_2;
	int file_length = 0;

	if (file != NULL) {
		while (fscanf(file, "%f ", &number_1) == 1) {
			file_length++;
		}
	}

	if (file != NULL) {
		fclose(file);
	}

	file = fopen("similar.txt", "r+");

	if (fscanf(file, "%f ", &number_1) != 1) {
		REQUIRE(false);
	}

	for (int i = 1; i < file_length - 1; i++) {
		if (fscanf(file, "%f ", &number_2) != 1) {
			REQUIRE(false);
			break;
		}
		if (number_1 > number_2) {
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}

	if (file != NULL) {
		fclose(file);
	}
}

TEST_CASE("One phase: Empty file (one phase)") {
	one_phase_merge_sort<float>("empty.txt");
	FILE* file = fopen("empty.txt", "r+");

	float number_1;
	float number_2;
	int file_length = 0;

	if (file != NULL) {
		while (fscanf(file, "%f ", &number_1) == 1) {
			file_length++;
		}
	}

	if (file != NULL) {
		fclose(file);
	}

	file = fopen("empty.txt", "r+");

	if (fscanf(file, "%f ", &number_1) != 1) {
		REQUIRE(true);
	}

	for (int i = 1; i < file_length - 1; i++) {
		if (fscanf(file, "%f ", &number_2) != 1) {
			REQUIRE(false);
			break;
		}
		if (number_1 > number_2) {
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}

	if (file != NULL) {
		fclose(file);
	}
}
