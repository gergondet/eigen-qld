#
# Copyright 2012-2019 CNRS-UM LIRMM, CNRS-AIST JRL
#

ADD_CYTHON_BINDINGS(eigen_qld
  TARGETS eigen-qld
  EXPORT_SOURCES eigen_qld/c_eigen_qld.pxd eigen_qld/eigen_qld.pxd eigen_qld/__init__.py
  PRIVATE_SOURCES eigen_qld/eigen_qld.pyx eigen_qld/private_typedefs.h tests/test_qp.py
)
