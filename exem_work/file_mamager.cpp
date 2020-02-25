#include "file_mamager.h"
file_mamager::file_mamager() {
	this->curent_place =std::filesystem::current_path();
}
void file_mamager::Print_directory() {
	try
	{

	
	std::cout << "You in  directory : " << this->curent_place.u8string() <<"\nIn this directory is such element :"<< std::endl;
	std::filesystem::recursive_directory_iterator begin(this->curent_place);
	std::filesystem::recursive_directory_iterator end;
	std::vector<std::filesystem::path> subdirs;
	std::copy_if(begin, end, std::back_inserter(subdirs), [](const std::filesystem::path& path) {
		return std::filesystem::is_directory(path) || std::filesystem::is_regular_file(path);
		});
	for (auto elem : subdirs)
	{
		std::cout << elem.filename() << std::endl;
	}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return;
	}
}
void file_mamager::Create_directory() {
	std::string temp;
	std::cout << "Enter path and name of directory for creating\n";
	std::cin >> temp;
	this->curent_place = temp;
	std::filesystem::create_directories(this->curent_place);
}
void file_mamager::Create_file() {
	std::string filename;
	std::cout << "Enter file name with extension to create file in curent directory : \n" << this->curent_place << std::endl;
	std::cin >> filename;
	std::fstream file;
	auto temp = this->curent_place;
	temp += "\\"+filename;
	std::cout << temp << std::endl;
	file.open(temp,std::ios::out);
	if (file.is_open()) {
		std::cout << "Succse\n";
	}
}
void file_mamager::Delete_file_and_directory() {
	std::filesystem::remove_all(this->curent_place);
	this->curent_place = this->curent_place.parent_path();
	std::cout << this->curent_place << std::endl;
}
void file_mamager::Delete_file() {
	this->Print_directory();
	std::string temp;
	std::cout << "Print name of file to deleting\n";
	std::cin >> temp;
	auto temp1 = this->curent_place;
	temp1+='\\';
	temp1 += temp;
	std::filesystem::remove(temp1);
	//this->curent_place = this->curent_place.parent_path();
	std::cout << this->curent_place << std::endl;
}

void file_mamager::find_file_or_directory() {}
void file_mamager::Count_size_of_directory() {}