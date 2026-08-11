/**
 * @file mvue_4.h
 * @brief Four-measurement Minimum Variance Unbiased Estimator.
 *
 * @details
 * This file defines the @ref estimators::mvue::MVUE_4 class, which
 * implements a Minimum Variance Unbiased Estimator (MVUE) for combining
 * four measurements.
 *
 * Each measurement is associated with a variance. The estimator combines
 * the measurements according to their variances, giving greater weight
 * to measurements with lower variance.
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

#ifndef ESTIMATORS_MVUE_4_H_BLUE_4_H
#define ESTIMATORS_MVUE_4_H_BLUE_4_H

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
         * @class MVUE_4
         * @brief Minimum Variance Unbiased Estimator for four measurements.
         *
         * @details
         * The MVUE_4 class combines four measurements into a single
         * estimate while minimizing the variance of the resulting estimate
         * under the assumptions of the estimator.
         *
         * Each measurement is associated with a variance. Measurements
         * with lower variance receive greater weighting in the resulting
         * estimate.
         *
         * @tparam T Numeric data type used for the estimator.
         *
         * @par Example
         * @code{.cpp}
         * estimators::mvue::MVUE_4<double> estimator;
         *
         * estimator.init(var1, var2, var3, var4);
         *
         * double estimate = estimator.update(x1, x2, x3, x4);
         * @endcode
         */
        template <typename T>
        class MVUE_4
        {
        public:
            /**
             * @brief Constructs a four-measurement MVUE.
             *
             * @details
             * The estimator parameters are initialized to zero.
             * Use @ref init() or @ref set_param() to configure the
             * measurement variances before calling @ref update().
             */
            MVUE_4();

            /**
             * @brief Destroys the MVUE estimator.
             */
            ~MVUE_4();

            /**
             * @brief Initializes the estimator.
             *
             * @param[in] var_1_ Variance of the first measurement.
             * @param[in] var_2_ Variance of the second measurement.
             * @param[in] var_3_ Variance of the third measurement.
             * @param[in] var_4_ Variance of the fourth measurement.
             *
             * @details
             * Initializes the estimator using the variances associated
             * with the four measurements.
             */
            void init(T var_1_, T var_2_, T var_3_, T var_4_);

            /**
             * @brief Sets the estimator parameters.
             *
             * @param[in] var_1_ Variance of the first measurement.
             * @param[in] var_2_ Variance of the second measurement.
             * @param[in] var_3_ Variance of the third measurement.
             * @param[in] var_4_ Variance of the fourth measurement.
             *
             * @details
             * Updates the variances used by the estimator when combining
             * the four measurements.
             */
            void set_param(T var_1_, T var_2_, T var_3_, T var_4_);

            /**
             * @brief Computes the minimum variance unbiased estimate.
             *
             * @param[in] x1_i First measurement.
             * @param[in] x2_i Second measurement.
             * @param[in] x3_i Third measurement.
             * @param[in] x4_i Fourth measurement.
             *
             * @return Combined minimum variance unbiased estimate.
             *
             * @details
             * Combines the four input measurements using their associated
             * variances and returns the resulting minimum variance
             * unbiased estimate.
             */
            T update(T x1_i, T x2_i, T x3_i, T x4_i);

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

            /**
             * @brief Variance of the third measurement.
             */
            T var_3 = 0.0;

            /**
             * @brief Variance of the fourth measurement.
             */
            T var_4 = 0.0;
        };

#include "../src/MVUE_4.tpp"

    } // namespace mvue

} // namespace estimators

#endif // ESTIMATORS_MVUE_4_H_BLUE_4_H