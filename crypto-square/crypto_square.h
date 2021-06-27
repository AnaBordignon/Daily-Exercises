#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H
#include <string>
#include <vector>
#include <algorithm>

namespace crypto_square {
	class cipher {
		std::string phrase;
		int columns;
		int rows;
	public:
		cipher(std::string input);
		std::string normalize_plain_text();
		std::vector<std::string> plain_text_segments();
		std::string cipher_text();
		std::string normalized_cipher_text();
	};
}  // namespace crypto_square

#endif // CRYPTO_SQUARE_H