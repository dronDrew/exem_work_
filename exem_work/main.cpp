#include "dependies.h"
#include"file_mamager.h"
using namespace std;

int main() {
	file_mamager test;
	test.Print_directory();
	test.Count_size_of_directory();
	test.Create_directory();
	//test.Print_directory();
	test.Create_file();
	test.Create_file();
	test.Create_file();
	//test.Print_directory();
	test.Delete_file();
	test.find_file_or_directory();
	test.Delete_file_and_directory();
	//test.Count_size_of_directory();
	//test.Print_directory();
	test.Create_directory();
	test.Create_file();
	test.Create_directory();
	test.move_file();
	test.move_directory();
	test.Create_directory();
	test.copy_file();
	test.copy_directory();
	return 0;

}