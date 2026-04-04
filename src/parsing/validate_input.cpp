#include "fract.hpp"

static bool isValidType(str inputType, t_input &input) {
	auto typeIter = std::find(validTypes.begin(), validTypes.end(), inputType);
	if (typeIter == validTypes.end()) {
		return (false);
	}
	input.type = static_cast<e_fract_type>(typeIter - validTypes.begin());
	return (true);
}

static bool areValidValues(str cRealString, str cImagString, t_input &input) {
	float cReal;
	float cImag;
	try {
			cReal = std::stof(cRealString);
			cImag = std::stof(cImagString);
	} catch (const std::exception&) {
		return (false);
	}
	input.args.push_back(cReal);
	input.args.push_back(cImag);
	return (true);
}

bool isValidInput(int argc, char *argv[], t_input &input) {
	if (argc != 2 && argc != 4) {
		return (false);
	}
	if (!isValidType(argv[1], input))
		return (false);
	if (argc == 4) {
		if (!areValidValues(argv[2], argv[3], input))
			return (false);
	}
	return (true);
}