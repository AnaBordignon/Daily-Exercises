#include "rna_transcription.h"
#include <map>

namespace rna_transcription {

	std::map<char, char> dnaToRna = {
		{ 'G', 'C' },
		{ 'C', 'G' },
		{ 'T', 'A' },
		{ 'A', 'U' }
	};

	char to_rna(char dna) {
		return dnaToRna[dna];
	}

	std::string to_rna(std::string dna) {
		for (char& c : dna) {
			c = dnaToRna[c];
		}
	
			return dna;
		}

}  // namespace rna_transcription
