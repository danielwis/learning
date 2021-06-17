#include <iostream>
#include <string>
#include <vector>

std::string veci(std::string inp){
    std::vector<int> vecivec;

    for(int i = 0; i<inp.size(); i++){
        vecivec.push_back((int) inp.at(i) - '0');
    }

    int pivotidx {};
    int pivotelem {};
    for(int i = vecivec.size() - 1; i > 0; i--){
        if (vecivec.at(i) > vecivec.at(i-1)){
            pivotidx = i-1;
            pivotelem = vecivec.at(i-1);
            break;
        }
    }

    std::sort(vecivec.begin + pivotidx, vecivec.end); // Sort only the required range

    for(int i = pivotidx; i < vecivec.size(); i++){
        if (vecivec.at(i) > pivotelem){ // shift this down
            std::move(vecivec.begin + pivotidx, vecivec.begin + pivotidx, veci

    return "hi";
}

int main(){
    std::string inp{};
    std::getline(std::cin, inp);
    std::cout << inp << std::endl;
    return 0;
}
