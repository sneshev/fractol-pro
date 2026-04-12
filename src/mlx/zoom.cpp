#include "fract.hpp"

void zoom(Fractal &fract, Fixed zoomRatio) {
	if ((fract.isPrecise() && fract.getXRangeL() > FixedL(0.5f)) ||
		(!fract.isPrecise() && fract.getXRange() > Fixed(0.5f))) {
		if (fract.isPrecise()) {
			fract.setXMin(Fixed((int)fract.getXMinL().getRawBits(), FIXED_LONG_FRACTIONAL_BITS));
			fract.setXMax(Fixed((int)fract.getXMaxL().getRawBits(), FIXED_LONG_FRACTIONAL_BITS));
			fract.setYMin(Fixed((int)fract.getYMinL().getRawBits(), FIXED_LONG_FRACTIONAL_BITS));
			fract.setYMax(Fixed((int)fract.getYMaxL().getRawBits(), FIXED_LONG_FRACTIONAL_BITS));
		}
		fract.setPrecise(false);

		Fixed centerX = fract.getXCenter();
		Fixed centerY = fract.getYCenter();
		Fixed newHalfRangeX = (fract.getXRangeHalf() * zoomRatio);
		Fixed newHalfRangeY = (fract.getYRangeHalf() * zoomRatio);

		fract.setXMin(centerX - newHalfRangeX);
		fract.setYMin(centerY - newHalfRangeY);
		fract.setXMax(centerX + newHalfRangeX);
		fract.setYMax(centerY + newHalfRangeY);
	}
	else {
		if (!fract.isPrecise()) {
			fract.setXMinL(FixedL(fract.getXMin().getRawBits(), FIXED_FRACTIONAL_BITS));
			fract.setXMaxL(FixedL(fract.getXMax().getRawBits(), FIXED_FRACTIONAL_BITS));
			fract.setYMinL(FixedL(fract.getYMin().getRawBits(), FIXED_FRACTIONAL_BITS));
			fract.setYMaxL(FixedL(fract.getYMax().getRawBits(), FIXED_FRACTIONAL_BITS));
		}
		fract.setPrecise(true);
		FixedL zoomRatioL(zoomRatio.getRawBits(), FIXED_FRACTIONAL_BITS);

		FixedL centerX = fract.getXCenterL();
		FixedL centerY = fract.getYCenterL();
		FixedL newHalfRangeX = (fract.getXRangeHalfL() * zoomRatioL);
		FixedL newHalfRangeY = (fract.getYRangeHalfL() * zoomRatioL);

		fract.setXMinL(centerX - newHalfRangeX);
		fract.setYMinL(centerY - newHalfRangeY);
		fract.setXMaxL(centerX + newHalfRangeX);
		fract.setYMaxL(centerY + newHalfRangeY);
	}
	fract.info();
	fract.draw();
}
