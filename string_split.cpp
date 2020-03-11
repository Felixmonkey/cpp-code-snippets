#include <iostream>
#include <vector>
#include <string>
#include <sstream>

//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
//https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/

std::vector<std::string> string_split(std::string str, std::string delimiter){
    size_t pos = 0;
    std::string token;
    std::vector<std::string> result;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        result.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(str);
    return result;
}

std::vector<std::string> string_split2(std::string str)
{   
    // Used to split string around spaces.
    std::istringstream ss(str);
    std::vector<std::string> result;
    
    do { 
        std::string word;
        ss >> word;  
        result.push_back(word);
    } while (ss);
    
    return result;
}

int main()
{
    std::string str = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";
 
    //Method 1
    for(std::string token : string_split(str, delimiter)){
        std::cout << token << std::endl;
    }
    std::cout << "=====================" << std::endl;
 
    //Method 2
    str = "Geeks for Geeks";
    std::vector<std::string> result = string_split2(str);
    std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}

/*
tiger
mushroom
=====================
Geeks
for
Geeks

*/
