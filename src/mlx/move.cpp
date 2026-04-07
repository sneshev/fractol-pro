#include "fract.hpp"

void move_center(Fractal &fract, Fixed rawX, Fixed rawY) {
	Fixed xRangeHalf = fract.getXRangeHalf();
	Fixed yRangeHalf = fract.getXRangeHalf();

	Fixed newXCenter = fract.getXMin() + ((rawX / width)  * fract.getXRange());
	Fixed newYCenter = fract.getYMin() + ((rawY / height) * fract.getYRange());	
	
	fract.setXMin(newXCenter - xRangeHalf);
	fract.setYMin(newYCenter - xRangeHalf);
	fract.setXMax(newXCenter + yRangeHalf);
	fract.setYMax(newYCenter + yRangeHalf);

	fract.info();
	fract.draw();
}
