#include "statespace.h"

StateSpace::StateSpace(float x1, float x2, float x3)
{
    m_integrator_X1 = new integrator(x1);
    m_integrator_X2 = new integrator(x2);
    m_integrator_X3 = new integrator(x3);
}

StateSpace::~StateSpace()
{
    delete m_integrator_X1;
    delete m_integrator_X2;
    delete m_integrator_X3;
}

float StateSpace::getOutput()
{
    return 0.1 * m_integrator_X1->state() + 3 * m_integrator_X2->state() + 1 * m_integrator_X3->state() + 1 * m_previous_input;
}

float StateSpace::update(float input, float dt)
{
    float tmp_x1 = m_integrator_X1->state();
    float tmp_x2 = m_integrator_X2->state();
    float tmp_x3 = m_integrator_X3->state();
    float output = getOutput();

    m_integrator_X1->update(0 * tmp_x1 + 1 * tmp_x2 + 0 * tmp_x3 + 0 * input, dt);
    m_integrator_X2->update(0 * tmp_x1 + 0 * tmp_x2 + 1 * tmp_x3 + 0 * input, dt);
    m_integrator_X3->update(-0.5 * tmp_x1 - 10 * tmp_x2 - 10 * tmp_x3 + 1 * input, dt);

    m_previous_input = input;

    return output;
}
