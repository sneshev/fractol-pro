#include "fract.hpp"

void zoom(Fractal &fract, Fixed zoomRatio) {
	Fixed centerX = fract.getXCenter();
	Fixed centerY = fract.getYCenter();
	Fixed newHalfRangeX = (fract.getXRangeHalf() * zoomRatio);
	Fixed newHalfRangeY = (fract.getYRangeHalf() * zoomRatio);

	fract.setXMin(centerX - newHalfRangeX);
	fract.setYMin(centerY - newHalfRangeY);
	fract.setXMax(centerX + newHalfRangeX);
	fract.setYMax(centerY + newHalfRangeY);
	fract.info();
	fract.draw();
}
