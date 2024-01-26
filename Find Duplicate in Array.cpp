#include <unordered_set>
#include <vector>

int findDuplicate(std::vector<int> &arr, int n) {
    std::unordered_set<int> seen;

    for (auto i : arr) {
        if (seen.count(i) > 0) {
            return i;  // Found the duplicate
        }
        seen.insert(i);
    }

    return -1;  // If no duplicate is found
}
