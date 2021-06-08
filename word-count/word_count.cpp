#include "word_count.h"
#include <algorithm>

namespace word_count {

    /* Returns true if char is a ascii character, except comma and single quote */
    bool IsPunctButComma(char c) {
        return ((c >= 0x21 && c <= 0x2F && c != 0x2C && c != 0x27) || (c >= 0x3A && c <= 0x40) || (c >= 0x5B && c <= 0x60) ||  (c >= 0x7B && c <= 0x7E));
    }

    /* Function has a known limitation: handles words between quotes as a different word. To be fixed! */
    std::map<std::string, int> words(std::string phrase) {
        
        std::map<std::string, int> count_words;
        std::map<std::string, int>::iterator itr;
        std::string word{};
        char* lowercase_letter;

        /* Remove all punctuation and characters, but commas and single quotes */
        phrase.erase(std::remove_if(phrase.begin(), phrase.end(), IsPunctButComma), phrase.end());

        lowercase_letter = (char*)malloc((phrase.size() + 1) * sizeof(char));

        for (int i{}; i < (phrase.size() + 1); i++) {
            lowercase_letter[i] = tolower(phrase[i]);
        }

        /* Tokenize */
        char* token = strtok(lowercase_letter, " \n\t\f\v\r,");

        while (token != NULL) {
            word = token;
            
            /* If word is repeted, increment counter */
            itr = count_words.find(word);
            if (itr != count_words.end()) {
                count_words[word] = itr->second + 1;
            }
            else {
                /* if not, add with count 1 */
                count_words[word] = 1;
            }
            token = strtok(NULL, " \n\t\f\v\r,");
        }

        return count_words;
    }


}  // namespace word_count
