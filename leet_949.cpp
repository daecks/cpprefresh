//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string largestTimeFromDigits(std::vector<int> &arr)
{
    // std::next_permutation requires sorted input
    std::sort(begin(arr), end(arr));

    // Create all possible permutations
    std::vector<std::vector<int>> permutations;
    do
    {
        permutations.push_back(arr);
    } while (std::next_permutation(begin(arr), end(arr)) != 0);

    // Remove invalid combinations
    permutations.erase((std::remove_if(begin(permutations), end(permutations), [](std::vector<int> candidate) {
        return (candidate[0] > 2 || candidate[2] > 5 || ((candidate[0]) == 2 && candidate[1] > 3));
    })), permutations.end());

    // Sort so largest is first element
    std::sort(rbegin(permutations), rend(permutations));

    // Format response
    if (permutations.size() == 0)
        return "";
        
    return (std::to_string(permutations[0][0]) + 
        std::to_string(permutations[0][1]) + 
        ":" + 
        std::to_string(permutations[0][2]) + 
        std::to_string(permutations[0][3]));
}

int main(){
    
    std::vector<int> candidate;
    //candidate = {0,4,0,0};
    //std::cout << largestTimeFromDigits(candidate) << '\n';

    candidate = {4,1,0,0};
    std::cout << largestTimeFromDigits(candidate) << '\n';


}