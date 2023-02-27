#pragma once

#include "realNum.h"

int calcPI(RealNum* pi, unsigned int c, unsigned int n);

int calcPIedge(RealNum* pi, unsigned int c, unsigned int n);

int calcPIvector(RealNum* pi, unsigned int c, unsigned int n);

void calcPIv(RealNum* w, RealNum* numX2, RealNum* C, RealNum* N);
