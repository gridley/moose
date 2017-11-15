/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef VECTORKERNEL_H
#define VECTORKERNEL_H

#include "KernelBase.h"

class VectorKernel;

template <>
InputParameters validParams<VectorKernel>();

class VectorKernel : public KernelBase
{
public:
  VectorKernel(const InputParameters & parameters);

  /// Compute this VectorKernel's contribution to the residual
  virtual void computeResidual() override;

  /// Compute this VectorKernel's contribution to the diagonal Jacobian entries
  virtual void computeJacobian() override;

  /// Computes d-residual / d-jvar... storing the result in Ke.
  virtual void computeOffDiagJacobian(unsigned int jvar) override;

  /**
   * Computes jacobian block with respect to a scalar variable
   * @param jvar The number of the scalar variable
   */
  virtual void computeOffDiagJacobianScalar(unsigned int jvar) override;

protected:
  /// This is a regular kernel so we cast to a regular MooseVariable
  MooseVariableVector & _var;

  /// the current test function
  const VectorVariableTestValue & _test;

  /// curl of the test function
  const VectorVariableTestCurl & _curl_test;

  /// the current shape functions
  const VectorVariablePhiValue & _phi;

  /// curl of the shape function
  const VectorVariablePhiCurl & _curl_phi;

  /// Holds the solution at current quadrature points
  const VectorVariableValue & _u;

  /// Holds the solution curl at the current quadrature points
  const VectorVariableCurl & _curl_u;
};

#endif /* VECTORKERNEL_H */
