/**
 * @file mvue.h
 * @brief Minimum Variance Unbiased Estimator (MVUE) module.
 *
 * @details
 * This header provides the complete MVUE estimator interface by including
 * implementations for different numbers of measurements.
 *
 * @defgroup MVUE Minimum Variance Unbiased Estimators
 * @{
 *
 * The available implementations are:
 * - @ref mvue_2 - MVUE using two measurements.
 * - @ref mvue_3 - MVUE using three measurements.
 * - @ref mvue_4 - MVUE using four measurements.
 * - @ref mvue_N - MVUE using an arbitrary number of measurements.
 *
 * @{
 */

/**
 * Copyright (c) 2026 Abhinay Kumar
 */

#ifndef ESTIMATORS_MVUE_H_BLUE_H
#define ESTIMATORS_MVUE_H_BLUE_H

#include "mvue_2.h"
#include "mvue_3.h"
#include "mvue_4.h"
#include "mvue_N.h"

#endif // ESTIMATORS_MVUE_H_BLUE_H

/** @} */
/** @} */