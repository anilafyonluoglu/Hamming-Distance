#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string convertToBinary(int number, int dim)
{
    std::string binaryString;
    while (number != 0) {
        binaryString = (number % 2 == 0 ? "0" : "1") + binaryString;
        number /= 2;
    }
    int numberOfZeros = dim - binaryString.size();
    for (int i = 0; i < numberOfZeros; i++) {
        binaryString.insert(0, "0");
    }
    return binaryString;
}

int main() {
    int dim, dis, size;
    cin >> dim >> dis;
    size = pow(2, dim);
    std::vector<std::string> allVectors;
    for (int i = 0; i < size; ++i) {
        allVectors.push_back(convertToBinary(i, dim));
    }
    vector<string> clique;
    int countOfDifferencessInEachIndex=0;
    clique.push_back(convertToBinary(0,dim));

    for (int a = pow(2, dis) - 1; a < size ; ++a) {
        int counterOfVectors = 0;
        for (int b = 0; b < clique.size() ; ++b) {
            for (int i = 0; i < dim; ++i) {
                if (allVectors[a][i] != clique[b][i]) {
                    countOfDifferencessInEachIndex++;
                }
            }
            if(countOfDifferencessInEachIndex>=dis){
                counterOfVectors++;
            }
            countOfDifferencessInEachIndex = 0;
        }
        if(counterOfVectors == clique.size()){
            clique.push_back(convertToBinary(a,dim));
        }
    }
    if (dis==0){
        std::cout<<clique.size()-1<<std::endl;

    }
    else{
        std::cout<<clique.size()<<std::endl;
    }
return 0;
}
