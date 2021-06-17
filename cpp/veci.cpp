#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void swap(char *a, char *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

std::string veci(std::string inp){
    std::vector<char> vecivec;

    for(int i = 0; i<inp.size(); i++){
        vecivec.push_back((char) inp.at(i));
    }

    // The pivot's index and value
    int pivotidx {};
    int pivotelem {};

    // Go backwards until we find two numbers that are sorted
    for(int i = vecivec.size() - 1; i > 0; i--){
        if (vecivec.at(i) > vecivec.at(i-1)){
            pivotidx = i-1;
            pivotelem = vecivec.at(i-1);
            break;
        }

        // If no two such elements exist - return 0
        if (i == 1) return "0";
    }

    std::sort(vecivec.begin() + pivotidx, vecivec.end()); // Sort only the required range

    int swaps {0}; // Amount of swaps needed to shift pivot down to new position

    while (vecivec.at(pivotidx) <= pivotelem){
        pivotidx++;
        swaps++;
    }

    /* Now, we are at the index where the element is the lowest greater than the pivot element,
     * so swap this lowest greater with the one before until it is at the beginning of the sorted list */
    while (swaps-- > 0){
        swap(&vecivec.at(pivotidx), &vecivec.at(pivotidx - 1));
        pivotidx--;
    }

    return std::string(vecivec.begin(), vecivec.end());
}

int main(){
    std::string inp{};
    std::getline(std::cin, inp);
    std::cout << veci(inp) << std::endl;
    return 0;
}
