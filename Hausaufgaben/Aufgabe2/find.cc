#include <iostream>
#include <sstream>
#include <dirent.h>

//Funktion Ausgabe find
void print_files(std::string dirname, std::string pattern, std::string type, bool follow, bool xdev){
    DIR *d; // DAteistruktur
    struct dirent *dir; //dirent ist eintrag in Directory, sagt mir was es ist (Ordner, Datei)
    d = opendir(dirname.c_str());
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if(std::string(dir->d_name) == "." || std::string(dir->d_name) == ".."){
                continue;
            }
            else{
                std::string temp;
                temp += dirname + "/";
                temp += std::string(dir->d_name);
                if(type == "none"){
                    printf("%s\n", temp.c_str());
                }
                else if (type == "f" && dir->d_type == DT_REG){
                    printf("%s\n", temp.c_str());
                }
                else if (type == "d" && dir->d_type == DT_DIR){
                    printf("%s\n", temp.c_str());
                }
                if (dir->d_type == DT_DIR && std::string(dir->d_name) != "." && std::string(dir->d_name) != ".."){
                    print_files( dirname + "/" + std::string(dir->d_name), pattern, type, follow, xdev);
                }
            }

        }
        closedir(d);
    }
}

// Testeingabe: find Testordner -name pattern -type f -follow -xdev
int main(int argc, char *argv[]){
    std::string pattern = "none";
    std::string type = "none";
    std::string dirname = argv[1];
    //std::string str;
    bool follow = false;
    bool xdev = false;
    //std::string input_split[8];
    //input = "find Testordner -name pattern -type f -follow";
    //input = argv;
    //std::stringstream ss(input);

    //int i = 0;
    //while (getline(ss, str, ' ')){
    //    input_split[i] = str;
    //    i =i + 1;
    //}
    for (int i = 2; i < argc; i++){
        if(strcmp(argv[i],"-name") == 0){
            pattern = argv[i+1];
        }
        if(strcmp(argv[i],"-type") == 0){
            type = argv[i+1];
        }
        if(strcmp(argv[i],"-follow") == 0){
            follow = true;
        }
        if(strcmp(argv[i], "-xdev") == 0){
            xdev = true;
        }
        std::cout << argv[i] << std::endl;
    }

    print_files(dirname, pattern, type, follow, xdev);


    return 0;


}
