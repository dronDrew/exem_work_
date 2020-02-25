#include "file_mamager.h"
file_mamager::file_mamager() {
	this->curent_place =std::filesystem::current_path();
}
void file_mamager::Print_directory() {

	std::cout << "You in  directory : " << this->curent_place.u8string() <<"\nIn this directory is such element :"<< std::endl;
	std::filesystem::recursive_directory_iterator begin(this->curent_place.parent_path());
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
void file_mamager::Create_directory() {
	std::string temp;
	std::cout << "Enter path and name of directory for creating\n";
	std::cin >> temp;
	this->curent_place = temp;
	std::cout << this->curent_place << std::endl;
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