#include <iostream>
#include <sstream>
#include <dirent.h>
#include <fnmatch.h>
#include <sys/stat.h>

//Funktion Ausgabe find
void print_files(std::string dirname, std::string pattern, std::string type, bool follow, bool xdev, int startvolume){
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
                    if(pattern == "none"){
                        printf("%s\n", temp.c_str());
                    }
                    else {
                        if (fnmatch(pattern.c_str(), std::string(dir->d_name).c_str(),0) == 0){
                            printf("%s\n", temp.c_str());
                        }
                    }
                }
                else if (type == "f" && dir->d_type == DT_REG){
                    if(pattern == "none"){
                        printf("%s\n", temp.c_str());
                    }
                    else {
                        if (fnmatch(pattern.c_str(), std::string(dir->d_name).c_str(),0) == 0){
                            printf("%s\n", temp.c_str());
                        }
                    }
                }
                else if (type == "d" && dir->d_type == DT_DIR){
                    if(pattern == "none"){
                        printf("%s\n", temp.c_str());
                    }
                    else {
                        if (fnmatch(pattern.c_str(), std::string(dir->d_name).c_str(),0) == 0){
                            printf("%s\n", temp.c_str());
                        }
                    }
                }
                else if(follow &&dir->d_type == DT_LNK){
                    struct stat tempstat2;
                    stat(temp.c_str(), &tempstat2);
                    if (S_ISDIR(tempstat2.st_mode)){
                        if (type != "f") {
                            if (pattern == "none") {
                                printf("%s\n", temp.c_str());
                            } else {
                                if (fnmatch(pattern.c_str(), std::string(dir->d_name).c_str(), 0) == 0) {
                                    printf("%s\n", temp.c_str());
                                }
                            }
                        }
                        print_files( dirname + "/" + std::string(dir->d_name), pattern, type, follow, xdev, startvolume);
                    }
                    else{
                        if (type != "d") {
                            if (pattern == "none") {
                                printf("%s\n", temp.c_str());
                            } else {
                                if (fnmatch(pattern.c_str(), std::string(dir->d_name).c_str(), 0) == 0) {
                                    printf("%s\n", temp.c_str());
                                }
                            }
                        }
                    }
                }
                if (dir->d_type == DT_DIR && std::string(dir->d_name) != "." && std::string(dir->d_name) != ".."){
                    struct stat tempstat;
                    stat(temp.c_str(), &tempstat);
                    if(xdev){
                        if (startvolume == tempstat.st_dev){
                            print_files( dirname + "/" + std::string(dir->d_name), pattern, type, follow, xdev, startvolume);
                        }
                    }
                    else {
                        print_files( dirname + "/" + std::string(dir->d_name), pattern, type, follow, xdev, startvolume);
                    }
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
        //std::cout << argv[i] << std::endl;
    }
    struct stat startstat;
    stat(dirname.c_str(), &startstat);
    int startvolume = startstat.st_dev;
    print_files(dirname, pattern, type, follow, xdev, startvolume);


    return 0;


}
