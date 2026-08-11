/**
 * @file mvue_2.h
 * @brief Two-measurement Minimum Variance Unbiased Estimator.
 *
 * @details
 * This file defines the @ref estimators::mvue::MVUE_2 class, which
 * implements a Minimum Variance Unbiased Estimator (MVUE) for combining
 * two independent measurements.
 *
 * The estimator combines the two input measurements according to their
 * associated variances. Measurements with lower variance are assigned
 * greater weight in the resulting estimate.
 *
 * The class is templated to support different numeric types such as
 * @c float and @c double.
 *
 * @tparam T Numeric data type used for the estimator calculations.
 *
 * @author Abhinay Kumar
 * @version 1.0
 * @date 2026-08-11
 *
 * @copyright
 * Copyright (c) 2026 Abhinay Kumar
 */

#ifndef ESTIMATORS_MVUE_2_H_BLUE_2_H
#define ESTIMATORS_MVUE_2_H_BLUE_2_H

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
         * @class MVUE_2
         * @brief Minimum Variance Unbiased Estimator for two measurements.
         *
         * @details
         * The MVUE_2 class combines two measurements into a single estimate
         * while minimizing the variance of the resulting estimate under the
         * assumptions of the estimator.
         *
         * Each measurement is associated with a variance. The measurement
         * with lower variance receives a greater contribution to the final
         * estimate.
         *
         * @tparam T Numeric data type used for the estimator.
         *
         * @par Example
         * @code{.cpp}
         * estimators::mvue::MVUE_2<double> estimator;
         *
         * estimator.init(var1, var2);
         *
         * double estimate = estimator.update(x1, x2);
         * @endcode
         */
        template <typename T>
        class MVUE_2
        {
        public:
            /**
             * @brief Constructs a two-measurement MVUE.
             *
             * @details
             * The estimator parameters are initialized to zero.
             * Use @ref init() or @ref set_param() to configure the
             * measurement variances before calling @ref update().
             */
            MVUE_2();

            /**
             * @brief Destroys the MVUE estimator.
             */
            ~MVUE_2();

            /**
             * @brief Initializes the estimator.
             *
             * @param[in] var_1_ Variance of the first measurement.
             * @param[in] var_2_ Variance of the second measurement.
             *
             * @details
             * Initializes the estimator using the variances associated
             * with the two measurements.
             */
            void init(T var_1_, T var_2_);

            /**
             * @brief Sets the estimator parameters.
             *
             * @param[in] var_1_ Variance of the first measurement.
             * @param[in] var_2_ Variance of the second measurement.
             *
             * @details
             * Updates the variances used by the estimator when combining
             * the two measurements.
             */
            void set_param(T var_1_, T var_2_);

            /**
             * @brief Computes the minimum variance unbiased estimate.
             *
             * @param[in] x1_i First measurement.
             * @param[in] x2_i Second measurement.
             *
             * @return Combined minimum variance unbiased estimate.
             *
             * @details
             * Combines the two input measurements using their associated
             * variances and returns the resulting minimum variance
             * unbiased estimate.
             */
            T update(T x1_i, T x2_i);

            /**
             * @brief Resets the estimator.
             *
             * @details
             * Resets the estimator parameters to their initial values.
             */
            void reset();

        private:
            /**
             * @brief Variance of the first measurement.
             */
            T var_1 = 0.0;

            /**
             * @brief Variance of the second measurement.
             */
            T var_2 = 0.0;
        };

#include "MVUE_2.tpp"

    } // namespace mvue

} // namespace estimators

#endif // ESTIMATORS_MVUE_2_H_BLUE_2_H