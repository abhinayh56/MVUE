/**
 * @file mvue_N.h
 * @brief N-measurement Minimum Variance Unbiased Estimator.
 *
 * @details
 * This file defines the @ref estimators::mvue::MVUE_N class, which
 * implements a Minimum Variance Unbiased Estimator (MVUE) for combining
 * an arbitrary number of measurements.
 *
 * Each measurement is associated with a variance. The estimator combines
 * the measurements according to their variances, giving greater weight
 * to measurements with lower variance.
 *
 * Unlike the fixed-size MVUE_2, MVUE_3, and MVUE_4 implementations,
 * MVUE_N supports a compile-time configurable number of measurements.
 *
 * The class is templated to support different numeric types and different
 * numbers of measurements.
 *
 * @tparam T Numeric data type used for the estimator calculations.
 * @tparam N Number of measurements to be combined.
 *
 * @author Abhinay Kumar
 * @version 1.0
 * @date 2026-08-11
 *
 * @copyright
 * Copyright (c) 2026 Abhinay Kumar
 */

#ifndef ESTIMATORS_MVUE_N_H_BLUE_4_H
#define ESTIMATORS_MVUE_N_H_BLUE_4_H

#include <cstddef>

namespace estimators
{
    /**
     * @namespace estimators
     * @brief Contains estimation and sensor-fusion algorithms.
     */

    namespace mvue
    {
        /**
         * @namespace mvue
         * @brief Contains Minimum Variance Unbiased Estimator implementations.
         */

        /**
         * @class MVUE_N
         * @brief Minimum Variance Unbiased Estimator for N measurements.
         *
         * @details
         * The MVUE_N class combines @p N measurements into a single
         * estimate while minimizing the variance of the resulting estimate
         * under the assumptions of the estimator.
         *
         * Each measurement has an associated variance. Measurements with
         * lower variance receive greater weighting in the resulting estimate.
         *
         * The number of measurements is specified at compile time through
         * the @p N template parameter.
         *
         * @tparam T Numeric data type used for the estimator.
         * @tparam N Number of measurements.
         *
         * @par Example
         * @code{.cpp}
         * constexpr std::size_t N = 5;
         *
         * estimators::mvue::MVUE_N<double, N> estimator;
         *
         * double variances[N] = {
         *     var1, var2, var3, var4, var5
         * };
         *
         * estimator.init(variances);
         *
         * double measurements[N] = {
         *     x1, x2, x3, x4, x5
         * };
         *
         * double estimate = estimator.update(measurements);
         * @endcode
         */
        template <typename T, std::size_t N>
        class MVUE_N
        {
        public:
            /**
             * @brief Constructs an N-measurement MVUE.
             *
             * @details
             * Constructs the estimator for @p N measurements.
             * The estimator parameters should be initialized using
             * @ref init() or @ref set_param() before calling @ref update().
             */
            MVUE_N();

            /**
             * @brief Destroys the N-measurement MVUE.
             */
            ~MVUE_N();

            /**
             * @brief Initializes the estimator.
             *
             * @param[in] var_ Array containing the variance of each
             * measurement.
             *
             * @details
             * The array must contain @p N variance values, where
             * @p var_[i] represents the variance associated with the
             * measurement @p x_i[i].
             *
             * @warning
             * The caller must ensure that @p var_ points to valid storage
             * containing at least @p N elements.
             */
            void init(T *var_);

            /**
             * @brief Sets the estimator parameters.
             *
             * @param[in] var_ Array containing the variance of each
             * measurement.
             *
             * @details
             * Updates the variances used by the estimator.
             *
             * The array must contain @p N variance values.
             *
             * @warning
             * The caller must ensure that @p var_ points to valid storage
             * containing at least @p N elements.
             */
            void set_param(T *var_);

            /**
             * @brief Computes the minimum variance unbiased estimate.
             *
             * @param[in] x_i Array containing the measurements to be combined.
             *
             * @return Combined minimum variance unbiased estimate.
             *
             * @details
             * Combines the @p N input measurements using their associated
             * variances and returns the resulting minimum variance
             * unbiased estimate.
             *
             * The input array must contain at least @p N measurements.
             *
             * @warning
             * The caller must ensure that @p x_i points to valid storage
             * containing at least @p N elements.
             */
            T update(const T *x_i);

            /**
             * @brief Resets the estimator.
             *
             * @details
             * Resets the estimator parameters to their initial state.
             */
            void reset();

        private:
            /**
             * @brief Array containing the measurement variances.
             *
             * @details
             * Stores the variance associated with each of the @p N
             * measurements.
             */
            T *var;
        };

#include "../src/MVUE_N.tpp"

    } // namespace mvue

} // namespace estimators

#endif // ESTIMATORS_MVUE_N_H_BLUE_4_H