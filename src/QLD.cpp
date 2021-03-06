/*
 * Copyright 2012-2019 CNRS-UM LIRMM, CNRS-AIST JRL
 */

// associated header
#include "eigen-qld/QLD.h"

// includes

namespace Eigen
{

QLD::QLD() : A_(), B_(), fdOut_(0), verbose_(false), fail_(0), U_(), WAR_(), IWAR_() {}

QLD::QLD(int nrvar, int nreq, int nrineq, bool verbose)
: A_(), B_(), fdOut_(0), verbose_(verbose ? 1 : 0), fail_(0), U_(), WAR_(), IWAR_()
{
  problem(nrvar, nreq, nrineq);
}

void QLD::fdOut(int fd)
{
  fdOut_ = fd;
}

int QLD::fdOut() const
{
  return fdOut_;
}

void QLD::verbose(bool v)
{
  verbose_ = v ? 1 : 0;
}

bool QLD::verbose() const
{
  return verbose_;
}

int QLD::fail() const
{
  return fail_;
}

void QLD::problem(int nrvar, int nreq, int nrineq)
{
  int nrconstr = nreq + nrineq;

  int MMAX = nrconstr == 0 ? 1 : nrconstr;
  // nrvar can't be == 0 so NMAX == nrvar
  int NMAX = nrvar;

  A_.resize(MMAX, NMAX);
  B_.resize(MMAX);

  X_.resize(nrvar);

  U_.resize(nrconstr + 2 * nrvar);
  int LWAR = static_cast<int>(std::ceil((3. * NMAX * NMAX) / 2. + 10. * NMAX + MMAX + nrconstr + 1.));
  WAR_.resize(LWAR);
  IWAR_.resize(nrvar);
}

const VectorXd & QLD::result() const
{
  return X_;
}

const VectorXd & QLD::multipliers() const
{
  return U_;
}

} // namespace Eigen
