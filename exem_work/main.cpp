#include "dependies.h"
#include"file_mamager.h"
using namespace std;

int main() {
	file_mamager test;
	test.Print_directory();
	test.Create_directory();
//	test.Print_directory();
	test.Create_file();
	test.Print_directory();
	return 0;

}