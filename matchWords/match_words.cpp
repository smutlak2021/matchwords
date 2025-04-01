#include <iostream>
#include <optional> // C++17 feature
#include <vector>
#include <tuple>
#include <string>
#include <regex>
#include <iomanip>
#include <chrono>


// using SYLLABLE = std::tuple<std::string, int, std::string>;

// bool match_syllable(SYLLABLE tub, std::string word){

//     return false;
// }


// std::vector<SYLLABLE>
// convert_to_syllables(std::string patt){

//     std::vector<SYLLABLE> result;
//     std::regex pattern("\\d+");
    
//     auto begin = std::sregex_iterator(patt.begin(), patt.end(), pattern);
//     auto end = std::sregex_iterator();
    
//     for(std::sregex_iterator i =begin; i != end; ++i){
//         std::smatch match = *i;
//         std::cout << "*****Match: " << match.str() << std::endl;
//     }

//    return result;
// }

// bool word_match(std::string patt, std::string word){
//     std::cout << patt << "\t\t" << word << "\t\t" << "==>";
//     std::vector<SYLLABLE>
//                 Syllables = convert_to_syllables(patt);
//     for (const auto syll: Syllables)
//         if (!match_syllable(syll, word)){
//             return false;
//         }
//     return true;
// }

std::string format_duration(std::chrono::nanoseconds ns) {
    using namespace std::chrono;
    auto ns_int = ns.count();

    if (ns_int < 1000) {
        return std::to_string(ns_int) + " ns";
    } else if (ns_int < 1000000) {
        return std::to_string(ns_int / 1000) + " µs"; // Microseconds
    } else if (ns_int < 1000000000) {
        return std::to_string(ns_int / 1000000) + " ms"; // Milliseconds
    } else {
        return std::to_string(ns_int / 1000000000) + " s"; // Seconds
    }
}

std::string convert_to_reg_ex(std::string patt){

    std::string generatedRegex = patt;
    std::regex pattern("\\d+", std::regex::icase);
    auto begin = std::sregex_iterator(patt.begin(), patt.end(), pattern);
    auto end = std::sregex_iterator();
    
    int accumulatedPos = 0;
    for(std::sregex_iterator i =begin; i != end; ++i){
        std::smatch match = *i;
        // std::cout << "*****Match: " << match.position() << " "<< match.str() << std::endl;
        std::string rx = "\\w{" + match.str() + "}";
        generatedRegex.replace(match.position() + accumulatedPos, match.str().length(), rx);
        // std::cout << "*****New Pattern: " << generatedRegex << std::endl;
        accumulatedPos+= rx.length() > match.str().length() ? rx.length() - match.str().length() : match.str().length() - rx.length();
    }
    
    std::cout << "final Pattern: " << std::left << std::setw(50) << generatedRegex << "\t\t" << "==> ";
    return generatedRegex;
}

bool word_match(std::string patt, std::string word){

    std::cout << std::left << std::setw(30) << patt << std::left << std::setw(30) << word << "==> ";
    std::string pattern = convert_to_reg_ex(patt);
    std::regex regex_pattern (pattern, std::regex::icase);

    if(std::regex_search(word, regex_pattern)) {
        return true;
    }
    return false;
}

int main() {
    auto start_high_res = std::chrono::high_resolution_clock::now();

    std::cout << word_match("F2eb2k", "Facebook") << "\n";
    std::cout << word_match("i11l", "International") << "\n";
    std::cout << word_match("8", "facebook") << "\n";
    std::cout << word_match("F2eb5k", "facebook") << "\n";

    auto end_high_res = std::chrono::high_resolution_clock::now();
    auto duration_high_res = std::chrono::duration_cast<std::chrono::nanoseconds>(end_high_res - start_high_res);

    std::cout << "High-Resolution Time: " << format_duration(duration_high_res) << std::endl;

    return 0;
}