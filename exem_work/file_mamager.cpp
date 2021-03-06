#include "file_mamager.h"
file_mamager::file_mamager() {
    this->curent_place = std::filesystem::current_path();
}
void file_mamager::Print_directory() {
    try
    {


        std::cout << "You in  directory : " << this->curent_place.u8string() << "\nIn this directory is such element :" << std::endl;
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
    catch (const std::exception & ex)
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
    temp += "//" + filename;
    std::cout << temp << std::endl;
    file.open(temp, std::ios::out);
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
    std::filesystem::remove(temp1 / temp);
    //this->curent_place = this->curent_place.parent_path();
    std::cout << this->curent_place << std::endl;
}

void file_mamager::find_file_or_directory() {
    std::string key_name;
    std::cout << "Enter name of file for searching\n";
    std::cin >> key_name;
    try
    {
        std::filesystem::recursive_directory_iterator begin(this->curent_place);
        std::filesystem::recursive_directory_iterator end;
        std::vector<std::filesystem::path> subdirs;
        std::copy_if(begin, end, std::back_inserter(subdirs), [](const std::filesystem::path& path) {
            return std::filesystem::is_directory(path) || std::filesystem::is_regular_file(path);
            });
        for (auto elem : subdirs)
        {
            if (elem.filename() == key_name) {
                std::cout << "file exist in this directory\n";
                return;
            }
        }
        std::cout << "No such file in this directoty\n";
    }
    catch (const std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
        return;
    }
}
void file_mamager::Count_size_of_directory() {
    try
    {
        long size{ 0 };
        std::filesystem::recursive_directory_iterator begin(this->curent_place);
        std::filesystem::recursive_directory_iterator end;
        std::vector<std::filesystem::path> subdirs;
        std::copy_if(begin, end, std::back_inserter(subdirs), [](const std::filesystem::path& path) {
            return std::filesystem::is_directory(path) || std::filesystem::is_regular_file(path);
            });
        for (auto elem : subdirs)
        {
            size += std::filesystem::file_size(elem);
        }
        std::cout << "Size of directory is : " << size << " bits" << std::endl;
    }
    catch (const std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
        return;
    }
}
void file_mamager::Rename_file() {
    this->Print_directory();
    std::string name_of_file, new_name_of_file;
    std::cout << "Enter name of file wich you want to rename\n";
    std::cin >> name_of_file;
    std::cout << "Enter new name of file\n";
    std::cin >> new_name_of_file;
    std::filesystem::rename(this->curent_place / name_of_file, this->curent_place / new_name_of_file);
}
void file_mamager::Rename_directory() {
    this->Print_directory();
    std::string name_of_directory, new_name_of_directory;
    std::cout << "Enter name of directory wich you want to rename\n";
    std::cin >> name_of_directory;
    std::cout << "Enter new name of directory\n";
    std::cin >> new_name_of_directory;
    std::filesystem::rename(this->curent_place.parent_path() / name_of_directory, this->curent_place.parent_path() / new_name_of_directory);
}
void file_mamager::move_file() {
    try
    {
    std::string path, file_name;
    std::cout << "Enter path and name of file wich you want to move\n";
    std::cin >> file_name;
    std::filesystem::path from = file_name;
    std::cout << "Enter path to directory in wirch you want to move files\n";
    std::cin >> path;
    std::filesystem::path temp = path;
    std::filesystem::rename(file_name, temp /from.filename());
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return;
    }
}
void file_mamager::move_directory() {
    try
    {

   
    std::string path, name_dir;
    std::cout << "Enter name of direcrory for moving";
    std::cin >> name_dir;
    std::filesystem::path from = name_dir;
    std::cout << "Enter path to directory in wirch you want to move curent directory\n";
    std::cin >> path;
    std::filesystem::path temp = path;
    std::filesystem::recursive_directory_iterator begin(from);
    std::filesystem::recursive_directory_iterator end;
    std::vector<std::filesystem::path> subdirs;
    std::copy_if(begin, end, std::back_inserter(subdirs), [](const std::filesystem::path& path) {
        return std::filesystem::is_regular_file(path);
        });
    for (auto elem : subdirs)
    {
        std::filesystem::rename(from/ elem, temp / elem);
    }

    std::filesystem::rename(from, temp/from.filename());
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return;
    }
}
void file_mamager::copy_file() {
    try
    {
        std::string from, to;
        std::cout << "Enter path to file with filename and extension  with you want to copy\n";
        std::cin >> from;
        std::cout << "Enter path to  diractory and new file name in witch you will put file\n";
        std::cin >> to;
        std::filesystem::copy_file(from,to);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
void file_mamager::copy_directory() {
    try
    {
        std::string from, to;
        std::cout << "Enter path to diractory witch you want to copy\n";
        std::cin >> from;
        std::cout << "Enter path to  diractory in witch you will put file\n";
        std::cin >> to;
        std::filesystem::copy(from,to, std::filesystem::copy_options::recursive);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

