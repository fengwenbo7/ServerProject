#include <iostream>
#include "src/file_parsing.h"

int main(){
    FileParsing file_parsing("127.0.0.1");
    file_parsing.Init();
    while(true){
        file_parsing.Handler();
    }
}