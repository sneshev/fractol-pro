#include "fract.hpp"
#define PRECISE_RANGE 0.0001f

void zoom(Fractal &fract, float zoomRatio) {
	if (fract.isPrecise()) {
		double centerX = fract.getXCenter_d();
		double centerY = fract.getYCenter_d();
		double newHalfRangeX = fract.getXRangeHalf_d() * zoomRatio;
		double newHalfRangeY = fract.getYRangeHalf_d() * zoomRatio;

		fract.setXMin_d(centerX - newHalfRangeX);
		fract.setYMin_d(centerY - newHalfRangeY);
		fract.setXMax_d(centerX + newHalfRangeX);
		fract.setYMax_d(centerY + newHalfRangeY);

		if (fract.getXRange_d() > PRECISE_RANGE) {
			fract.setPrecise(false);
		}
	}
	else {
		Fixed centerX = fract.getXCenter();
		Fixed centerY = fract.getYCenter();
		Fixed newHalfRangeX = fract.getXRangeHalf() * Fixed(zoomRatio);
		Fixed newHalfRangeY = fract.getYRangeHalf() * Fixed(zoomRatio);

		fract.setXMin(centerX - newHalfRangeX);
		fract.setYMin(centerY - newHalfRangeY);
		fract.setXMax(centerX + newHalfRangeX);
		fract.setYMax(centerY + newHalfRangeY);

		if (fract.getXRange() < Fixed(PRECISE_RANGE)) {
			fract.setPrecise(true);
		}
	}
	fract.info();
	fract.draw();
}