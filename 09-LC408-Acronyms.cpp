#include <iostream>
#include <vector>
#include <string>

bool ValidWordAbbreviation(const std::string& word, const std::string& abbr) {
    int wordIndex = 0, abbrIndex = 0;

    while (abbrIndex < abbr.size()) {
        if (std::isdigit(abbr[abbrIndex])) {
            if (abbr[abbrIndex] == '0') {
                return false;
            }
            int num = 0;

            while (abbrIndex < abbr.size() && std::isdigit(abbr[abbrIndex])) {
                num = num * 10 + (abbr[abbrIndex] - '0');
                ++abbrIndex;
            }
            wordIndex += num;
        } else {
            if (wordIndex >= word.size() || word[wordIndex]!= abbr[abbrIndex]) {
                return false;
            }
            ++wordIndex;
            ++abbrIndex;
        }
    }

    return wordIndex == word.size() && abbrIndex == abbr.size();
}

int main() {
    std::vector<std::string> words = {"a", "a", "abcdefghijklmnopqrst", "abcdefghijklmnopqrst", "word", "internationalization", "localization"};
    std::vector<std::string> abbreviations = {"a", "b", "a18t", "a19t", "w0rd", "i18n", "l12n"};

    for (size_t i = 0; i < words.size(); ++i) {
        std::cout << i + 1 << ".\t word: '" << words[i] << "'" << std::endl;
        std::cout << "\t abbr: '" << abbreviations[i] << "'\n";
        std::cout << "\n\t Is '" << abbreviations[i] << "' a valid abbreviation for the word '" << words[i] << "'? ";
        std::cout << (ValidWordAbbreviation(words[i], abbreviations[i])? "Yes\n" : "No\n");
        std::cout << "-" << std::string(100, '-') << "\n";
    }

    return 0;
}
