#ifndef Alignment_CommonAlignmentParametrization_FrameToFrameDerivative_h
#define Alignment_CommonAlignmentParametrization_FrameToFrameDerivative_h

#include "Alignment/CommonAlignment/interface/Utilities.h"

/// \class FrameToFrameDerivative
///
/// class for calculating derivatives between different frames
///
///  $Date: 2007/03/02 12:17:09 $
///  $Revision: 1.4 $
/// (last update by $Author: fronga $)

class Alignable;

class FrameToFrameDerivative
{

  public:

  /// Return the derivative DeltaFrame(object)/DeltaFrame(composedobject) 
  AlgebraicMatrix frameToFrameDerivative(const Alignable* object,
					 const Alignable* composedObject) const;

  private:

  /// Helper to transform from RotationType to AlgebraicMatrix
  inline static AlgebraicMatrix transform(const align::RotationType&);

  /// Calculates derivatives using the orientation Matrixes and the origin difference vector
  AlgebraicMatrix getDerivative(const align::RotationType &detUnitRot,
				const align::RotationType &composeRot,
				const align::GlobalVector &posVec) const;

  /// Gets linear approximated euler Angles 
  AlgebraicVector linearEulerAngles(const AlgebraicMatrix &rotDelta) const;
 
  /// Calculates the derivative DPos/DPos 
  AlgebraicMatrix derivativePosPos(const AlgebraicMatrix &RotDet,
				   const AlgebraicMatrix &RotRot) const;

  /// Calculates the derivative DPos/DRot 
  AlgebraicMatrix derivativePosRot(const AlgebraicMatrix &RotDet,
				   const AlgebraicMatrix &RotRot,
				   const AlgebraicVector &S) const;

  /// Calculates the derivative DRot/DRot 
  AlgebraicMatrix derivativeRotRot(const AlgebraicMatrix &RotDet,
				   const AlgebraicMatrix &RotRot) const;

};

AlgebraicMatrix FrameToFrameDerivative::transform(const align::RotationType& rot)
{
  AlgebraicMatrix R(3, 3);

  R(1, 1) = rot.xx(); R(1, 2) = rot.xy(); R(1, 3) = rot.xz();
  R(2, 1) = rot.yx(); R(2, 2) = rot.yy(); R(2, 3) = rot.yz();
  R(3, 1) = rot.zx(); R(3, 2) = rot.zy(); R(3, 3) = rot.zz();

  return R;
}

#endif

