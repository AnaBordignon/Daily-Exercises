#include "crypto_square.h"

namespace crypto_square {
	cipher::cipher(std::string input) {
		phrase = input;
	}

	/* Remove spaces and punctuation from text. Convert to lowercase */
	std::string cipher::normalize_plain_text() {
		std::string normalized = phrase;

		normalized.erase(
			std::remove_if(normalized.begin(), normalized.end(),
				[](unsigned char c) { return isspace(c) || ispunct(c); }),
			normalized.end());

		std::transform(normalized.begin(), normalized.end(), normalized.begin(),
			[](unsigned char c) { return std::tolower(c); });

		return normalized;
	}

	/* Create row segments of text of column-long length.  column >= row and column - row <= 1 */
	std::vector<std::string> cipher::plain_text_segments() {
		std::vector<std::string> result{};
		std::string normalized = normalize_plain_text();
		int start{ };

		rows = floor(sqrt(normalized.length()));
		columns = ceil(sqrt(normalized.length()));
		while (start < normalized.length()) {
			result.push_back(normalized.substr(start, columns));
			start += columns;
		}
		return result;		
	}

	/* Create text reading the segments from top to bottom, left to right */
	std::string cipher::cipher_text() {
		std::string result{};
		std::vector<std::string> segments = plain_text_segments();

		for (int i{}; i < columns; i++) {
			for (int j{}; j < rows; j++) {
				if (i < segments[j].size()) {
					result.append(segments[j].substr(i, 1));
				}
			}
		}

		return result;
	}

	/* Create new segments of same column and row size, but with the text created in cipher_text. */
	std::string cipher::normalized_cipher_text() {
		std::string result{};
		std::vector<std::string> segments = plain_text_segments();
		
		for (int i{}; i < columns; i++) {
			for (int j{}; j < rows; j++) {
				if (i < segments[j].size()) {
					result.append(segments[j].substr(i, 1));
				}
				else {
					result.append(" ");
				}
			}
			if (i < columns-1)
				result.append(" ");
		}

		return result;

	}
}  // namespace crypto_square
