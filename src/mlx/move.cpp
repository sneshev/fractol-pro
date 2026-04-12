#include "fract.hpp"

void move_center(Fractal &fract, Fixed16_16 rawX, Fixed16_16 rawY) {
    if (!fract.isPrecise()) {
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
    }
    else {
        FixedL xRangeHalf = fract.getXRangeHalfL();
        FixedL yRangeHalf = fract.getYRangeHalfL();

        FixedL xRatio((rawX / width).getRawBits(), 16);
        FixedL yRatio((rawY / width).getRawBits(), 16);

        FixedL newXCenter = fract.getXMinL() + (xRatio * fract.getXRangeL());
        FixedL newYCenter = fract.getYMinL() + (yRatio * fract.getYRangeL());

        fract.setXMinL(newXCenter - xRangeHalf);
        fract.setXMaxL(newXCenter + xRangeHalf);
        fract.setYMinL(newYCenter - yRangeHalf);
        fract.setYMaxL(newYCenter + yRangeHalf);
    }
    fract.info();
    fract.draw();
}