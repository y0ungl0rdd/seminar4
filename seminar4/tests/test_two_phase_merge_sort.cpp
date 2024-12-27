#define _CRT_SECURE_NO_WARNINGS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "two_phase_merge_sort.h"

TEST_CASE("Two phase: Normal file") {
	two_phase_merge_sort<float>("normal.txt");

	FILE* file_1 = fopen("normal.txt", "r+");

	float number_1;
	float number_2;
	int file_1_length = 0;

	if (file_1 != NULL) {
		while (feof(file_1) == false) {
			file_1_length++;
			fscanf(file_1, "%f ", &number_1);
		}
	}

	fclose(file_1);
	fopen("normal.txt", "r+");

	fscanf(file_1, "%f ", &number_1);
	for (int i = 1; i < file_1_length; i++) {
		fscanf(file_1, "%f ", &number_2);
		if (number_1 > number_2) {
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}
}

TEST_CASE("Two phase: Reverse file") {
	two_phase_merge_sort<float>("reverse.txt");
	FILE* file = fopen("reverse.txt", "r+");

	float number_1;
	float number_2;
	int file_length = 0;

	if (file != NULL) {
		while (feof(file) == false) {
			file_length++;
			std::ignore = fscanf(file, "%f ", &number_1);
		}
	}

	fclose(file);
	fopen("reverse.txt", "r+");


	fscanf(file, "%f ", &number_1);
	for (int i = 1; i < file_length - 1; i++) {
		fscanf(file, "%f ", &number_2);
		if (number_1 > number_2) {
			std::cout << number_1 << " " << number_2;
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}
}

TEST_CASE("Two phase: Similar file") {
	two_phase_merge_sort<float>("similar.txt");
	FILE* file = fopen("similar.txt", "r+");

	float number_1;
	float number_2;
	int file_length = 0;

	if (file != NULL) {
		while (feof(file) == false) {
			file_length++;
			fscanf(file, "%f ", &number_1);
		}
	}

	fclose(file);
	fopen("similar.txt", "r+");

	fscanf(file, "%f ", &number_1);
	for (int i = 1; i < file_length - 1; i++) {
		fscanf(file, "%f ", &number_2);
		if (number_1 > number_2) {
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}
}

TEST_CASE("Two phase: Empty file") {
	two_phase_merge_sort<float>("empty.txt");
	FILE* file = fopen("empty.txt", "r+");

	float number_1;
	float number_2;
	int file_length = 0;

	if (file != NULL) {
		while (feof(file) == false) {
			file_length++;
			fscanf(file, "%f ", &number_1);
		}
	}

	fclose(file);
	fopen("empty.txt", "r+");

	fscanf(file, "%f ", &number_1);
	for (int i = 1; i < file_length - 1; i++) {
		fscanf(file, "%f ", &number_2);
		if (number_1 > number_2) {
			REQUIRE(false);
			break;
		}
		number_1 = number_2;
	}
}