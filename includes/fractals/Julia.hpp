#ifndef FRACT_JULIA_HPP
#define FRACT_JULIA_HPP

#include "Fractal.hpp"
#include "macros.hpp"

class Julia : public Fractal {
	private:
		Fixed _cX;
		Fixed _cY;

		double _cX_d;
		double _cY_d;

		__m256i calcIterations8i(Vec8i cX, Vec8i cY);
		__m256i calcIterations4d(Vec4d cX, Vec4d cY);
	public:
		Julia(Mlx &inMlx, t_input &input) 
			: Fractal(inMlx, input),
			_cX(input.args[0]),
			_cY(input.args[1]),
			_cX_d(input.args[0]),
			_cY_d(input.args[1]) {}

		~Julia() {}

		void adjustCX(float amount) {
			if (_precise == true)
				_cX_d += amount;
			else
				_cX = _cX + Fixed(amount);
		}
		void adjustCY(float amount) {
			if (_precise == true)
				_cY_d += amount;
			else
				_cY = _cY + Fixed(amount);
		}

		void setPrecise(bool type) override {
		if (type == false) {
			_xMin = Fixed((float)_xMin_d);
			_xMax = Fixed((float)_xMax_d);
			_yMin = Fixed((float)_yMin_d);
			_yMax = Fixed((float)_yMax_d);
			_cX = Fixed((float)_cX_d);
			_cY = Fixed((float)_cY_d);
			_precise = false;
		} else {
			_xMin_d = (double)_xMin.toFloat();
			_xMax_d = (double)_xMax.toFloat();
			_yMin_d = (double)_yMin.toFloat();
			_yMax_d = (double)_yMax.toFloat();
			_cX_d = _cX.toFloat();
			_cY_d = _cY.toFloat();
			_precise = true;
		}
	}
};

#endif