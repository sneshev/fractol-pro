#include "fract.hpp"

void move_center(Fractal &fract, Fixed16_16 rawX, Fixed16_16 rawY) {
	Fixed xRangeHalf = fract.getXRangeHalf();
	Fixed yRangeHalf = fract.getYRangeHalf();
	
	Fixed xRatio((rawX / width).getRawBits(), 16);
	Fixed yRatio((rawY / width).getRawBits(), 16);

	Fixed newXCenter = fract.getXMin() + (xRatio * fract.getXRange());
	Fixed newYCenter = fract.getYMin() + (yRatio * fract.getYRange());	
	
	fract.setXMin(newXCenter - xRangeHalf);
	fract.setXMax(newXCenter + xRangeHalf);
	fract.setYMin(newYCenter - yRangeHalf);
	fract.setYMax(newYCenter + yRangeHalf);

	fract.info();
	fract.draw();
}
