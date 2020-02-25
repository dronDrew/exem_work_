#pragma once
#include"dependies.h"


class file_mamager
{
	std::filesystem::path curent_place;
public:
	file_mamager();//done
	void Print_directory();//done
	void Create_directory();//done
	void Create_file();
	void Delete_file_and_directory();
	void find_file_or_directory();
	void Count_sixe_of_directory();
};

