#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
  std::string str1 = "apple";
  std::string str2 = "aplle";

  std::vector<std::pair<int, char>> differences;
  auto it1 = str1.begin();
  auto it2 = str2.begin();
  int index = 0;

  while(it1 != str1.end() && it2 != str2.end()) {
    auto mismatch_pair = std::mismatch(it1, str1.end(), it2, str2.end());

    if (mismatch_pair.first != str1.end()) {
      differences.push_back({index + std::distance(str1.begin(), mismatch_pair.first), *mismatch_pair.second});
      it1 = mismatch_pair.first + 1;
      it2 = mismatch_pair.second + 1;
      index += std::distance(str1.begin(), mismatch_pair.first) + 1;
    } else {
      break; // No more mismatches within the common prefix
    }
  }

    // Handle differing lengths (similar to the previous example)
    // ... (code to handle insertions/deletions)

  // ... (code to print differences)
  return 0;
}