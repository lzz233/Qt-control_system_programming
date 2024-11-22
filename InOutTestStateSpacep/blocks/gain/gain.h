#ifndef GAIN_H
#define GAIN_H

#include <inttypes.h>

class gain
{
public:
    gain(float gain_value);
	float getGainValue() const;
    float update(float input);

private:
    float gain_value;
};

#endif // GAIN_H
