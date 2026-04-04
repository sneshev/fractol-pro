#include "fract.hpp"

static int getType(str inputType, t_input &input) {
	auto typeIter = std::find(validTypes.begin(), validTypes.end(), inputType);
	if (typeIter == validTypes.end()) {
		return (-1);
	}
	input.type = static_cast<e_fract_type>(typeIter - validTypes.begin());
	return (1);
}

static int getValues(str cRealString, str cImagString, t_input &input) {
	float cReal;
	float cImag;
	try {
			cReal = std::stof(cRealString);
			cImag = std::stof(cImagString);
		} catch (const std::exception&) {
			return (-1);
		}
	input.args.push_back(cReal);
	input.args.push_back(cImag);
	return (1);
}

bool isValidInput(int argc, char *argv[], t_input &input) {
	if (argc != 2 && argc != 4) {
		return (false);
	}
	if (getType(argv[1], input) == -1)
		return (false);
	if (argc == 4) {
		if (getValues(argv[2], argv[3], input) == -1)
			return (false);
	}
	return (true);
}