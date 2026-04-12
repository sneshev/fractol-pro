#include "fract.hpp"

void move_center(Fractal &fract, float rawX, float rawY) {
    if (!fract.isPrecise()) {
        Fixed xRangeHalf = fract.getXRangeHalf();
        Fixed yRangeHalf = fract.getYRangeHalf();

        Fixed xRatio(rawX / width);
        Fixed yRatio(rawY / height);

        Fixed newXCenter = fract.getXMin() + (xRatio * fract.getXRange());
        Fixed newYCenter = fract.getYMin() + (yRatio * fract.getYRange());

        fract.setXMin(newXCenter - xRangeHalf);
        fract.setXMax(newXCenter + xRangeHalf);
        fract.setYMin(newYCenter - yRangeHalf);
        fract.setYMax(newYCenter + yRangeHalf);
    }
    else {
        double xRangeHalf = fract.getXRangeHalf_d();
        double yRangeHalf = fract.getYRangeHalf_d();

        double xRatio = (rawX / width);
        double yRatio = (rawY / height);

        double newXCenter = fract.getXMin_d() + (xRatio * fract.getXRange_d());
        double newYCenter = fract.getYMin_d() + (yRatio * fract.getYRange_d());

        fract.setXMin_d(newXCenter - xRangeHalf);
        fract.setXMax_d(newXCenter + xRangeHalf);
        fract.setYMin_d(newYCenter - yRangeHalf);
        fract.setYMax_d(newYCenter + yRangeHalf);
    }
    fract.info();
    fract.draw();
}