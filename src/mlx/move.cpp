#include "fract.hpp"

void move_center(Fractal &fract, Fixed24_10 rawX, Fixed24_10 rawY) {
	Fixed xRangeHalf = fract.getXRangeHalf();
	Fixed yRangeHalf = fract.getYRangeHalf();
	
	Fixed xRatio((rawX / width).getRawBits(), 8);
	Fixed yRatio((rawY / width).getRawBits(), 8);

	Fixed newXCenter = fract.getXMin() + (xRatio * fract.getXRange());
	Fixed newYCenter = fract.getYMin() + (yRatio * fract.getYRange());	
	
	fract.setXMin(newXCenter - xRangeHalf);
	fract.setXMax(newXCenter + xRangeHalf);
	fract.setYMin(newYCenter - yRangeHalf);
	fract.setYMax(newYCenter + yRangeHalf);

	fract.info();
	fract.draw();
}
