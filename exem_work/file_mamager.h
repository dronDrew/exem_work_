#pragma once
#include"dependies.h"


class file_mamager
{
    std::filesystem::path curent_place;
public:
    file_mamager();//done
    void Print_directory();//done
    void Create_directory();//done
    void Create_file();//done
    void Delete_file_and_directory();//done
    void Delete_file();//done
    void find_file_or_directory();//done
    void Count_size_of_directory();//done
    void Rename_file();//done
    void Rename_directory();//done
    void move_file();//done
    void move_directory();//done
    void copy_file();
    void copy_directory();
};

