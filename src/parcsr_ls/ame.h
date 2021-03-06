/*BHEADER**********************************************************************
 * Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * This file is part of HYPRE.  See file COPYRIGHT for details.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * $Revision$
 ***********************************************************************EHEADER*/

#ifndef hypre_AME_HEADER
#define hypre_AME_HEADER

/*--------------------------------------------------------------------------
 * Auxiliary space Maxwell Eigensolver
 *--------------------------------------------------------------------------*/
typedef struct
{
   /* The AMS preconditioner */
   hypre_AMSData *precond;

   /* The edge element mass matrix */
   hypre_ParCSRMatrix *M;

   /* Discrete gradient matrix with eliminated boundary */
   hypre_ParCSRMatrix *G;
   /* The Laplacian matrix G^t M G */
   hypre_ParCSRMatrix *A_G;
   /* AMG preconditioner for A_G */
   HYPRE_Solver B1_G;
   /* PCG-AMG solver for A_G */
   HYPRE_Solver B2_G;

   /* Eigensystem for A x = lambda M x, G^t x = 0 */
   HYPRE_Int block_size;
   void *eigenvectors;
   HYPRE_Real *eigenvalues;

   /* Eigensolver (LOBPCG) options */
   HYPRE_Int maxit;
   HYPRE_Real atol;
   HYPRE_Real rtol;
   HYPRE_Int print_level;

   /* Matrix-vector interface interpreter */
   void *interpreter;

   /* Temporary vectors */
   hypre_ParVector *t1, *t2, *t3;

} hypre_AMEData;

#include "_hypre_lapack.h"

#endif
