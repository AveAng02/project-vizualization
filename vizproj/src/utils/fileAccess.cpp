#include <iostream>
#include <fstream>
#include <string>

/*
* Token List:
*  <VertexNum>...</VertexNum>
*  <Vertex>...</Vertex>
*  <AdjacentNodeNum>...</AdjacentNodeNum>
*/

int* arr;

int* Vertex;

int* AdjacentNodeNum;


int stringToChar(std::string str) {

    str = 
}


void VertexNum(std::string str) {


}

void token(std::string str) {

    std::string token = "";

    std::string value = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '<') {

            for (; i < str.length(); i++) {
                if (str[i] != '>') {
                    token = token + str[i];
                }
                if (str[i] == '>') {
                    token = token + str[i];
                    break;
                }
            }
        }
    }

    // the string between first '>' and '<' and trimmed of white spaces

    for (int i = 0; i < str.length(); i++) {

        if (str[i] == '>') {

            for (i = i + 1; i < str.length(); i++) {

                if (str[i] == '<') {
                    break;
                }
                else {
                    value = value + str[i];
                }
            }
        }
    }

    if ("<VertexNum></VertexNum>" == token) {

        VertexNum(value);
    }


    std::cout << token << "  " << value << std::endl;
}


int main() {
    std::fstream newfile;

    newfile.open("punchCard.txt", std::ios::in); //open a file to perform read operation using file object

    if (newfile.is_open()) {   //checking whether the file is open
        std::string str;

        while (getline(newfile, str)) {
            token(str);
        }

        newfile.close();   //close the file object.
    }
}

