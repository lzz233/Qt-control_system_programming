#ifndef STATESPACE_H
#define STATESPACE_H

#include "blocks/integrator/integrator.h"

class StateSpace
{
public:
    StateSpace(float x1, float x2, float x3);
    ~StateSpace();

    float getOutput();
    float update(float input, float dt);

private:
    integrator* m_integrator_X1;
    integrator* m_integrator_X2;
    integrator* m_integrator_X3;

    float m_previous_input;
};

#endif // STATESPACE_H
